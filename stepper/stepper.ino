#include <Stepper.h> // Include the header file

#define STEPS 64 // Motor has 5.625 deg/ step which means 64 steps/revolution

Stepper mystepper(64, 8, 9, 10, 11); //stepper motor initialisation

void setup() {
//  Serial.begin(9600);
  mystepper.setSpeed(700); //
}

void loop() {

  delay(100);
  mystepper.step(100);
  

}
