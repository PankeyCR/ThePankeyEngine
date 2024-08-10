
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void print(String a_print){
  System::console.println(a_print);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  MethodMap<String,String> map;

  String print_name = "print";

  map.add(print_name, print);

  String parameter = "Higgs";
  invoke(map, print_name, parameter);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//