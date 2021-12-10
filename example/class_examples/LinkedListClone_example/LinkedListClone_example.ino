
#include "LinkedList.hpp"
#include "List.hpp"
#include "MemoryRam.h"

using namespace ame;

LinkedList<String> *testList;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  testList = new LinkedList<String>();

  testList->addPointer(new String("names"));
  testList->addPointer(new String("node"));
  testList->addPointer(new String("pankey"));
  testList->addPointer(new String("test"));
  testList->addPointer(new String("monkey"));
  
  for(String& i : *testList){
    Serial.println(i);
  }
  
  List<String>* cloneList = testList->clone(true);
  delete testList;
  
  for(int x = 0; x < cloneList->getPosition(); x++){
    Serial.println(*cloneList->getByPosition(x));
  }
  delete cloneList;
  Serial.println("////////////end");
  Serial.println(getRamSize());
}