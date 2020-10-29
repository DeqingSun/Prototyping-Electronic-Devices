int pinPressedCount = 0;
bool prevPinLevel = HIGH;

void setup() {
  pinMode(2, INPUT_PULLUP);
  Serial.begin(9600);
}

void loop() {
  //pretend some long job
  delay(1000);

  bool currentPinLevel = digitalRead(2);
  if (currentPinLevel == LOW && prevPinLevel == HIGH) {
    pinPressedCount++;
  }
  prevPinLevel = currentPinLevel;

  Serial.print("Button pressed ");
  Serial.print(pinPressedCount);
  Serial.println(" times.");
}
