
#include "LinkedList.h"
#include "MemoryFree.h"

LinkedList<String> list;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  LinkedList<String> list;
  list.addLValue("pika");
  list.addLValue("chu");
  list.addLValue("adventure");

  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  Serial.println("////////////end");
  Serial.println(freeMemory());
}