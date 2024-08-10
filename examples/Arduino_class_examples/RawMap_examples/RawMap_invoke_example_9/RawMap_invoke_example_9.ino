
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

String print(){
  return "printing";
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  MethodReturnMap<String,String> map;

  String print_name = "print";

  map.add(print_name, print);

  String var = invoke(map, print_name);
  
  System::console.println(var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//