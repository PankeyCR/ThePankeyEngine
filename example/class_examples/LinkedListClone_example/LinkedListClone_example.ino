
#include "LinkedList.h"
#include "List.h"
#include "MemoryFree.h"

using namespace ame;

List<String> *testList;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  testList = new LinkedList<String>();

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