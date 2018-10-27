
void setup() {
}

void loop() {
  volatile int a,b;
  //int a,b;
  volatile int c;

  a=1;
  b=2;
  c=a+b;
  asm("nop");
}
