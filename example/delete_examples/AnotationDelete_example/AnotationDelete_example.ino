
#include "RobotArmTest.h"
#include "MemoryFree.h"
RobotArmTest *arm;

int deletememory;
int startmemory;
int instancememory;
 
void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  arm = new RobotArmTest(&Serial,5,6,7);
  instancememory = freeMemory();
       
  invoke(arm,"X",50);
  invoke(arm,"Y",70);
  invoke(arm,"Z",4);

  delete arm;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop(){
}
