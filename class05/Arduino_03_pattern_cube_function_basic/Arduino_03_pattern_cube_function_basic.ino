void setup() {
  digitalWrite(11, LOW);  //we change pinMode on cathod to control current
  digitalWrite(12, LOW);

  pinMode(2, OUTPUT); //we use High and Low for common cathod
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
}

void loop() {
  setLayerOutput(HIGH, HIGH, HIGH, LOW);
  enableLayer(0);
  delay(8);
  disableLayers();

  setLayerOutput(LOW, LOW, HIGH, LOW);
  enableLayer(1);
  delay(8);
  disableLayers();
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

