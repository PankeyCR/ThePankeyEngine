#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"
#include "Vector3f.h"

void setup() {
  Serial.begin(9600);
  //another way of adding stuff to the list just putting the parameters of the constructor on the add method,
  //the list will make a new instance with the that parameters, it will make a compile error if you dont put a valid parameter
  ArrayList<Vector3f,5> list;
  //PList<Vector3f,5> list;
  //PrimitiveList<Vector3f> list;
  //LinkedList<Vector3f> list;
  
  list.add(0,1,2);
  list.add(5,6,7);
  list.add();
  
  iterateV(list){
    Serial.println(list.getValue().toString());
  }
}

void loop() {
  
}
