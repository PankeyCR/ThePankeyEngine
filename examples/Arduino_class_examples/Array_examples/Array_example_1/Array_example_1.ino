
#include "higgs_Enviroment.hpp"
#include "higgs_Enviroment_config.hpp"

#include "Array.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  higgs_Debuging(higgs_Log_StartLoop, "loop");
  
  Array<int> array;

  array.addLocalValue(1);
  array.addLocalValue(2);
  array.addLocalValue(3);
  array.addLocalValue(4);
  array.addLocalValue(5);

  for(int i : array){
    System::console.println(i);
  }
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}