void setup() {
  pinMode(13, OUTPUT);
}

void loop() {
  while (1) {
    PORTB ^= (1 << 5);
  }
}
