#include <Wire.h>

void setup() {
  Serial.begin(9600);
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop() {
  Serial.print("Master Arduino sending ");
  Serial.println(x,DEC);
  Wire.beginTransmission(8); // transmit to device #8
  Wire.write(x);              // sends one byte
  Wire.endTransmission();    // stop transmitting
  x++;

  Wire.requestFrom(8, 1);    // request 1 bytes from slave device #8
  if (Wire.available()) { // slave may send less than requested
    byte c = Wire.read(); // receive a byte 
    Serial.print("Master Arduino receiveing ");
    Serial.println(c,DEC);
  }

  delay(500);
}
