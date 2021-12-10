
#include "KVMap.hpp"
#include "Map.hpp"
#include "MemoryRam.h"

using namespace ame;

Map<int,String> *testMap;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  testMap = new KVMap<int,String,10>();

  testMap->addPointers(new int(85),new String("names"));
  testMap->addPointers(new int(24),new String("node"));
  testMap->addPointers(new int(57),new String("pankey"));
  testMap->addPointers(new int(7),new String("test"));
  testMap->addPointers(new int(0),new String("monkey"));
  
  for(int x = 0; x < testMap->getPosition(); x++){
    Serial.print(testMap->getKey(x));
    Serial.print(" ");
    Serial.println(testMap->getValue(x));
  }

  Map<int,String>* cloneMap = testMap->clone(true);
  delete testMap;//
  
  for(int x = 0; x < cloneMap->getPosition(); x++){
    Serial.print(cloneMap->getKey(x));
    Serial.print(" ");
    Serial.println(cloneMap->getValue(x));
  }
  delete cloneMap;
  Serial.println("////////////end");
  Serial.println(getRamSize());
}