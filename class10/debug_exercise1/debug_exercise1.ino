void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  int inputArray[3]={1,2,3};
  volatile int product = 0;
  volatile int i;
  asm("nop");
  for (i=0;i<=3;i++){
    volatile int inputNumber = inputArray[i];
    product = product * inputNumber;
    asm("nop");
  }
  if (product==6){
    digitalWrite(LED_BUILTIN,HIGH);
  }

  asm("nop");
}
