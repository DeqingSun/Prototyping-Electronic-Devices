#define PIN_LED 1

void setup() {
  // initialize digital pin 13 as an output.
  pinMode(PIN_LED, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(PIN_LED, HIGH);   // turn the LED on (HIGH is the voltage level)
  delay(1000);              // wait for a second
  digitalWrite(PIN_LED, LOW);    // turn the LED off by making the voltage LOW
  delay(1000);              // wait for a second
}
