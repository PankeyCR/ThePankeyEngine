
#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"
#include "MemoryFree.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  ArrayList<int,15> list;
  //PList<int,15> list(true);
  //PrimitiveList<int> list;
  //LinkedList<int> list;

  //with the addPack method, you can add a secuence of any size(depending on the list class) 
  list.addPack(0,1,2,5,4);
  list.addPack(0,1,2,5,4,1,2,5,4);
  
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  Serial.println();
  Serial.println("////////////end");
  Serial.println(freeMemory());
}