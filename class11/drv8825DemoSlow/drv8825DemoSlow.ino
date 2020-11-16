#include <Arduino.h>
#include "DRV8825.h"


#define DRV_8825_STEP_PIN     PA0
#define DRV_8825_DIR_PIN      PA1
#define DRV_8825_SLEEP_PIN    PA2
#define DRV_8825_RST_PIN      PA3

#define DRV_8825_MS0_PIN      PA6
#define DRV_8825_MS1_PIN      PA5
#define DRV_8825_MS2_PIN      PA4

#define STEPPER_LOW_SW_PIN    PB13
#define STEPPER_HIGH_SW_PIN   PB12

#define STEPPER_TEST_BTN_PIN  PB9

#define RS485_CONTROL_PIN     PA8


// Motor steps per revolution. Most steppers are 200 steps or 1.8 degrees/step
#define MOTOR_STEPS 200
#define RPM 20

// Since microstepping is set externally, make sure this matches the selected mode
// If it doesn't, the motor will move at a different RPM than chosen
// 1=full step, 2=half step etc.
#define MICROSTEPS 1

//Uncomment line to use enable/disable functionality
//#define ENABLE 13

// 2-wire basic config, microstepping is hardwired on the driver
//BasicStepperDriver stepper(MOTOR_STEPS, DRV_8825_DIR_PIN, DRV_8825_STEP_PIN);

//Uncomment line to use enable/disable functionality
DRV8825 stepper(MOTOR_STEPS, DRV_8825_DIR_PIN, DRV_8825_STEP_PIN, DRV_8825_SLEEP_PIN, DRV_8825_MS0_PIN, DRV_8825_MS1_PIN, DRV_8825_MS2_PIN);

void setup() {

  afio_cfg_debug_ports(AFIO_DEBUG_SW_ONLY);
  pinMode(PC13, OUTPUT);

  Serial.begin(9600);

  pinMode(DRV_8825_DIR_PIN, OUTPUT); //direction
  digitalWrite(DRV_8825_DIR_PIN, LOW);
  pinMode(DRV_8825_SLEEP_PIN, OUTPUT);
  digitalWrite(DRV_8825_SLEEP_PIN, LOW);
  pinMode(DRV_8825_RST_PIN, OUTPUT);
  digitalWrite(DRV_8825_RST_PIN, HIGH);

  pinMode(DRV_8825_MS0_PIN, OUTPUT);
  digitalWrite(DRV_8825_MS0_PIN, LOW);
  pinMode(DRV_8825_MS1_PIN, OUTPUT);
  digitalWrite(DRV_8825_MS1_PIN, LOW);
  pinMode(DRV_8825_MS2_PIN, OUTPUT);
  digitalWrite(DRV_8825_MS2_PIN, LOW);


  stepper.begin(RPM, MICROSTEPS);
}

void loop() {

  Serial.println("Stepper Demo For Class");

  Serial.println("Now 30 second per Revolution without microstepping");
  //stepper.setMicrostep(1);
  stepper.setMicrostep(32);
  
  
  stepper.setRPM(2+10);
  stepper.enable();
  delay(10);
  stepper.rotate(360);
  delay(100);
  //stepper.rotate(-360);
  delay(10);
  stepper.disable();



  delay(1000);
}
