#include <avr/sleep.h>
#include <avr/wdt.h>
const int ledPin =  13;

ISR(WDT_vect)
{
}

void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(ledPin, LOW);
  delay(120);
}
