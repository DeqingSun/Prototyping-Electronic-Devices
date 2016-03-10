#include <Wire.h>

void setup(void)
{
  Serial.begin(9600);
  while (!Serial) ; // wait for serial port to connect. Needed for Leonardo and Micro
  Wire.begin();

  delay(1000);  //make sure Serial monitor have time to set up

  unsigned int address = 0;
  Serial.println("Write to EEPROM");
  writeEEPROM(0x50, address, 123);
  Serial.println("Read from EEPROM");
  Serial.print(readEEPROM(0x50, address), DEC);
}

void loop() {}

void writeEEPROM(unsigned char deviceaddress, unsigned int eeaddress, byte data )
{
  Wire.beginTransmission(deviceaddress);
  Wire.write(eeaddress >> 8);   // MSB, Right shift 8 bits to get bit 8 to bit 15
  Wire.write(eeaddress & 0xFF); // LSB, use AND logic to turn bit 8 to bit 15 to 0
  Wire.write(data);
  Wire.endTransmission();

  delay(10);  //wait 10 ms to make sure 
}

byte readEEPROM(unsigned char deviceaddress, unsigned int eeaddress )
{
  byte rdata = 0xFF;

  Wire.beginTransmission(deviceaddress);
  Wire.write(eeaddress >> 8);   // MSB
  Wire.write(eeaddress & 0xFF); // LSB
  Wire.endTransmission();

  Wire.requestFrom(deviceaddress, 1);

  if (Wire.available()) rdata = Wire.read();

  return rdata;
}
