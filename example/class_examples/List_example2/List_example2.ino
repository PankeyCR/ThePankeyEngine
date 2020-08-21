#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"

void setup() {
  Serial.begin(9600);
  //you can do set, insert stuff on the list while iterating with the proper methods to do that
  //the arraylist doesnt return the proper value while removing on the iterator, due to the internal data type, but it will work the same after the iteration
  //remember that if you hace ownership over the values, you have to be carefull to delete on some moment the remove value or,
  //you can use the removeDelete() method on the iterator to remove and delete that value
  ArrayList<int,5> list;
  //PList<int,5> list;
  //PrimitiveList<int> list;
  //LinkedList<int> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  Serial.println("inserting on list while iterating");
  iterateV(list){
    Serial.println(list.getValue());
    if(list.getIteration() == 1){
      list.insert(5);
    }
    if(list.getIteration() == 3){
      list.insert(9);
    }
  }
  
  Serial.println();
  Serial.println("list after inserting");
  iterateV(list){
    Serial.println(list.getValue());
  }

  //never remove a element on a list on precise position because youll remove everything from that point to the end, example
  //  iterateV(list){
  //    if(list.getIteration() == 1){
  //      int pointer = *list.remove();
  //      Serial.print("removed: ");Serial.println(pointer);
  //    }
  //  }

  //the arraylist is the only one that works different from the other lists while removing on the iterator,
  //the arraylist wont return the proper value when removing
  Serial.println();
  Serial.println("removing on list while iterating");
  iterateV(list){
    Serial.print("value: ");Serial.print(list.getValue());
    Serial.print("   iteration: ");Serial.println(list.getIteration());
    if(list.getValue() == 5){
      int pointer = *list.remove();
      //int pointer = *list.removeDelete();
      Serial.print("removed: ");Serial.println(pointer);
    }
    if(list.getValue() == 9){
      int pointer = *list.remove();
      //int pointer = *list.removeDelete();
      Serial.print("removed: ");Serial.println(pointer);
    }
  }
  
  Serial.println();
  Serial.println("list after removing");
  iterateV(list){
    Serial.println(list.getValue());
  }
}

void loop() {
  
}
