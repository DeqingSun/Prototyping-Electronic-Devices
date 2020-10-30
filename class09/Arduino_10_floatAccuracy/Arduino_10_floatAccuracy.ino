void setup() {
  Serial.begin(9600);
}

void loop() {
  long longNumber = 1;
  longNumber = longNumber + 1000000000UL;
  Serial.print("Long type: 1 + 1bil = ");
  Serial.println(longNumber);
  longNumber = longNumber - 1000000000UL;
  Serial.print("Long type: 1 + 1bil - 1bil = ");
  Serial.println(longNumber);

  float floatNumber = 1;
  floatNumber = floatNumber + 1000000000UL;
  Serial.print("Float type: 1 + 1bil = ");
  Serial.println(floatNumber);
  floatNumber = floatNumber - 1000000000UL;
  Serial.print("Float type: 1 + 1bil - 1bil = ");
  Serial.println(floatNumber);
  
  delay(5000);
}
