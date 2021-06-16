
#include "Method.h"
#include "ClassType.h"
#include "RobotArmTest.h"

RobotArmTest *arm;
 
void setup() {
  Serial.begin(9600);
  //remember to change the pins values to any allowed pin on your board
  arm = new RobotArmTest(&Serial,16,5,4);
}

void loop(){
  Method* method = arm->getClass()->getMethod("X");
  if(method != nullptr){
    invoke<RobotArmTest,bool,float>(arm,method,false,50.0f);
  }
  invoke<RobotArmTest,bool,float>(arm,"Y",false,60.0f);
  invoke<RobotArmTest,bool,float>(arm,"Z",false,70.0f);
  Serial.println(invoke<RobotArmTest,String>(arm,"stop","default"));
}