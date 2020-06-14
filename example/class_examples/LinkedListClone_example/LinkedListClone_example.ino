
#include "LinkedList.h"
#include "List.h"

List<String> *testList;

void setup() {
  Serial.begin(9600);
  testList = new LinkedList<String>();

  testList->add(new String("names"));
  testList->add(new String("node"));
  testList->add(new String("pankey"));
  testList->add(new String("test"));
  testList->add(new String("monkey"));
  
  iterate(testList){
    Serial.println(testList->getValue());
  }
  
  List<String>* cloneList = testList->clone();
  delete testList;//list can be deleted because the linkedlist creates new instances of the data,
                  //but be sure that the contructor of the class template has no parameters
                
  iterate(cloneList){
    Serial.println(cloneList->getValue());
  }
}

void loop() {}
