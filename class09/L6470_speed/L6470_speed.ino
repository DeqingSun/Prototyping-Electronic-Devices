#include <SPI.h>
#include "L6470.h"

L6470 stepper(10);

int divMul = 1;

void setup() {
  Serial.begin(9600);
  Serial.println("start");
  stepper.init();
  stepper.free();
  stepper.setAcc(1000); //set acceleration
  stepper.setMaxSpeed(1);



  stepper.setMinSpeed(1);
  stepper.setMicroSteps(2); //1,2,4,8,16,32,64 or 128
  stepper.setThresholdSpeed(100);
  stepper.setOverCurrent(6000); //set overcurrent protection
  stepper.setStallCurrent(3000);

  stepper.softStop();

}

void loop() {
  stepper.setMaxSpeed(1);
  stepper.move(100);
  while (stepper.isBusy()) {
    delay(10);
  }

  stepper.setMaxSpeed(100);
  stepper.move(300);
  while (stepper.isBusy()) {
    delay(10);
  }

  stepper.setMaxSpeed(500);
  stepper.move(1500);
  while (stepper.isBusy()) {
    delay(10);
  }
  stepper.softFree();
  delay(5000);
  stepper.softStop();

}




