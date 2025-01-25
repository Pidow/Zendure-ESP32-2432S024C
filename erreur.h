#pragma once
void erreur() {
    tft.fillScreen(TFT_BLACK);
      tft.setCursor(0, 0);
      tft.setTextSize(2);
      tft.print(erreurtitle);
      tft.print(erreurmessage);
      delay(50000);
     }
