#include <avr/sleep.h>
const int ledPin =  13;
int ledState = LOW;
unsigned long previousMillis = 0;
const long interval = 1000;           // interval at which to blink (milliseconds)
void setup() {
  pinMode(ledPin, OUTPUT);
}

void loop() {
  unsigned long currentMillis = millis();
  if (currentMillis - previousMillis >= interval) {
    previousMillis = currentMillis;
    if (ledState == LOW) {
      ledState = HIGH;
    } else {
      ledState = LOW;
    }
    digitalWrite(ledPin, ledState);
  }
  set_sleep_mode(SLEEP_MODE_IDLE);
  sleep_mode();
}

