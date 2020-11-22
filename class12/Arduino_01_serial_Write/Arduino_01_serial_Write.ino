unsigned char accu = 0;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.write(accu);
  accu=accu+16; //it will oveflow back to 0
  delay(50);
}
