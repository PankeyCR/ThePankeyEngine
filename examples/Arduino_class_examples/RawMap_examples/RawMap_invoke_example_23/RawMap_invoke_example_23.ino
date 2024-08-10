
#include "higgs.hpp"
#include "InvokeRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

String print(String a_var){
  return a_var;
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  using Method = String (*)(String);
  
  Method* method = new Method(print);

  String parameter = "Higgs";
  String var = invoke(method, parameter);
  System::console.println(var);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//