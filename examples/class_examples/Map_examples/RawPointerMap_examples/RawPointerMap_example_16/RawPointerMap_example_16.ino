
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

  map.addPointers(new int(1), new int(11));
  map.addPointers(new int(2), new int(12));
  map.addPointers(new int(3), new int(13));
  map.addPointers(new int(4), new int(14));
  map.addPointers(new int(5), new int(15));

  int* i_key_2 = map.getKeyByPosition(2);
  int* i_value_2 = map.getValueByPosition(2);
  
  System::console.print("key: ");
  System::console.print(*i_key_2);
  System::console.print("       value: ");
  System::console.println(*i_value_2);

  ame_Debuging(ame_Log_EndLoop, "loop");
}