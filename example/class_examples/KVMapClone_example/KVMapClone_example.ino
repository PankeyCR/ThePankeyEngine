
#include "KVMap.h"
#include "Map.h"

Map<int,String> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new KVMap<int,String,10>();

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
  delete testMap;//testMap can be deleted because the new map has new rvalues saved on it, 
                 //and KVMap doesnt have ownership of the data stored on the list
  iterate(cloneMap){
    Serial.print(cloneMap->getKey());
    Serial.print(" ");
    Serial.println(cloneMap->getValue());
  }
  
}

void loop() {}
