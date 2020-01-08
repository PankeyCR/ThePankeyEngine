
#include "ArrayList.h"
#include "List.h"

List<String> *testList;

void setup() {
  Serial.begin(9600);
  testList = new ArrayList<String,10>();

  testList->add("names");
  testList->add("node");
  testList->add("pankey");
  testList->add("test");
  testList->add("monkey");
  

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

  ArrayList<String,10> *Listt = new ArrayList<String,10>(testList);

  
  for(int x = 0; x < Listt->getPos(); x++){
    Serial.print("Total Size Available:  ");Serial.println(Listt->getSize());
    Serial.print("Total Size Used:  ");Serial.println(Listt->getPos());
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Object:  ");Serial.println(*Listt->getByPos(x));
  }
  
}
void loop() {
  

}
