
#include "PMap.hpp"
#include "KPMap.hpp"
#include "KVMap.hpp"
#include "PrimitiveMap.hpp"
#include "HashMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
//  PMap<int,int,10> map = true;
//  KPMap<int,int,10> map = true;
//  KVMap<int,int,10> map;
  PrimitiveMap<int,int> map;
//  HashMap<int,int> map;
  
  map.add(1,11);
  map.add(2,12);
  map.add(3,13);
  map.add(4,14);
  map.add(5,15);

  for(auto entry :  map){
    int key = entry.getKey();
    int value = entry.getValue();
    System::console.print("key: ");System::console.print(key);
    System::console.print("     value: ");System::console.println(value);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//