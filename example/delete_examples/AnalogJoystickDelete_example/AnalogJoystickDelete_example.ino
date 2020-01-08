
#include "AnalogJoystick.h"
#include "JoystickCalibrationControl.h"
#include "MemoryFree.h"

AnalogJoystick *joy;
 
int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  joy = new AnalogJoystick();
  joy->setPins(A10,A11,46);
  joy->addControl(new JoystickCalibrationControl());
  
  instancememory = freeMemory();
  
  joy->update();
  Serial.print("X "); Serial.println(joy->getX()); 
  Serial.print("Y "); Serial.println(joy->getY()); 
  Serial.print("Xraw "); Serial.println(joy->getRawX()); 
  Serial.print("Yraw "); Serial.println(joy->getRawY()); 

  delete joy;
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop(){
}
