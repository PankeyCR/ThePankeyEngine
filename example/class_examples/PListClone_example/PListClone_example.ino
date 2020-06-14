
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
  
  iterate(testList){
    Serial.println(testList->getValue());
  }
  
  List<String>* cloneList = testList->clone();
  delete testList;//list can be deleted because PList doesnt have ownership of the data stored on the list
                
  iterate(cloneList){
    Serial.println(cloneList->getValue());
  }

  cloneList->onDelete();//but remember that PList doesnt have ownership over the data stored, 
                        //and if you whant to delete the pointers, you have to call onDelete method
}

void loop() {}
