
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

String print(String a_var){
  System::console.println(a_var);
  return "";
}

String run(String a_var){
  System::console.println(a_var);
  return "";
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  MethodReturnMap<String,String,String> map;

  String print_name = "print";

  map.add(print_name, print);
  map.add(print_name, run);

  String name = "Higgs";
  invokeAll(map, name);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//