#include <avr/sleep.h>
const int ledPin =  13;

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(ledPin, LOW);
  delay(120);
}
