
#include "PList.h"
#include "List.h"
#include "Iterator.h"
#include "MemoryFree.h"

using namespace ame;

List<String> *testList;

void setup() {
  Serial.begin(9600);
}
void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  //set true to have ownership of the memory so you could delete everything without memory leake
  testList = new PList<String,10>(true);

  testList->addPointer(new String("names"));
  testList->addPointer(new String("node"));
  testList->addPointer(new String("pankey"));
  testList->addPointer(new String("test"));
  testList->addPointer(new String("monkey"));
  

  for(int x = 0; x < testList->getPosition(); x++){
    Serial.print("Total Size Available:  ");Serial.println(testList->getSize());
    Serial.print("Total Size Used:  ");Serial.println(testList->getPosition());
    Serial.print("Actual Position:  ");Serial.println(x);
    Serial.print("Actual Object:  ");Serial.println(*testList->getByPosition(x));
  }

  testList->removeDeleteByLValue("monkey");


  for(Iterator i : *testList){
    Serial.print("Total Size Available:  ");Serial.println(testList->getSize());
    Serial.print("Total Size Used:  ");Serial.println(testList->getPosition());
    Serial.print("Actual Position:  ");Serial.println(i.getIteration());
    Serial.print("Actual Object:  ");Serial.println(testList->getLValue(i));
  }
  delete testList;
  Serial.println("////////////end");
  Serial.println(freeMemory());
}