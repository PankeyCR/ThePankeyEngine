
#include "PMap.h"
#include "Map.h"
#include "MemoryFree.h"

using namespace ame;

Map<int,String> *testMap;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  testMap = new PMap<int,String,10>(true);

  testMap->addPointers(new int(85),new String("names"));
  testMap->addPointers(new int(24),new String("node"));
  testMap->addPointers(new int(57),new String("pankey"));
  testMap->addPointers(new int(7),new String("test"));
  testMap->addPointers(new int(0),new String("monkey"));
  
  for(Iterator i : *testMap){
    Serial.print(testMap->getKey(i));
    Serial.print(" ");
    Serial.println(testMap->getLValue(i));
  }
  
  Map<int,String>* cloneMap = testMap->clone(true);
  delete testMap;
  
  for(Iterator i : *cloneMap){
    Serial.print(cloneMap->getKey(i));
    Serial.print(" ");
    Serial.println(cloneMap->getLValue(i));
  }

  delete cloneMap;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}