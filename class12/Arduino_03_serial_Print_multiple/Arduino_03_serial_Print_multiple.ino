unsigned char accu0 = 0;
unsigned char accu1 = 0;
unsigned char accu2 = 0;


void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.print(accu0);
  Serial.print(',');
  Serial.print(accu1);
  Serial.print(',');
  Serial.print(accu2);
  Serial.print('\n');
  accu0=accu0+16; //it will oveflow back to 0
  accu1=accu1+8; //it will oveflow back to 0
  accu2=accu2+4; //it will oveflow back to 0
  delay(50);
}
