#include <Wire.h>

unsigned char accu = 0;

void setup() {
  Wire.begin(8);                // join i2c bus with address #8
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output

  Serial.println("\nThis Arduino Sketch will accumulate received value and send it back");
}

void loop() {
  delay(100);
}

// function that executes whenever data is requested by master
// this function is registered as an event, see setup()
void requestEvent() {
  Wire.write(accu); // respond with accumulator value
  Serial.print("Send back: ");
  Serial.println((int)accu);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  while (Wire.available()>0) { // loop through all but the last
    int x = Wire.read(); // receive byte as a character
    Serial.print("Got value: ");
    Serial.println(x);         // print the character
    accu+=x;
  }
}
