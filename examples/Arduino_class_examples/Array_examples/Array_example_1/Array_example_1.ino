
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"

#include "Array.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Array<int> array;

  array.addLocalValue(1);
  array.addLocalValue(2);
  array.addLocalValue(3);
  array.addLocalValue(4);
  array.addLocalValue(5);

  for(int i : array){
    System::console.println(i);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}