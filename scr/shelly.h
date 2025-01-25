#include "erreur.h"

void shelly() {
  if (WiFi.status() == WL_CONNECTED) {
    WiFiClient client;
    HTTPClient http;
    http.useHTTP10(true);
    http.begin(client, request);
    int httpCode = http.GET();
    if (httpCode == 200 ) {
      String reponse = http.getString();
      deserializeJson(doc, reponse);
      power = doc["em:0"]["c_act_power"];
    } else {
          erreurtitle ="Erreur shelly : ";
          erreurmessage = httpCode;
          erreur();
      http.end();
    }
  } else  {
          erreurtitle ="Erreur shelly : ";
          erreurmessage = "WIFI DOWN ";
          erreur();
  }
}
