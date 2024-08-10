
#include "higgs.hpp"
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

  using Method = void (*)();
  
  Method* method = new Method(print);

  invoke(method);

  delete method;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//