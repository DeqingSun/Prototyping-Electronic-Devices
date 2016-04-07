#include <SPI.h>
#include "L6470.h"

L6470 stepper(10);

int divMul = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  stepper.init();
  stepper.free();
  stepper.setAcc(100); //set acceleration
  stepper.setMaxSpeed(1);



  stepper.setMinSpeed(1);
  stepper.setMicroSteps(1); //1,2,4,8,16,32,64 or 128
  stepper.setThresholdSpeed(100);
  stepper.setOverCurrent(6000); //set overcurrent protection
  stepper.setStallCurrent(3000);

  stepper.softStop();

}

void loop() {
  quarterTurn(2);
  delay(50);
  quarterTurn(4);
  delay(50);
  quarterTurn(8);
  delay(50);
  quarterTurn(16);
  delay(50);
  delay(5000);
}

void quarterTurn(int divMul) {
  stepper.softFree();
  stepper.setMicroSteps(1 * divMul); //1,2,4,8,16,32,64 or 128
  stepper.softStop();
  stepper.move(50 * divMul);

  while (stepper.isBusy()) {
    delay(10);
  }

  stepper.softFree();
}



