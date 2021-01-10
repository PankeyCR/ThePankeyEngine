
#include "PrimitiveMap.h"
#include "PMap.h"
#include "Map.h"
#include "MemoryFree.h"

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  testMap = new PMap<String,int,10>(true);
  
  testMap->addPointers(new String("names"), new int(15));
  testMap->addPointers(new String("node"), new int(10));
  testMap->addPointers(new String("pankey"), new int(5));
  testMap->addPointers(new String("test"), new int(0));
  testMap->addPointers(new String("monkey"), new int(7));
  

  for(int x = 0; x < testMap->getPosition(); x++){
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Key:  ");Serial.println(*testMap->getKeyByPosition(x));
    Serial.print("Actual Value:  ");Serial.println(*testMap->getByPosition(x));
  }

  
  Serial.print("Value monkey:  ");Serial.println(*testMap->getByLValue("monkey"));
  testMap->removeDeleteByLValue("monkey");

  if(testMap->getByLValue("monkey") == nullptr){
    Serial.println("Value monkey is null ");
  }

  for(Iterator i : *testMap){
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey(i));
    Serial.print("Actual Value:  ");Serial.println(testMap->getLValue(i));
  }
  delete testMap;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}