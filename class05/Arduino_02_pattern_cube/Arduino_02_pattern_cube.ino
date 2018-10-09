void setup() {
  digitalWrite(11, LOW);  //we change pinMode on cathod to control current
  digitalWrite(12, LOW);

  pinMode(2, OUTPUT); //we use High and Low for common cathod
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  digitalWrite(2, HIGH);
  digitalWrite(3, HIGH);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  pinMode(11, OUTPUT);
  delay(8);
  pinMode(11, INPUT);

  digitalWrite(2, LOW);
  digitalWrite(3, LOW);
  digitalWrite(4, HIGH);
  digitalWrite(5, LOW);
  pinMode(12, OUTPUT);
  delay(8);
  pinMode(12, INPUT);
}
