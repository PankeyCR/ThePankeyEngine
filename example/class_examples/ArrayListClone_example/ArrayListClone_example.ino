
#include "ArrayList.hpp"
#include "List.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("///////////////////////////start");
  Serial.println(getRamSize());
  ArrayList<String,10> testList;

  testList.add("names");
  testList.add("node");
  testList.add("pankey");
  testList.add("test");
  testList.add("monkey");
  
  Serial.println("testList Iterator");
  for(String& i : testList){
    Serial.println(i);
  }
  
  List<String>* cloneList = testList.clone();
  
  Serial.println("cloneList Iterator");
  for(int x = 0; x < cloneList->getPosition(); x++){
    Serial.println(*cloneList->getByPosition(x));
  }
  delete cloneList;
  Serial.println(getRamSize());
  Serial.println("///////////////////////////end");
}