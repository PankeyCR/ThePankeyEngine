
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

  array.remove(1,3);//1 = start, 3 = size
  
  for(int i : array){
    System::console.println(i);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}