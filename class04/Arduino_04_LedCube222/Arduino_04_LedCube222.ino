
/*
   This is code for 2*2*2 cube
   4 common anode pins are connected to Arduino pin 2,3,4,5 via resistors
   2 common cathode pins are connected to Arduino pin 1,12
*/

void setup() {
  digitalWrite(11, LOW);  //we change pinMode on cathod to control current
  digitalWrite(12, LOW);

  pinMode(2, OUTPUT); //we use High and Low for common cathod
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  for (uint8_t j = 0; j < 4; j++) {
    for (uint8_t i = 0; i < 8; i++) {
      displayByte(1 << i, 100);
    }
  }
  displayByte(0, 200);
  for (uint8_t j = 0; j < 2; j++) {
    for (uint8_t i = 0; i < 2; i++) {
      displayByte(0b00001111, 200);
      displayByte(0b11110000, 200);
    }
    for (uint8_t i = 0; i < 2; i++) {
      displayByte(0b01010101, 200);
      displayByte(0b10101010, 200);
    }
  }
  displayByte(0, 200);
  for (uint8_t j = 0; j < 4; j++) {
    displayByte(0b00000001, 200);
    displayByte(0b00010110, 200);
    displayByte(0b01101000, 200);
    displayByte(0b10000000, 200);
  }
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

void setLayerOutput(boolean led0, boolean led1, boolean led2, boolean led3) {
  digitalWrite(2, led0);
  digitalWrite(3, led1);
  digitalWrite(4, led2);
  digitalWrite(5, led3);
}

void displayByte(uint8_t data, uint16_t duration) {
  unsigned long beginTime = millis();
  do {
    enableLayer(0);
    setLayerOutput(data & (1 << 0), data & (1 << 1), data & (1 << 2), data & (1 << 3));
    delay(2);
    disableLayers();
    enableLayer(1);
    setLayerOutput(data & (1 << 4), data & (1 << 5), data & (1 << 6), data & (1 << 7));
    delay(2);
    disableLayers();
  } while (millis() - beginTime < duration);
}

