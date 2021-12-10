
#include "KPMap.hpp"
#include "Map.hpp"

using namespace ame;

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
  Serial.println("//////////////end");
}