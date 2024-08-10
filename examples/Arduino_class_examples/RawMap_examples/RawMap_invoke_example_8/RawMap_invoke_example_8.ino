
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
  void run(String var){
    System::console.println(var);
  }
};

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ClassMethodMap<Example,String,String> map;

  String print_name = "print";

  map.add(print_name, &Example::print);
  map.add(print_name, &Example::run);

  Example example;

  String parameter = "Higgs";
  invokeAll(map, example, parameter);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//