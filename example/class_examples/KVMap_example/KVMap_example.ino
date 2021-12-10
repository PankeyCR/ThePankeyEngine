
#include "KVMap.hpp"
#include "Map.hpp"
#include "MemoryRam.h"

using namespace ame;

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
}
void loop(){
  Serial.println("////////////start");
  Serial.println(getRamSize());
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
  
  for(int x = 0; x < testMap->getPosition(); x++){
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey(x));
    Serial.print("Actual Value:  ");Serial.println(testMap->getValue(x));
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
  
  for(int x = 0; x < testMap->getPosition(); x++){
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey(x));
    Serial.print("Actual Value:  ");Serial.println(testMap->getValue(x));
  }
  delete testMap;
  Serial.println("////////////end");
  Serial.println(getRamSize());
}