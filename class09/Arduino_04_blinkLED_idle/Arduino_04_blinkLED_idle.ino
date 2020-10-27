#include <avr/sleep.h>
#include <avr/wdt.h>
const int ledPin =  13;

ISR(WDT_vect)
{
}

void setup() {
  pinMode(ledPin, OUTPUT);
  set_sleep_mode(SLEEP_MODE_IDLE);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(ledPin, LOW);
  unsigned long startMillis = millis();
  while ( millis() - startMillis < 120 ) {
    sleep_mode();
  }
}
