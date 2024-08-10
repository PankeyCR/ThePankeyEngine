
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createDataAllocator<int>();
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  Data<int> var;
  var.create();
  if(var.isNull()){
    return;
  }
  int* pointer = var.get();
  *pointer = 15;
  int value = *pointer;
  
  Serial.println(value);  
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//