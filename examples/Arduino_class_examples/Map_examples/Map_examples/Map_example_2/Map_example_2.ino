
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
  
  PrimitiveMap<int,int> map_2;
  
  map_2.add(1,11);
  map_2.add(2,12);
  map_2.add(3,13);
  map_2.add(4,14);
  map_2.add(5,15);
  
  System::console.print("map == map_2: ");
  System::console.println(map == map_2);
  
  PrimitiveMap<int,int> map_3;
  
  map_3.add(1,11);
  map_3.add(2,15);
  map_3.add(3,13);
  map_3.add(4,18);
  map_3.add(5,15);
  
  System::console.print("map == map_3: ");
  System::console.println(map == map_3);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//