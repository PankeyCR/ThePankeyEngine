
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

  MapEntry<int,int> mapEntry(new int(3), new int(13));

  map.addMapEntry(MapEntry<int,int>(new int(1), new int(11)));
  map.addMapEntry(MapEntry<int,int>(new int(2), new int(12)));
  map.addMapEntry(mapEntry);
  map.addMapEntry(MapEntry<int,int>(new int(4), new int(14)));
  map.addMapEntry(MapEntry<int,int>(new int(5), new int(15)));

  MapEntry<int,int> mapEntry_2(mapEntry.getKey(), new int(99));

  map.setMapEntry(mapEntry_2);

  for(int x = 0; x < map.getPosition(); x++){
    MapEntry<int,int> entry = map.getMapEntryByPosition(x);
    if(entry.isNull()){
      continue;
    }
    int key = *entry.getKey();
    int value = *entry.getValue();
    System::console.print("key: ");System::console.print(key);
    System::console.print("     value: ");System::console.println(value);
  }

  ame_Debuging(ame_Log_EndLoop, "loop");
}