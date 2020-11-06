#include <Arduino.h>

volatile unsigned char a;
void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
}

// the loop function runs over and over again forever
void loop() {
  digitalWrite(LED_BUILTIN, HIGH); 
  a=1;
  asm("nop");
  delay(100);                       
  digitalWrite(LED_BUILTIN, LOW);   
  a=a+2;
  asm("nop"); 
  delay(100);                       
}
