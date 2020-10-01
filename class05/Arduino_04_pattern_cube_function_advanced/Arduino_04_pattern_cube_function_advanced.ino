#include <avr/pgmspace.h>
const uint8_t cubePattern[4] PROGMEM = {0b00000001, 0b00010110, 0b01101000, 0b10000000};

void setup() {
  digitalWrite(11, LOW);  //we change pinMode on cathod to control current
  digitalWrite(12, LOW);

  pinMode(2, OUTPUT); //we use High and Low for common cathod
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  for (uint8_t i = 0; i < 4; i++) {
    displayByte(pgm_read_byte(cubePattern+i), 200);
  }
}

void displayByte(uint8_t data, uint16_t duration) {
  unsigned long beginTime = millis();
  while ((millis() - beginTime) < duration) {
    enableLayer(0);
    setLayerOutput(bitRead(data, 0), bitRead(data, 1), bitRead(data, 2), bitRead(data, 3));
    delay(8);
    disableLayers();
    enableLayer(1);
    setLayerOutput(bitRead(data, 4), bitRead(data, 5), bitRead(data, 6), bitRead(data, 7));
    delay(8);
    disableLayers();
  };
}

void setLayerOutput(boolean led0, boolean led1, boolean led2, boolean led3) {
  digitalWrite(2, led0);
  digitalWrite(3, led1);
  digitalWrite(4, led2);
  digitalWrite(5, led3);
}

void enableLayer(int layer) {
  if (layer == 0) {
    pinMode(12, INPUT);
    pinMode(11, OUTPUT);
  } else if (layer == 1) {
    pinMode(11, INPUT);
    pinMode(12, OUTPUT);
  } else {
    disableLayers();
  }
}
void disableLayers() {
  pinMode(11, INPUT);
  pinMode(12, INPUT);
}

