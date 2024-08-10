
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
  void print(){
    System::console.println("printing");
  }
  void run(){
    System::console.println("running");
  }
};

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ClassMethodMap<Example,String> map;

  String print_name = "print";

  map.add(print_name, &Example::print);
  map.add(print_name, &Example::run);

  Example example;

  invokeAll(map, example);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//