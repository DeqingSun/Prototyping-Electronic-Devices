#include <Wire.h>

//This is a quick example to show raw data from ADXL345
//if you want to read accurate value, use Adafruit's library

#define DEVICE (0x53) // Device address as specified in data sheet 

byte _buff[6];

#define THRESH_TAP  0x1D  //Tap Threshold
#define  DURATION  0x21  //Tap Duration
#define  LATENT    0x22  //Tap latency
#define WINDOW    0x23  //Tap window
#define POWER_CTL  0x2D  //Power Control Register
#define DATA_FORMAT  0x31
#define DATAX0  0x32 //X-Axis Data 0
#define DATAX1  0x33 //X-Axis Data 1
#define DATAY0  0x34 //Y-Axis Data 0
#define DATAY1  0x35 //Y-Axis Data 1
#define DATAZ0  0x36 //Z-Axis Data 0
#define DATAZ1  0x37 //Z-Axis Data 1
#define  TAP_AXES  0x2A  //Axis control for tap/double tap
#define  INT_ENABLE  0x2E  //Interrupt Enable Control
#define  INT_SOURCE  0x30  //Source of interrupts

void setup()
{
  Wire.begin();        // join i2c bus (address optional for master)
  Serial.begin(9600);  // start serial for output. Make sure you set your Serial Monitor to the same!
  Serial.println("init");

  //Put the ADXL345 into +/- 8G range by writing the value 0x01 to the DATA_FORMAT register.
  writeTo(DATA_FORMAT, 0x02);

  //Look for taps on the Z axis only.
  writeTo(TAP_AXES, 0x01);
  //Set the Tap Threshold to 1g
  writeTo(THRESH_TAP, 0x10);
  //Set the Tap Duration that must be reached 5ms
  writeTo(DURATION, 0x8);

  //100ms Latency before the second tap can occur.
  writeTo(LATENT, 0x50);
  writeTo(WINDOW, 0xFF);

  //Enable the Single and Double Taps.
  writeTo(INT_ENABLE, 0xE0);

  //Put the ADXL345 into Measurement Mode by writing 0x08 to the POWER_CTL register.
  writeTo(POWER_CTL, 0x08);


}

void loop()
{
  readAccel(); // read the x/y/z tilt
  delay(200); // only read every 0.2 seconds
}

void readAccel() {
  uint8_t howManyBytesToRead = 6;
  readFrom( DATAX0, howManyBytesToRead, _buff); //read the acceleration data from the ADXL345

  // each axis reading comes in 10 bit resolution, ie 2 bytes.  Least Significat Byte first!!
  // thus we are converting both bytes in to one int
  int x = (((int)_buff[1]) << 8) | _buff[0];
  int y = (((int)_buff[3]) << 8) | _buff[2];
  int z = (((int)_buff[5]) << 8) | _buff[4];
  Serial.print("x: ");
  Serial.print( x );
  Serial.print(" y: ");
  Serial.print( y );
  Serial.print(" z: ");
  Serial.print( z );

  readFrom( INT_SOURCE, 1, _buff);
  Serial.print(" Tap: ");
  if (_buff[0] & (1 << 6)) Serial.print(" single");
  if (_buff[0] & (1 << 5)) Serial.print(" double");
  Serial.print('\n');
}

void writeTo(byte address, byte val) {
  Wire.beginTransmission(DEVICE); // start transmission to device
  Wire.write(address);             // send register address
  Wire.write(val);                 // send value to write
  Wire.endTransmission();         // end transmission
}

// Reads num bytes starting from address register on device in to _buff array
void readFrom(byte address, int num, byte _buff[]) {
  Wire.beginTransmission(DEVICE); // start transmission to device
  Wire.write(address);             // sends address to read from
  Wire.endTransmission();         // end transmission

  Wire.beginTransmission(DEVICE); // start transmission to device
  Wire.requestFrom(DEVICE, num);    // request 6 bytes from device

  int i = 0;
  while (Wire.available())        // device may send less than requested (abnormal)
  {
    _buff[i] = Wire.read();    // receive a byte
    i++;
  }
  Wire.endTransmission();         // end transmission
}
