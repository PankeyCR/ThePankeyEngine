
#include "MemoryRam.h"
#include "PMap.hpp"
#include "KPMap.hpp"
#include "KVMap.hpp"
#include "PrimitiveMap.hpp"
#include "PrimitiveRawMap.hpp"
#include "HashMap.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
//  PMap<String,int,10> m_map = true;
//  KPMap<String,int,10> m_map = true;
//  KVMap<String,int,10> m_map;
  PrimitiveMap<String,int> m_map;
//  PrimitiveRawMap<String,int> m_map;
//  HashMap<String,int> m_map;
  
  m_map.add("test",15);
  m_map.add("test",76);
  m_map.add("test",35);

  for(auto iterator : m_map){
    String key = iterator.getKey();
    int value = iterator.getValue();
    Serial.print("key ");Serial.println(key);
    Serial.print("value ");Serial.println(value);
  }
  
  Serial.println();
  Serial.println(getRamSize());
  Serial.println();
  Serial.println();
}
