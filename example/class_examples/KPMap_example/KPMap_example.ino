
#include "KPMap.h"
#include "Map.h"

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
}
void loop(){
  Serial.println("//////////////start");
  testMap = new KPMap<String,int,10>();
  
  testMap->addPointer("test", new int(15));
  testMap->addPointer("a", new int(10));
  testMap->addPointer("in", new int(40));
  testMap->addPointer("monkey", new int(20));
  testMap->addPointer("total", new int(50));
  testMap->addPointer("engine", new int(30));
  testMap->addPointer("go", new int(7));
  

  Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
  Serial.print("Total Size Used:  ");Serial.println(testMap->getPosition());
  
  for(Iterator i : *testMap){
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Key:  ");Serial.println(testMap->getKey(i));
    Serial.print("Actual Value:  ");Serial.println(testMap->getLValue(i));
    //Serial.print("Actual Pointer:  ");Serial.println(testMap->getPointer(i));
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
    //Serial.print("Actual Pointer:  ");Serial.println(testMap->getPointer());
  }

  delete testMap;
  Serial.println("//////////////end");
}