void calc() {
  if ((power > 0) && (power < 1000)) {
    POWER = ("w ");
    MESURE = 0;
  }
  if (power > 999) {
    power /= 1000;
    POWER = ("K");
    MESURE = 0;
  }
  if ((power < 0) && (power > -1000)) {
    power *= -1;
    POWER = ("w ");
    MESURE = 1;
  }
  if (power < -999) {
    power /= -1000;
    POWER = ("K");

    MESURE = 1;
  }
  if (etatBat == 2) {  MESURE = 2;  }

}
