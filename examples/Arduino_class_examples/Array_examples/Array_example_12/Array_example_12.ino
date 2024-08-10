
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"

#include "Array.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Array<int> array = {1,3,2,3,4,3,5};

  int index = array.getLastIndex(3);
  
  System::console.print("index ");
  System::console.println(index);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}