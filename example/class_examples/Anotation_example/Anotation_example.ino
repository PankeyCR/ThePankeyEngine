
#include "RobotArmTest.h"
RobotArmTest *arm;
 
void setup() {
  Serial.begin(9600);
  arm = new RobotArmTest(&Serial,5,6,7);
       
  invoke(arm,"X",50);
  invoke(arm,"Y",70);
  invoke(arm,"Z",4);
  
}

void loop(){
}
