
#include "ame_Enviroment.hpp"
#include "ame_Enviroment_config.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  createValueManager<int>();
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Var<int> i = 100;
  Var<int> j = 200;
  Var<int> k = 300;
  
  DataList<int> list;
  
  list.add(i);
  list.add(j);
  list.add(k);

  for(int x = 0; x < list.length(); x++){
    Var<int> number = list.get(x);
    if(number.isNull()){
      continue;
    }
    System::console.println(number.getValue());
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}