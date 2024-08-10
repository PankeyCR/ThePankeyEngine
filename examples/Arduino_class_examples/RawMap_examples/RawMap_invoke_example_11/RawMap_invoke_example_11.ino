
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

String print(){
  System::console.println("printing");
  return "";
}

String run(){
  System::console.println("running");
  return "";
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  MethodReturnMap<String,String> map;

  String print_name = "print";
  String run_name = "run";

  map.add(print_name, print);
  map.add(run_name, run);

  invokeAll(map);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//