
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createDataAllocator<int>();
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Var<int> var;
  
  Serial.println(var.getValue());  
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//