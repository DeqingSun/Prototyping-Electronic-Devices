boolean LED_1_state = LOW;
int LED_1_toggle_time = 2000;
unsigned long LED_1_previousMillis = 0;

boolean LED_2_state = LOW;
int LED_2_toggle_time = 3000;
unsigned long LED_2_previousMillis = 0;

void setup() {
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
}

void loop() {
  unsigned long LED_1_currentsMillis = millis();
  unsigned long LED_2_currentsMillis = millis();
  if (LED_1_currentsMillis - LED_1_previousMillis >= LED_1_toggle_time) {
    LED_1_previousMillis = LED_1_currentsMillis;
    LED_1_state = !LED_1_state;
    digitalWrite(13, LED_1_state);
  }
  if (LED_2_currentsMillis - LED_2_previousMillis >= LED_2_toggle_time) {
    LED_2_previousMillis = LED_2_currentsMillis;
    LED_2_state = !LED_2_state;
    digitalWrite(12, LED_2_state);
  }
}


