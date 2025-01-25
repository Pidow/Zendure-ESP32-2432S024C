void screenoff() {
  pinMode(27, OUTPUT);
  digitalWrite(27, LOW);
  tft.writecommand(TFT_DISPOFF);
  tft.writecommand(ILI9341_SLPIN);
  ecran = 0;
}
void screenon() {
  digitalWrite(led_pin[0], HIGH);
  digitalWrite(led_pin[1], HIGH);
  digitalWrite(led_pin[2], HIGH);
  pinMode(27, OUTPUT);
  digitalWrite(27, HIGH);
  tft.writecommand(TFT_DISPON);
  tft.writecommand(ILI9341_SLPOUT);
  ecran = 1;
}