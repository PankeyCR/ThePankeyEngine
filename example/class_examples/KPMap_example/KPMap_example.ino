
#include "KPMap.h"
#include "Map.h"

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new KPMap<String,int,10>();
  
  testMap->add("test", new int(15));
  testMap->add("a", new int(10));
  testMap->add("in", new int(40));
  testMap->add("monkey", new int(20));
  testMap->add("total", new int(50));
  testMap->add("engine", new int(30));
  testMap->add("go", new int(7));
  

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPos());
  
  iterate(testMap){
    Serial.print("Actual Position:  ");Serial.println(testMap->getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey());
    Serial.print("Actual Value:  ");Serial.println(testMap->getValue());
    //Serial.print("Actual Pointer:  ");Serial.println(testMap->getPointer());
  }

  
  Serial.print("Value go:  ");Serial.println(*testMap->get("go"));
  testMap->removeDelete("go");
  Serial.print("Value go:  ");Serial.println(*testMap->get("go"));

  if(testMap->get("go") == NULL){
    Serial.println("Value go is null ");
  }
  testMap->removeDelete("test");
  testMap->removeDelete("in");
  testMap->removeDelete("total");

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPos());
  
  iterate(testMap){
    Serial.print("Actual Position:  ");Serial.println(testMap->getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey());
    Serial.print("Actual Value:  ");Serial.println(testMap->getValue());
    //Serial.print("Actual Pointer:  ");Serial.println(testMap->getPointer());
  }
  
}
void loop(){}
