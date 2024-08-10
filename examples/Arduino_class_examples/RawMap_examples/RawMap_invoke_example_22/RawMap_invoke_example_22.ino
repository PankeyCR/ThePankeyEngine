
#include "higgs.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

String print(){
  return "printing";
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  using Method = String (*)();
  
  Method* method = new Method(print);
  
  String var = invoke(method);
  System::console.println(var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//