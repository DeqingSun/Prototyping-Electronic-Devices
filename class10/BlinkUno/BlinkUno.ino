#include <Arduino.h>

void __attribute__ ((noinline)) testSimpleAdd(){
  volatile unsigned char b,c;
  //unsigned char a,b;
  volatile unsigned char d;

  asm("nop");
  b=1;
  c=2;
  d=b+c;
  asm("nop");
}

volatile unsigned char a;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  testSimpleAdd();

  digitalWrite(LED_BUILTIN, HIGH); 
  a=1;
  asm("nop");
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW);   
  a=a+2;
  asm("nop"); 
  delay(100);                       
}
