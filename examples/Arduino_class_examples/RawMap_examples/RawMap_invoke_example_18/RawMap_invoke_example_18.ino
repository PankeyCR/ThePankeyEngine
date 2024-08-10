
#include "higgs.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void print(String var){
  System::console.println(var);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  using Method = void (*)(String);
  
  Method* method = new Method(print);

  String var = "Higgs";
  invoke(method, var);

  delete method;
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//