
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
//  PrimitiveMap<String,int> m_map;
  PrimitiveRawMap<String,int> m_map;
//  HashMap<String,int> m_map;
  
  m_map.put("test",15);
  m_map.put("monkey",76);
  m_map.put("arduino",35);

  if(m_map.containKeyByLValue("monkey")){
    Serial.println("contain monkey key");
  }

  if(m_map.containValueByLValue(76)){
    Serial.println("contain 76 value");
  }
  
  m_map.resetDelete();
  
  m_map.put("mega",222);
  m_map.put("feather",321);
  m_map.put("leonardo",354);

  for(auto iterator : m_map){
    String key = iterator.getKey();
    int value = iterator.getValue();
    Serial.print("key ");Serial.println(key);
    Serial.print("value ");Serial.println(value);
  }
  
  m_map.remove("feather");

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
