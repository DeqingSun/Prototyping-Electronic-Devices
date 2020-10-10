//This is for yout master Arduino

#include <Wire.h>

void setup() {
  Serial.begin(9600);  // start serial for output
  Wire.begin(); // join i2c bus (address optional for master)
}

byte x = 0;

void loop() {
  exchangeDataI2C(8, 0);
  delay(1000);
  exchangeDataI2C(8, 1);
  delay(1000);
}

void exchangeDataI2C(unsigned char addr, unsigned char sendValue) {
  Serial.print("Sending to I2C device ");
  Serial.print(addr);
  Serial.print(" with value ");
  Serial.println(sendValue);

  Wire.beginTransmission(addr); // transmit to device
  Wire.write(sendValue);     // sends one byte
  Wire.endTransmission();    // stop transmitting

  Serial.print("Receiving from I2C device ");
  Serial.println(addr);
  Wire.requestFrom(addr, 1);    // request 1 bytes from slave device
  while (Wire.available()) { // slave may send less than requested
    int i2cValue = Wire.read();    // receive byte as an integer
    Serial.print(i2cValue);         // print the integer
    Serial.print(' ');
  }
  Serial.println();
}

