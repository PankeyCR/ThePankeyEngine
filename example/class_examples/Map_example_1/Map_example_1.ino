
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
  m_map.add("monkey",76);
  m_map.add("arduino",35);

  for(int x = 0; x < m_map.getPosition(); x++){
    String key = m_map.getKey(x);
    int value = m_map.getValue(x);
    Serial.print("key ");Serial.println(key);
    Serial.print("value ");Serial.println(value);
  }

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
