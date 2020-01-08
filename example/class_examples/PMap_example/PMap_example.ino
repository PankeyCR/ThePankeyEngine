
#include "PMap.h"
#include "Map.h"

Map<String,int> *testMap;

void setup() {
  Serial.begin(9600);
  testMap = new PMap<String,int,10>();
  
  testMap->add(new String("names"), new int(15));
  testMap->add(new String("node"), new int(10));
  testMap->add(new String("pankey"), new int(5));
  testMap->add(new String("test"), new int(0));
  testMap->add(new String("monkey"), new int(7));
  

  for(int x = 0; x < testMap->getPos(); x++){
    Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
    Serial.print("Total Size Used:  ");Serial.println(testMap->getPos());
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Key:  ");Serial.println(*testMap->getKeyByPos(x));
    Serial.print("Actual Value:  ");Serial.println(*testMap->getByPos(x));
  }

  
  Serial.print("Value monkey:  ");Serial.println(*testMap->get("monkey"));
  testMap->remove("monkey");
  Serial.print("Value monkey:  ");Serial.println(*testMap->get("monkey"));

  if(testMap->get("monkey") == NULL){
    Serial.println("Value monkey is null ");
  }

  for(int x = 0; x < testMap->getPos(); x++){
    Serial.print("Total Size Available:  ");Serial.println(testMap->getSize());
    Serial.print("Total Size Used:  ");Serial.println(testMap->getPos());
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Key:  ");Serial.println(*testMap->getKeyByPos(x));
    Serial.print("Actual Value:  ");Serial.println(*testMap->getByPos(x));
  }
  
}
void loop() {
  

}
