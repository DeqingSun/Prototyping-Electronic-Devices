bool useCorrectedPWM = true;
int LEDpin = 11;

void setup() {
}

void loop() {
  if (!useCorrectedPWM) { 
    analogWrite(LEDpin, 15);
    delay(125);
    analogWrite(LEDpin, 31);
    delay(125);
    analogWrite(LEDpin, 47);
    delay(125);
    analogWrite(LEDpin, 63);
    delay(125);
    analogWrite(LEDpin, 79);
    delay(125);
    analogWrite(LEDpin, 95);
    delay(125);
    analogWrite(LEDpin, 111);
    delay(125);
    analogWrite(LEDpin, 127);
    delay(125);
    analogWrite(LEDpin, 143);
    delay(125);
    analogWrite(LEDpin, 159);
    delay(125);
    analogWrite(LEDpin, 175);
    delay(125);
    analogWrite(LEDpin, 191);
    delay(125);
    analogWrite(LEDpin, 207);
    delay(125);
    analogWrite(LEDpin, 223);
    delay(125);
    analogWrite(LEDpin, 239);
    delay(125);
    analogWrite(LEDpin, 255);
    delay(125);
  } else {  
    analogWrite(LEDpin, 1);
    delay(125);
    analogWrite(LEDpin, 1);
    delay(125);
    analogWrite(LEDpin, 2);
    delay(125);
    analogWrite(LEDpin, 4);
    delay(125);
    analogWrite(LEDpin, 8);
    delay(125);
    analogWrite(LEDpin, 13);
    delay(125);
    analogWrite(LEDpin, 21);
    delay(125);
    analogWrite(LEDpin, 32);
    delay(125);
    analogWrite(LEDpin, 45);
    delay(125);
    analogWrite(LEDpin, 62);
    delay(125);
    analogWrite(LEDpin, 83);
    delay(125);
    analogWrite(LEDpin, 108);
    delay(125);
    analogWrite(LEDpin, 137);
    delay(125);
    analogWrite(LEDpin, 171);
    delay(125);
    analogWrite(LEDpin, 210);
    delay(125);
    analogWrite(LEDpin, 255);
    delay(125);
  }
}
