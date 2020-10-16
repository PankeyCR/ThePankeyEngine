
#include "Method.h"
#include "RobotArmTest.h"

RobotArmTest *arm;
 
void setup() {
  Serial.begin(9600);
  arm = new RobotArmTest(&Serial,5,6,7);
       
  bool x = Method::invoke<bool,RobotArmTest,float>(arm,"X",50.0f);
  bool y = Method::invoke<bool,RobotArmTest,float>(arm,"Y",70.0f);
  bool z = Method::invoke<bool>(arm,"Z",4.0f);
  String stop = Method::invoke<String>(arm,"stop");
  
  Serial.print("x: ");Serial.println(x);
  Serial.print("y: ");Serial.println(y);
  Serial.print("z: ");Serial.println(z);
  Serial.print("stop: ");Serial.println(stop);
}

void loop(){
}