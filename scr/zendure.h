void zendure() {
  HTTPClient http;
  http.begin(ZendureDeveloperUrl);
  http.addHeader("Content-Type", "application/json");
  JsonDocument doc;
  doc["snNumber"] = serialNumber;
  doc["account"] = appUsername;
  serializeJson(doc, httpRequestData);
  int httpResponseCode = http.POST(httpRequestData);
  if (httpResponseCode == 200) {
    String reponse = http.getString();
    deserializeJson(doc, reponse);
    String mqtta_login  = doc["data"]["appKey"];
    String mqtta_pass = doc["data"]["secret"];
    String mqtta_url = doc["data"]["mqttUrl"];
    int mqtta_port = doc["data"]["port"];
    String topica = "" + mqtta_login + "/#";
    tft.fillScreen(TFT_BLACK);
    tft.setCursor(0, 0);
    tft.setTextSize(2);
    tft.print("*  ZENDURE API: OK *");
    tft.print("Compte MQTT:");
    tft.println (mqtta_login);
    tft.print("Pass:");
    tft.println (mqtta_pass);
    tft.print("URL:");
    tft.println (mqtta_url);
    tft.print("Port:");
    tft.println (mqtta_port);
    http.end();
    delay (50000);
  } else {
    tft.print("*  ZENDURE API: NOK *");
    http.end();
    delay (50000);
  }
}
