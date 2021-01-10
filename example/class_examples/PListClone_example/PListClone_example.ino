
#include "PList.h"
#include "List.h"
#include "MemoryFree.h"

List<String> *testList;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  testList = new PList<String,10>(true);

  testList->addPointer(new String("names"));
  testList->addPointer(new String("node"));
  testList->addPointer(new String("pankey"));
  testList->addPointer(new String("test"));
  testList->addPointer(new String("monkey"));
  
  for(Iterator i : *testList){
    Serial.println(testList->getLValue(i));
  }
  
  List<String>* cloneList = testList->clone(true);
  delete testList;
                
  for(Iterator i : *cloneList){
    Serial.println(cloneList->getLValue(i));
  }
  delete cloneList;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}