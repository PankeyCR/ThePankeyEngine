
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

String print(String var){
  return var;
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  MethodReturnMap<String,String,String> map;

  String print_name = "print";

  map.add(print_name, print);

  String parameter = "Higgs";
  String var = invoke(map, print_name, parameter);
  
  System::console.println(var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//