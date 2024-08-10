
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
  void print(String var){
    System::console.println(var);
  }
};

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ClassMethodMap<Example,String,String> map;

  String print_name = "print";

  map.add(print_name, &Example::print);

  Example example;

  String parameter = "Higgs";
  invoke(map, example, print_name, parameter);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//