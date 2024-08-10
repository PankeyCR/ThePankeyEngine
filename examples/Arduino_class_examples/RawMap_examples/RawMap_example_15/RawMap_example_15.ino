
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

  int i_key = map.getKey(2);
  int i_value = map.getValue(2);

  System::console.print("key: ");
  System::console.print(i_key);
  System::console.print("    value: ");
  System::console.println(i_value);

  ame_Debuging(ame_Log_EndLoop, "loop");
}