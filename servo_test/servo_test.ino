#include <Servo.h>

VarSpeedServo myservo;  // create servo object to control a servo

int incomingByte = 0;
int currentPosition; // This is the position of the servo (in deg) 
int positionRequest; // stores request from serial monitor

void setup() {
  myservo.attach(3);  // attaches the servo on pin 3 to the servo object
  Serial.begin(9600); // Begin Serial communication with a baud rate of 9600
  Serial.setTimeout(50); //Makes Serial.parseInt() much faster (default is 1000)
}

void loop() {
  if (Serial.available() > 0) {
    // read the incoming ASCII as integer:
    positionRequest = Serial.parseInt();
    
  }
  Serial.print("Position: ");
  Serial.println(positionRequest);
//  Moveto(positionRequest,90);
  myServo.slowmove (positionRequest, 50);
  delay(100);
}

//void Moveto(int deg, int rate){
//  int SpeedToDelay = map(rate, 0,100,1000,0); // User inputs speed as value from 0 - 10 (slowest - fastest
//  // This is then mapped to a delay() in ms between 50 - 0 (slowest - fastest 
//  Serial.println(SpeedToDelay);
//  if (deg > currentPosition){
//    for(int pos = currentPosition; pos < deg; pos += 1){
//      myservo.write(pos);
//      currentPosition = pos;
//      delay(SpeedToDelay);
//    }
//  }
//  else if (deg < currentPosition){
//    for(int pos = currentPosition; pos > deg; pos -= 1){
//      myservo.write(pos);
//      currentPosition = pos;
//      delay(SpeedToDelay);
//    }
//  }
//}
