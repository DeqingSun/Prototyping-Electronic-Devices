void setup() {
  pinMode(LED_BUILTIN,OUTPUT);
  digitalWrite(LED_BUILTIN,LOW);
}

void loop() {
  int inputArray[3]={1,2,3};
  volatile int sum = 0;
  volatile int i;
  for (i=0;i<=3;i++){
    volatile int inputNumber = inputArray[i];
    sum = sum + inputNumber;
    asm("nop");
  }
  if (sum==6){
    digitalWrite(LED_BUILTIN,HIGH);
  }

  asm("nop");
}
