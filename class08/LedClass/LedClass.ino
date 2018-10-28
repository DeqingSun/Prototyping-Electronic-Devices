class BlinkLED {
    int ledPin;
    int duration;
    bool ledState;
    unsigned long previousMillis;

  public:
    BlinkLED(int _ledPin, int _duration) {
      ledPin = _ledPin;
      pinMode(ledPin, OUTPUT);
      duration = _duration;
      ledState = LOW;
      previousMillis = 0;
    }

    void Update() {
      unsigned long currentMillis = millis();
      if (currentMillis - previousMillis >= duration)
      {
        previousMillis = currentMillis;
        if (ledState == LOW) {          //shift state of machine
          ledState = HIGH;
        } else {
          ledState = LOW;
        }
        digitalWrite(ledPin, ledState);  // Update the actual LED
      }
    }
};

BlinkLED led1(13, 500);

void setup() {
}

void loop() {
  asm("nop");
  led1.Update();
}
