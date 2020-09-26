#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"

void setup() {
  Serial.begin(9600);
  //ArrayList<int,5> list;
  //PList<int,5> list;
  //PrimitiveList<int> list;
  LinkedList<int> list;

  //with the addPack method, you can add a secuence of any size(depending on the list class) 
  list.addPack(0,1,2,5,4);
  list.addPack(0,1,2,5,4,1,2,5,4);
  
  iterateV(list){
    Serial.println(list.getValue());
  }
}

void loop() {
  
}
