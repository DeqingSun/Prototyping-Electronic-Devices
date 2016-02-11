void setup() {
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
}

void loop() {
  digitalWrite(10, LOW);
  //send data to shift register
  shiftOut(9, 8, MSBFIRST, 0b11110001); 
  //create a rising edge to latch data
  digitalWrite(10, HIGH); 
  digitalWrite(10, LOW);
}
