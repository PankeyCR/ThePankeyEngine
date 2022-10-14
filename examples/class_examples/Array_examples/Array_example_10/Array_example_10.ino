
#include "Array.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Array<int> array = {1,2,3,4,5};
  
  if(array.contain(3)){
    System::console.println("array contain value 3");
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}