
#include "higgs_Enviroment.hpp"
#include "higgs_Enviroment_config.hpp"

#include "Array.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  higgs_Debuging(higgs_Log_StartLoop, "loop");
  
  Array<int> array = {1,2,3,4,5};
  Array<int> array_2 = {11,12,13,14,15};
  
  array.insertLocalArray(2, array_2);
  
  for(int i : array){
    System::console.println(i);
  }
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}