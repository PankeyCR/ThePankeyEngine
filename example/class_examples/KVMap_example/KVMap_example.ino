
#include "KVMap.h"
#include "Map.h"
#include "MemoryFree.h"

using namespace ame;

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
}
void loop(){
  Serial.println("////////////start");
  Serial.println(freeMemory());
  testMap = new KVMap<String,int,10>();
  
  testMap->addLValues("test", 15);
  testMap->addLValues("a", 10);
  testMap->addLValues("in", 40);
  testMap->addLValues("monkey", 20);
  testMap->addLValues("total", 50);
  testMap->addLValues("engine", 30);
  testMap->addLValues("go", 7);
  

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPosition());
  
  for(Iterator i : *testMap){
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey(i));
    Serial.print("Actual Value:  ");Serial.println(testMap->getLValue(i));
  }

  
  Serial.print("Value go:  ");Serial.println(*testMap->getByLValue("go"));
  testMap->removeDeleteByLValue("go");

  if(testMap->getByLValue("go") == nullptr){
    Serial.println("Value go is null ");
  }
  testMap->removeDeleteByLValue("test");
  testMap->removeDeleteByLValue("in");
  testMap->removeDeleteByLValue("total");

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPosition());
  
  for(Iterator i : *testMap){
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey(i));
    Serial.print("Actual Value:  ");Serial.println(testMap->getLValue(i));
  }
  delete testMap;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}