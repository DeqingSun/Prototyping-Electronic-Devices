volatile unsigned char pinPressedCount = 0;

void pin2LevelFalling() {
  pinPressedCount++;
}

void setup() {
  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), pin2LevelFalling, FALLING);
  Serial.begin(9600);
}

void loop() {
  //pretend some long job
  delay(1000);

  Serial.print("Button pressed ");
  Serial.print(pinPressedCount);
  Serial.println(" times.");
}
