
#include "PrimitiveMap.h"
#include "Map.h"

Map<int,String> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new PrimitiveMap<int,String>();

  testMap->add(new int(85),new String("names"));
  testMap->add(new int(24),new String("node"));
  testMap->add(new int(57),new String("pankey"));
  testMap->add(new int(7),new String("test"));
  testMap->add(new int(0),new String("monkey"));
  
  iterate(testMap){
    Serial.print(testMap->getKey());
    Serial.print(" ");
    Serial.println(testMap->getValue());
  }

  Map<int,String>* cloneMap = testMap->clone();
  delete testMap;//map can be deleted because the PrimitiveMap creates new instances of the data,
                  //but be sure that the contructor of the class template has no parameters
  iterate(cloneMap){
    Serial.print(cloneMap->getKey());
    Serial.print(" ");
    Serial.println(cloneMap->getValue());
  }
  
}

void loop() {}
