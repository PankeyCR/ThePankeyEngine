
#include "ArrayList.h"

void setup() {
  Serial.begin(9600);
}
void loop() {
  ArrayList<String,10> testList;

  testList.addLValue("names");
  testList.addLValue("node");
  testList.addLValue("pankey");
  testList.addLValue("test");
  testList.addLValue("monkey");
  
  Serial.print("Total Size Available:  ");Serial.println(testList.getSize());
  Serial.print("Total Size Used:  ");Serial.println(testList.getPosition());

  for(Iterator i : testList){
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Object:  ");Serial.println(testList.getLValue(i));
  }

  testList.removeByLValue("monkey");

  Serial.print("Total Size Available:  ");Serial.println(testList.getSize());
  Serial.print("Total Size Used:  ");Serial.println(testList.getPosition());
  
  for(Iterator i : testList){
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Object:  ");Serial.println(testList.getLValue(i));
  }
}