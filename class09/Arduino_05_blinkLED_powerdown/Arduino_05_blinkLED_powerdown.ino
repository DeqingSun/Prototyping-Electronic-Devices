#include <avr/sleep.h>
#include <avr/wdt.h>
const int ledPin =  13;

ISR(WDT_vect)
{
}

void setup() {
  pinMode(ledPin, OUTPUT);
  set_sleep_mode(SLEEP_MODE_PWR_DOWN);
}

void loop() {
  digitalWrite(ledPin, HIGH);
  delayMicroseconds(500);
  digitalWrite(ledPin, LOW);
  wdt_reset();
  wdt_enable(WDTO_120MS);
  WDTCSR |=  1 << WDIE;
  sleep_mode();
  wdt_disable();
}
