
//#define PrimitiveRawPointerMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  PrimitiveRawMap<int,int> map;

  map.add(1, 11);
  map.add(2, 12);
  map.add(3, 13);
  map.add(4, 14);
  map.add(5, 15);

  int* i_key = map.getKeyByLValue(13);

  System::console.print("key: ");
  System::console.println(*i_key);

  ame_Debuging(ame_Log_EndLoop, "loop");
}