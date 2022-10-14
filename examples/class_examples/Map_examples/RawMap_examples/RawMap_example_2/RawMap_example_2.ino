
#include "ame_Enviroment.hpp"
#include "PrimitiveRawMap.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  PrimitiveRawMap<int,int> map;

  map.addPointer(1, new int(11));
  map.addPointer(2, new int(12));
  map.addPointer(3, new int(13));
  map.addPointer(4, new int(14));
  map.addPointer(5, new int(15));

  for(auto entry :  map){
    int key = entry.getKey();
    int value = entry.getValue();
    System::console.print("key: ");System::console.print(key);
    System::console.print("     value: ");System::console.println(value);
  }

  ame_Debuging(ame_Log_EndLoop, "loop");
}