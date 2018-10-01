int LEDpin = 11;

uint8_t ledBirghtnessPower[16] = {1, 1, 2, 4, 8, 13, 21, 32, 45, 62, 83, 108, 137, 171, 210, 255};

void setup() {
}

void loop() {
  for (uint8_t i = 0; i < 16; i++) {
    analogWrite(LEDpin, ledBirghtnessPower[i]);
    delay(125);
  }
}
