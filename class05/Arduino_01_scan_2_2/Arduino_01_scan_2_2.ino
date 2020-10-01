void setup() {
  digitalWrite(11, LOW);  //Switch which column to control
  digitalWrite(12, LOW);

  pinMode(2, OUTPUT); //we use High and Low for common cathod
  pinMode(3, OUTPUT);
}

void loop() {
  for (int i = 0; i < 2; i++) {
    digitalWrite(2, HIGH);  //config LEDs in Pin11's group
    digitalWrite(3, LOW);
    pinMode(11, OUTPUT);
    delay(500);             //light LEDs in Pin11's group
    pinMode(11, INPUT);

    digitalWrite(2, LOW);   //config LEDs in Pin12's group
    digitalWrite(3, HIGH);
    pinMode(12, OUTPUT);
    delay(500);             //light LEDs in Pin12's group
    pinMode(12, INPUT);
  }
  for (int i = 0; i < 8; i++) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    pinMode(11, OUTPUT);
    delay(125);
    pinMode(11, INPUT);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    pinMode(12, OUTPUT);
    delay(125);
    pinMode(12, INPUT);
  }
  for (int i = 0; i < 32; i++) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    pinMode(11, OUTPUT);
    delay(32);
    pinMode(11, INPUT);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    pinMode(12, OUTPUT);
    delay(32);
    pinMode(12, INPUT);
  }
  for (int i = 0; i < 128; i++) {
    digitalWrite(2, HIGH);
    digitalWrite(3, LOW);
    pinMode(11, OUTPUT);
    delay(8);
    pinMode(11, INPUT);

    digitalWrite(2, LOW);
    digitalWrite(3, HIGH);
    pinMode(12, OUTPUT);
    delay(8);
    pinMode(12, INPUT);
  }
}
