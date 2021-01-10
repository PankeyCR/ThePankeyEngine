
#include "Method.h"
#include "RobotArmTest.h"

RobotArmTest *arm;
 
void setup() {
  Serial.begin(9600);
  //remember to change the pins values to any allowed pin on your board
  arm = new RobotArmTest(&Serial,16,5,4);
}

void loop(){
  bool x = Method::invoke<bool,RobotArmTest,float>(arm,"X",50.0f);
  bool y = Method::invoke<bool,RobotArmTest,float>(arm,"Y",70.0f);
  bool z = Method::invoke<bool>(arm,"Z",4.0f);
  String stop = Method::invoke<String>(arm,"stop");
  
  Serial.print("x: ");Serial.println(x);
  Serial.print("y: ");Serial.println(y);
  Serial.print("z: ");Serial.println(z);
  Serial.print("stop: ");Serial.println(stop);
}