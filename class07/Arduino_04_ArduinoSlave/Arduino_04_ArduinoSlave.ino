#include <Wire.h>

byte x = 0;

void setup() {
  Serial.begin(9600);           // start serial for output
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  if (Wire.available()) { // loop through all but the last
    x = Wire.read(); // receive byte as a character
    Serial.print("Slave Arduino receiving ");
    Serial.println(x, DEC);
  }

}

void requestEvent() {
  Wire.write((x + 128));
  Serial.print("Slave Arduino sending ");
  Serial.println((x + 128), DEC);
}
