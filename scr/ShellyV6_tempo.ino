#include <ArduinoJson.h>
#include <WiFi.h>
#include <SPI.h>
#include <TFT_eSPI.h>
#include <HTTPClient.h>
#include <WiFiUdp.h> // NTP Service
#include <NTPClient.h>  // NTP Service
#include <PubSubClient.h>  // MQTT
#include <bb_captouch.h>
#include <iui.h>

// Paramètres Wi-Fi et Shelly
const char* ssid = "XXX";
const char* password = "xxx";

const String request = "http://192.168.xxxx/rpc/Shelly.GetStatus" ; // adresse local shelly
const String tempotoday = "https://www.api-couleur-tempo.fr/api/jourTempo/today" ;
const String tempotomo = "https://www.api-couleur-tempo.fr/api/jourTempo/tomorrow" ;
int tempotodayA = 0;
int tempotomoA = 0;

WiFiUDP ntpUDP;

NTPClient timeClient(ntpUDP, "fr.pool.ntp.org", 3600, 60000);
char daysOfTheWeek[7][12] = {"Dimanche ", "Lundi ", "Mardi ", "Mercredi ", "Jeudi ", "Vendredi ", "Samedi "};
char monthOfTheYear[12][10] = {" jan. ", " fev. ", " mar. ", " avr. ", " mai. ", " juin. ", " juil. ", " aou. ", " sept. ", " oct. ", " nov. ", " dec. "};

float power = 0;
String POWER = "w";
int MESURE = 0;
int PMESURE = 2;
int ecran = 1;
int currentHour;
uint16_t couleurAJD = 0x0000; //
uint16_t couleurDMN = 0x0000; //


JsonDocument doc;
int led_pin[3] = {17, 4, 16};

TFT_eSPI tft = TFT_eSPI();

const String url = "https://app.zendure.tech/eu";
const String ZendureDeveloperUrl = "http://app.zendure.tech/eu/developer/api/apply";
const String serialNumber = "xxxxxx"; //Serial number Zendure Hyper
const String appUsername = "x@x.fr"; // adresse mail compte Zendure
String httpRequestData = " ";

const char *mqtt_broker = "mqtt-eu.zen-iot.com"; // adresse du broker Zendure
const char *topic = "xx/xx/state/#"; // nom du topic
const char *mqtt_username = "xxx"; // username MQTT
const char *mqtt_password = "xxx"; //password MQTT
const int mqtt_port = 1883;
int batterie = 0;
int etatBat =0; 
int valueBat=0;
float dechargetemp=0;
int dechargetempH=0;
int dechargetempM=0;
int Updatbat = 1;
int tempBat =0;
unsigned long tempo = 0;
unsigned long tempos = 0;

String erreurtitle =" ";
String erreurmessage = "  ";

WiFiClient espClient;
PubSubClient client(espClient);

#define TOUCH_SDA 33
#define TOUCH_SCL 32
#define TOUCH_INT 21
#define TOUCH_RST 25
#define TADR 0x15
BBCapTouch bbct;
const char *szNames[] = {"Unknown", "FT6x36", "GT911", "CST820"};
#include <erreur.h>
#include <calc.h>
#include <heure.h>
#include <screen.h>
#include <shelly.h>
#include <tempo.h>
#include <zendure.h>


void setup() {
  uint8_t wbf[16];
  bbct.init(TOUCH_SDA, TOUCH_SCL, TOUCH_RST, TOUCH_INT);
  int iType = bbct.sensorType();

  pinMode(led_pin[0], OUTPUT);
  pinMode(led_pin[1], OUTPUT);
  pinMode(led_pin[2], OUTPUT);

  WiFi.begin(ssid, password);
  tft.init();
  tft.setRotation(0);
  tft.setSwapBytes(true);
  tft.setTextSize(2);
  tft.fillScreen(TFT_BLACK);
  tft.setTextColor(0xFFFF);
  tft.setCursor(25, 60);
  tft.print("WIFI CONNECTION");
  tft.println(" ");
  while (WiFi.status() != WL_CONNECTED) {
    delay(200);
    tft.print("*");
  }
  tft.fillScreen(TFT_BLACK);
  tft.setCursor(80, 60);
  tft.print("WIFI OK");
  delay(1500);
  timeClient.begin();

  //Activer pour avoir les codes mqtt
  //zendure();

  mqtt();
  tempocolor();
  tft.pushImage(0, 0, 240, 320, iui);
  digitalWrite(led_pin[0], HIGH);
  digitalWrite(led_pin[1], HIGH);
  digitalWrite(led_pin[2], HIGH);
}

void loop() {
  TOUCHINFO ti;
  timeClient.update();
  currentHour = timeClient.getHours();
  if (tempo == 0) {
    tempo = millis();
  }
  if (tempos == 0) {
    tempos = millis();
  }
  shelly();
  calc();
  client.loop();
  if (ecran == 1) {
    if ((millis() - tempo ) > 3000)  {
      affichage();
      heure ();
      tempo = 0;
    }
    if ((millis() - tempos ) > 120000)  {
      tempos = 0;
      tempocolor ();
      screenoff ();

    }
  }

  if ((ecran == 0) && (bbct.getSamples(&ti))) {
    tempos = 0;
    screenon ();
  }

  if (ecran == 0) {
    if ((millis() - tempo ) > 1000)  {
      digitalWrite(led_pin[0], HIGH);
      digitalWrite(led_pin[1], HIGH);
      digitalWrite(led_pin[2], HIGH);
    }
    if ((millis() - tempo ) > 3000)  {
      if  (MESURE == 0) {
        digitalWrite(led_pin[0], HIGH);
        digitalWrite(led_pin[1], LOW);
        digitalWrite(led_pin[2], HIGH);
        tempo = 0;
      }
      if  (MESURE == 1) {
        digitalWrite(led_pin[0], HIGH);
        digitalWrite(led_pin[1], HIGH);
        digitalWrite(led_pin[2], LOW);
        tempo = 0;
      }
       if  (MESURE == 2) {
       digitalWrite(led_pin[0], LOW);
       digitalWrite(led_pin[1], HIGH);
       digitalWrite(led_pin[2], LOW);
        tempo = 0;
      }

    }
  }
}

void affichage() {
  tft.setTextColor(0x0000, 0xe75c);
  tft.setCursor(27, 287);
  tft.setTextSize(3);
  tft.print(String("") + batterie + "%");

  
  tft.setTextColor(couleurAJD, 0x0000);
  tft.setCursor(50, 80);
  tft.setTextSize(3);
  tft.print(String("AJD"));

  tft.setTextColor(0xFFFF, 0x0000);
  tft.setCursor(109, 80);
  tft.setTextSize(3);
  tft.print("/");
  
  tft.setTextColor(couleurDMN, 0x0000);
  tft.setCursor(132, 80);
  tft.setTextSize(3);
  tft.print(String("DEM"));

    tft.setTextColor(0x0000, 0xFFFF);
    tft.setTextSize(3);
  if (MESURE == 0) {
        tft.setCursor(20, 220);
        tft.print(" ---");
        tft.setCursor(135, 220);
  } else {
        tft.setCursor(135, 220);
        tft.print(" ---");
        tft.setCursor(20, 220);
  }
  

  if (POWER == "w ")
  {
    tft.print((power), 0);
  } else {
    tft.print((power), 1);
  }
  tft.print(POWER);

  tft.setTextColor(0x0000, 0xFFFF);
  tft.setTextSize(2);
  tft.setCursor(100, 270);
  if (etatBat==0) { tft.print(".VEILLE.  ");  }
  if (etatBat==1) { tft.print(".CHARGE.  ");  }
  if (etatBat==2) { tft.print(".DECHARGE.");  }
  
  tft.setCursor(100, 300);
  if (etatBat==1) { tft.print(valueBat); tft.print("w"); }
  if (etatBat==0) { tft.print("       ");  }
  if (etatBat==2) { tft.print(dechargetempH); tft.print("H"); tft.print(dechargetempM); tft.print("m.");}
  
  
  tft.setCursor(170, 300);
  if (tempBat==1) {  tft.print(tempBat); tft.print("C");}
  if (tempBat==0) { tft.print("   ");  } 


}
void mqtt() {
  client.setServer(mqtt_broker, mqtt_port);
  client.setCallback(callback);
  while (!client.connected()) {
    String client_id = "esp32-client-";
    client_id += String(WiFi.macAddress());
    if (client.connect(client_id.c_str(), mqtt_username, mqtt_password)) {
      if (batterie == 0) {
        tft.fillScreen(TFT_BLACK);
        tft.setCursor(50, 60);
        tft.println("ATTENTE MQTT");
      }
      client.subscribe(topic);
      tft.fillScreen(TFT_BLACK);
    } else {
      erreurtitle ="Erreur MQTT: ";
      erreurmessage = client.state();
      erreur();
    }
  }

}

void callback(char* topic, byte* payload, unsigned int length)  {
  char messageBuffer[200];
  memcpy(messageBuffer, payload, length);
  messageBuffer[length] = '\0';
  parseMessage(messageBuffer);
}

void parseMessage(char* json)  {

  StaticJsonDocument<300> doc;
  DeserializationError error = deserializeJson(doc, json);
  if (error)
  {
    erreurtitle ="Erreur JSON: ";
    erreurmessage = error.f_str();
    erreur();
    return;
  }
  batterie = doc["electricLevel"];
  if (batterie == 0) {
    batterie = Updatbat;
  }
  Updatbat = batterie;
  
  int reponseB=0;
    
     etatBat =0 ;
     valueBat=0;
  
  reponseB = doc["gridInputPower"];
   if (reponseB != 0) {
       etatBat =1 ;
       valueBat=reponseB;
   }

     reponseB = doc["remainOutTime"];
     if (reponseB != 0) {
       etatBat =2 ;
       dechargetemp=reponseB*0.016667;

       dechargetempH=dechargetemp;
       dechargetempM=(dechargetemp-dechargetempH)/0.016667;
       if (dechargetempH>998) {dechargetempH=0;  dechargetempH=0;  etatBat=0;  valueBat=0;}
   }
  
   reponseB = doc ["packData"]["maxTemp"];
     if (reponseB != 0) {
       tempBat=reponseB-273;
   }

   
}
