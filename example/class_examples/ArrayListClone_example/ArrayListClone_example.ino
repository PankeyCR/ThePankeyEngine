
#include "ArrayList.h"
#include "List.h"
#include "MemoryFree.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(freeMemory());
  ArrayList<String,10> testList;

  testList.addLValue("names");
  testList.addLValue("node");
  testList.addLValue("pankey");
  testList.addLValue("test");
  testList.addLValue("monkey");
  
  Serial.println("testList Iterator");
  for(Iterator i : testList){
    Serial.println(testList.getLValue(i));
  }
  
  List<String>* cloneList = testList.clone();
  
  Serial.println("cloneList Iterator");
  for(Iterator i : *cloneList){
    Serial.println(cloneList->getLValue(i));
  }
  delete cloneList;
  Serial.println(freeMemory());
}