
#include "AnalogJoystick.h"
#include "JoystickCalibrationControl.h"

AnalogJoystick *joy;
 
void setup() {
  Serial.begin(9600);
  joy = new AnalogJoystick();
  joy->setPins(A10,A11,46);
  joy->attach(new JoystickCalibrationControl());
  Serial.println(joy->getRawX()); 
}

void loop(){
  joy->update(0.1f);
  //Serial.print("X "); Serial.println(joy->getX()); 
  //Serial.print("Y "); Serial.println(joy->getY()); 
  Serial.println(joy->getRawX()); 
}
