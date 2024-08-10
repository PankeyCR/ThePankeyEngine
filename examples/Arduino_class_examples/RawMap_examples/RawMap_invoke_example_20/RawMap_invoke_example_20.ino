
#include "higgs.hpp"
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

  Example example;

  String var = "Higgs";
  invoke(example, &Example::print, var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//