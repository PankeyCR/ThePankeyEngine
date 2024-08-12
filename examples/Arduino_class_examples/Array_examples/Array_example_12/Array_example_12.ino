
#include "higgs_Enviroment.hpp"
#include "higgs_Enviroment_config.hpp"

#include "Array.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  higgs_Debuging(higgs_Log_StartLoop, "loop");
  
  Array<int> array = {1,3,2,3,4,3,5};

  int index = array.getLastIndex(3);
  
  System::console.print("index ");
  System::console.println(index);
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}