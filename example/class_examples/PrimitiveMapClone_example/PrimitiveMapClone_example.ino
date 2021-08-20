
#include "PrimitiveMap.h"
#include "Map.h"
#include "Iterator.h"

using namespace ame;

Map<int,String> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new PrimitiveMap<int,String>();

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

  Map<int,String>* cloneMap = testMap->clone();
  delete testMap;//map can be deleted because the PrimitiveMap creates new instances of the data,
                  //but be sure that the contructor of the class template has no parameters
  for(Iterator i : *cloneMap){
    Serial.print(cloneMap->getKey(i));
    Serial.print(" ");
    Serial.println(cloneMap->getLValue(i));
  }
  
}

void loop() {}
