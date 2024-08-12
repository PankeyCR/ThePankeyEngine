
#include "higgs_Enviroment.hpp"
#include "higgs_Enviroment_config.hpp"

#include "Array.hpp"
#include "Cast.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  higgs_Debuging(higgs_Log_StartLoop, "loop");
  
  Array<int> array = {1,2,3,4,5};
  Array<int> array_2 = move(array);

  for(int i : array_2){
    System::console.println(i);
  }
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}