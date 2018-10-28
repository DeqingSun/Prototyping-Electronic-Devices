bool pin12State = false;

void setup() {
  pinMode(LED_BUILTIN, OUTPUT);
  digitalWrite(LED_BUILTIN, LOW);

  pinMode(12, OUTPUT); //use pin 12 as debug
  pinMode(11, OUTPUT); //use pin 11 as debug
}

void loop() {
  digitalWrite(11, HIGH); //loop started

  int inputArray[3] = {1, 2, 3};
  int sum = 0;
  int i;
  for (i = 0; i <= 3; i++) {
    volatile int inputNumber = inputArray[i];
    sum = sum + inputNumber;

    pin12State = !pin12State;
    digitalWrite(12, pin12State);
  }
  if (sum == 6) {
    digitalWrite(LED_BUILTIN, HIGH);
  }

  digitalWrite(11, LOW); //loop ended
}

