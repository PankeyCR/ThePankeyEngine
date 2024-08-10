
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"

#include "Array.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Array<int> array = {1,2,3,4,5};
  Array<int> array_2 = {11,12,13,14,15};
  
  array.insertLocalArray(2, array_2);
  
  for(int i : array){
    System::console.println(i);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}