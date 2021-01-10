
#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"
#include "Vector3f.h"
#include "MemoryFree.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  //another way of adding stuff to the list just putting the parameters of the constructor on the add method,
  //the list will make a new instance with the that parameters, it will make a compile error if you dont put a valid parameter
  //ArrayList<Vector3f,5> list;
  //PList<Vector3f,5> list(true);
  //PrimitiveList<Vector3f> list;
  LinkedList<Vector3f> list;
  
  list.addParameters(0,1,2);
  list.addParameters(5,6,7);
  list.addParameters();
  
  for(Iterator i : list){
    Serial.println(list.getLValue(i).toString());
  }
  Serial.println();
  Serial.println("////////////end");
  Serial.println(freeMemory());
}