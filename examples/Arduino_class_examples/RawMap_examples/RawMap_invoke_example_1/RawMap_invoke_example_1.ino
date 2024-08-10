
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void print(){
  System::console.println("printing");
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  MethodMap<String> map;

  String print_name = "print";

  map.add(print_name, print);

  invoke(map, print_name);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//