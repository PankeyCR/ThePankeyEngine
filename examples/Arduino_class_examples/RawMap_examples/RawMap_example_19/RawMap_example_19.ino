
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

  map.putPointer(1, new int(11));
  map.putPointer(1, new int(11));
  map.putPointer(1, new int(11));
  map.putPointer(1, new int(11));
  map.putPointer(1, new int(11));

  for(auto entry :  map){
    int key = entry.getKey();
    int value = entry.getValue();
    System::console.print("key: ");System::console.print(key);
    System::console.print("     value: ");System::console.println(value);
  }

  ame_Debuging(ame_Log_EndLoop, "loop");
}





//