void heure() {
  tft.setTextColor(0x07e0, 0x0000);
  tft.setTextSize(2);
  tft.setCursor(5, 5);
  tft.print(daysOfTheWeek[timeClient.getDay()]);
  tft.print (timeClient.getDate());
  tft.print(monthOfTheYear[timeClient.getMonth()-1]);
  tft.print (timeClient.getYear()-2000);
  tft.setCursor(110, 35);
  tft.setTextSize(4);
  tft.print(timeClient.getHours());
  tft.print(":");
  if (timeClient.getMinutes() < 10) {tft.print("0");}
  tft.print(timeClient.getMinutes());
}
