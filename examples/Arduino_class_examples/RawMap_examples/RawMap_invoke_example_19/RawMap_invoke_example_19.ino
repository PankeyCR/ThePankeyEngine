
#include "higgs.hpp"
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
};

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  using Method = void (Example::*)();

  Example example;
  
  invoke(example, &Example::print);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//