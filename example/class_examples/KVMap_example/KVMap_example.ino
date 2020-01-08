
#include "KVMap.h"
#include "Map.h"

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new KVMap<String,int,10>();
  
  testMap->add("test", 15);
  testMap->add("a", 10);
  testMap->add("in", 40);
  testMap->add("monkey", 20);
  testMap->add("total", 50);
  testMap->add("engine", 30);
  testMap->add("go", 7);
  

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPos());
  
  iterate(testMap){
    Serial.print("Actual Position:  ");Serial.println(testMap->getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey());
    Serial.print("Actual Value:  ");Serial.println(testMap->getValue());
  }

  
  Serial.print("Value go:  ");Serial.println(*testMap->get("go"));
  testMap->remove("go");
  Serial.print("Value go:  ");Serial.println(*testMap->get("go"));

  if(testMap->get("go") == NULL){
    Serial.println("Value go is null ");
  }
  testMap->remove("test");
  testMap->remove("in");
  testMap->remove("total");

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPos());
  
  iterate(testMap){
    Serial.print("Actual Position:  ");Serial.println(testMap->getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey());
    Serial.print("Actual Value:  ");Serial.println(testMap->getValue());
  }
  
}
void loop(){}
