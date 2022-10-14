
#include "ame_Enviroment.hpp"
#include "PrimitiveRawPointerMap.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  PrimitiveRawPointerMap<int,int> map;

  int* i_key = new int(3);
  int* i_value = new int(13);

  map.addPointers(new int(1), new int(11));
  map.addPointers(new int(2), new int(12));
  map.addPointers(i_key, i_value);
  map.addPointers(new int(4), new int(14));
  map.addPointers(new int(5), new int(15));

  int index = map.getKeyIndexByPointer(i_key);

  System::console.print("index: ");
  System::console.println(index);

  ame_Debuging(ame_Log_EndLoop, "loop");
}