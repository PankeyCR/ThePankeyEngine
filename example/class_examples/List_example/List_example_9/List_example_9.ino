
#include "RawMap.hpp"
#include "Map.hpp"

#include "PrimitiveRawMap.hpp"
#include "PrimitiveMap.hpp"
#include "KVMap.hpp"
#include "KPMap.hpp"
#include "PMap.hpp"

#include "MapNote.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  PrimitiveRawMap<int,Note> m_map;
//  PrimitiveMap<int,Note> m_map;
//  KVMap<int,Note> m_map;
//  KPMap<int,Note> m_map;
//  PMap<int,Note> m_map;

  m_map.addKeyPack(10, 20, 30);

  Serial.println(MapNote_p(m_map));

  m_map.resetDelete();

  m_map.addKeyPack(Note("numbers"), 10, 20, 30);

  Serial.println(MapNote_p(m_map));

  m_map.resetDelete();

  m_map.addValuePack("first", "second", "third");

  Serial.println(MapNote_p(m_map));

  m_map.resetDelete();

  m_map.addValuePack(10, "third", "fourth", "fifth");

  Serial.println(MapNote_p(m_map));
}




//
