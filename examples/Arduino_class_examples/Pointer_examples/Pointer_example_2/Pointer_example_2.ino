
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

  Data<int> var_2 = var;
  int* pointer_2 = var_2.get();
  *pointer_2 = 7;
  
  int value = *pointer;
  int value_2 = *pointer_2;
  
  Serial.print("value 1: ");Serial.println(value);  
  Serial.print("value 2: ");Serial.println(value_2);  
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}





//