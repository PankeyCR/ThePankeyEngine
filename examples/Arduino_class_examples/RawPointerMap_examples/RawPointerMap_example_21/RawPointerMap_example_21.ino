
//#define PrimitiveRawPointerMap_LogApp

#include "higgs.hpp"
#include "PrimitiveRawPointerMap.hpp"

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

  map.removeDeleteByKeyPointer(i_key);

  for(int x = 0; x < map.getPosition(); x++){
    MapEntry<int,int> entry = map.getMapEntryByPosition(x);
    if(entry.getKey() != nullptr){
      int key = *entry.getKey();
      System::console.print("key: ");System::console.print(key);
    }
    if(entry.getValue() != nullptr){
      int value = *entry.getValue();
      System::console.print("         value: ");System::console.println(value);
    }
  }

  ame_Debuging(ame_Log_EndLoop, "loop");
}