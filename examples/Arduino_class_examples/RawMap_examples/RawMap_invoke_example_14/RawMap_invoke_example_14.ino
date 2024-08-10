
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
    return var;
  }
};

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ClassMethodReturnMap<Example,String,String,String> map;

  String print_name = "print";

  map.add(print_name, &Example::print);

  Example example;

  String parameter = "Higgs";
  String var = invoke(map, example, print_name, parameter);
  System::console.println(var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//