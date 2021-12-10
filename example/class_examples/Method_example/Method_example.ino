
#include "RobotArmTest.hpp"

using namespace ame;

RobotArmTest *arm;
 
void setup() {
  Serial.begin(9600);
  //remember to change the pins values to any allowed pin on your board
  arm = new RobotArmTest(&Serial);
}

void loop(){
  Serial.println("start");
  Method* method = arm->getClass()->getMethod("X");
  if(method != nullptr){
    method->invoke<RobotArmTest,bool,float>(arm,false,50.0f);
  }
  RawList<Method>* methods = arm->getClass()->getMethods();
  if(methods == nullptr){
    return;
  }
  for(int x = 0; x < methods->getPosition(); x++){
    Method* m = methods->getByPosition(x);
    m->invoke<RobotArmTest,bool,float>(arm,false,50.0f);
  }
}