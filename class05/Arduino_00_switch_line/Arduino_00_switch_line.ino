void setup() {
  digitalWrite(11, LOW);  //we change pinMode on cathod to control current
  digitalWrite(12, LOW);

  pinMode(2, OUTPUT); //we use High and Low for common cathod
  pinMode(3, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  pinMode(11, OUTPUT);
  pinMode(12, INPUT);
  delay(1000);

  digitalWrite(2, HIGH);
  digitalWrite(3, LOW);
  pinMode(11, INPUT);
  pinMode(12, OUTPUT);
  delay(1000);
}
