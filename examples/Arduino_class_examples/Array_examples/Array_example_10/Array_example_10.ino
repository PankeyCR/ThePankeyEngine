
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
  
  if(array.contain(3)){
    System::console.println("array contain value 3");
  }
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}