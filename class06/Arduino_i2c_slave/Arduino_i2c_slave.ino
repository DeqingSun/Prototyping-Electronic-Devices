//This is for yout master Arduino

#include <Wire.h>

void setup() {
  Wire.begin(8);                // join i2c bus with address, change address here
  Wire.onReceive(receiveEvent); // register event
  Wire.onRequest(requestEvent); // register event
  Serial.begin(9600);           // start serial for output
  pinMode(LED_BUILTIN, OUTPUT);
}

void loop() {
  delay(100);
}

// function that executes whenever data is received from master
// this function is registered as an event, see setup()
void receiveEvent(int howMany) {
  Serial.print("Got ");
  Serial.print(howMany);
  Serial.println(" bytes from master");

  for (int i = 0 ; i < howMany ; i++) {
    int i2cValue = Wire.read();    // receive byte as an integer
    Serial.print(i2cValue);         // print the integer
    Serial.print(' ');
    if (i == 0) { //first byte
      if (i2cValue) {
        digitalWrite(LED_BUILTIN, HIGH);
      } else {
        digitalWrite(LED_BUILTIN, LOW);
      }
    }
  }
  Serial.println();
}

void requestEvent() {
  unsigned char analog8Bit = analogRead(0) / 4;
  Wire.write(analog8Bit); // respond with message of 1 bytes
  // as expected by master
}
