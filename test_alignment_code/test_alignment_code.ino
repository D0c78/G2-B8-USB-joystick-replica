#include <Joystick.h>

Joystick_ Joystick;
int zAxis_ = 0;

const bool initAutoSendState = true; 

void setup() {
  Joystick.begin();
}

void loop() {
  zAxis_ = analogRead(A0);  
  //zAxis_ = map(zAxis_,10,275,0,255); // 1
  zAxis_ = map(zAxis_,443,597,0,255); // 2
  Joystick.setZAxis(zAxis_);
}
