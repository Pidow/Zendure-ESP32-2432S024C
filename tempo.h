#include "erreur.h"

void tempocolor () {
  if (WiFi.status() == WL_CONNECTED) {

    WiFiClient client;
    HTTPClient http;
    http.begin(tempotoday);
    http.setTimeout(10000);
    http.addHeader("Accept", "application/json");
    int httpCode = http.GET();
    if (httpCode == 200 ) {
      String reponse = http.getString();
      deserializeJson(doc, reponse);
      tempotodayA = doc["codeJour"];
      http.begin(tempotomo);
      httpCode = http.GET();
      reponse = http.getString();
      deserializeJson(doc, reponse);
      tempotomoA = doc["codeJour"];

    } else {
          erreurtitle ="Erreur TEMPO : ";
          erreurmessage = httpCode;
          erreur();
      http.end();
    }
  } else  {
          erreurtitle ="Erreur shelly : ";
          erreurmessage = "WIFI DOWN ";
          erreur();
  }
  if (tempotodayA == 0) {    couleurAJD = 0x0000;  }
  if (tempotodayA == 1) {    couleurAJD = 0x043f;  }
  if (tempotodayA == 2) {    couleurAJD = 0xffff;  }
  if (tempotodayA == 3) {    couleurAJD = 0xf800;  }
  if (tempotomoA == 0) {    couleurDMN = 0x0000;  }
  if (tempotomoA == 1) {    couleurDMN = 0x043f;  }
  if (tempotomoA == 2) {    couleurDMN = 0xffff;  }
  if (tempotomoA == 3) {    couleurDMN = 0xf800;  }
  

  }

