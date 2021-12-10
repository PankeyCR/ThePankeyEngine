
#include "AnalogJoystick.hpp"
#include "JoystickCalibrationControl.hpp"

using namespace ame;

AnalogJoystick joy;
 
void setup() {
  Serial.begin(9600);
  joy.setPins(A10,A11,46);
  joy.attach(new JoystickCalibrationControl());
  Serial.println(joy.getRawX()); 
}

void loop(){
  joy.update(0.1f);
  Serial.print("X "); Serial.println(joy.getX()); 
  Serial.print("Y "); Serial.println(joy.getY()); 
  Serial.print("raw X "); Serial.println(joy.getRawX()); 
  Serial.print("raw Y "); Serial.println(joy.getRawY()); 
}
