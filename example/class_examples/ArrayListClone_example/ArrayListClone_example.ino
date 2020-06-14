
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
  
  iterate(testList){
    Serial.println(testList->getValue());
  }
  
  List<String>* cloneList = testList->clone();
  delete testList;//list can be deleted because the new list has new rvalues saved on it, 
                  //and ArrayList doesnt have ownership of the data stored on the list
  
  iterate(cloneList){
    Serial.println(cloneList->getValue());
  }
}

void loop() {}
