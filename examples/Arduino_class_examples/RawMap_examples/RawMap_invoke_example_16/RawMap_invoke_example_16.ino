
//#define PrimitiveRawMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

class Example{
  public:
  Example(){}
  String print(String var){
    System::console.println(var);
    return "";
  }
  String run(String var){
    System::console.println(var);
    return "";
  }
};

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ClassMethodReturnMap<Example,String,String,String> map;

  String print_name = "print";

  map.add(print_name, &Example::print);
  map.add(print_name, &Example::run);

  Example example;

  String parameter = "Higgs";
  invokeAll(map, example, parameter);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//