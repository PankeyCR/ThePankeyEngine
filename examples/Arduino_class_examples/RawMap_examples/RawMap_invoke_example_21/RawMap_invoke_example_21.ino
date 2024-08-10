
#include "higgs.hpp"
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

  Example example;

  String parameter = "Higgs";
  String var = invoke(example, &Example::print, parameter);
  System::console.println(var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//