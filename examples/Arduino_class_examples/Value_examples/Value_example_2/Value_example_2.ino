
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createDataAllocator<int>();
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Var<int> var = 15;
  Var<int> var_2 = var;
  var_2 = 7;
  
  Serial.print("value 1: ");Serial.println(var.getValue());  
  Serial.print("value 2: ");Serial.println(var_2.getValue());  
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//