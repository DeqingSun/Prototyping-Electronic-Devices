void setup() {
  // put your setup code here, to run once:
  analogWrite(11, 128);
  //TCCR2B & (~0b111) means set low 3 bits to 0
  //TCCR2B = TCCR2B & (~0b111) | 0b100;  //div64, Arduino default
  //TCCR2B = TCCR2B & (~0b111) | 0b010;  //div8
  //TCCR2B = TCCR2B & (~0b111) | 0b001;  //div1
}

void loop() {
  // put your main code here, to run repeatedly:

}
