
#include "PList.h"
#include "List.h"

List<String> *testList;

void setup() {
  Serial.begin(9600);
  testList = new PList<String,10>();

  testList->add(new String("names"));
  testList->add(new String("node"));
  testList->add(new String("pankey"));
  testList->add(new String("test"));
  testList->add(new String("monkey"));
  

  for(int x = 0; x < testList->getPos(); x++){
    Serial.print("Total Size Available:  ");Serial.println(testList->getSize());
    Serial.print("Total Size Used:  ");Serial.println(testList->getPos());
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Object:  ");Serial.println(*testList->getByPos(x));
  }

  testList->remove("monkey");


  for(int x = 0; x < testList->getPos(); x++){
    Serial.print("Total Size Available:  ");Serial.println(testList->getSize());
    Serial.print("Total Size Used:  ");Serial.println(testList->getPos());
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Object:  ");Serial.println(*testList->getByPos(x));
  }
  
}
void loop() {
  

}
