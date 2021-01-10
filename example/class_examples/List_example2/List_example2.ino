
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
  //you can do set, insert stuff on the list while iterating with the proper methods to do that
  //the arraylist doesnt return the proper value while removing on the iterator, due to the internal data type, but it will work the same after the iteration
  //remember that if you hace ownership over the values, you have to be carefull to delete on some moment the remove value or,
  //you can use the removeDelete(Iterator) method on the iterator to remove and delete that value
  //ArrayList<int,5> list;
  //PList<int,5> list(true);
  //PrimitiveList<int> list;
  LinkedList<int> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  Serial.println("inserting on list while iterating");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
    if(i.getIteration() == 1){
      list.insertLValue(i,5);
    }
    if(i.getIteration() == 3){
      list.insertLValue(i,9);
    }
  }
  
  Serial.println();
  Serial.println("list after inserting");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }

  //never remove a element on a list on precise position because youll remove everything from that point to the end, example
  //  for(Iterator i : list){
  //    if(i.getIteration() == 1){
  //      list.removeDelete(i);
  //    }
  //  }

  //the arraylist is the only one that works different from the other lists while removing on the iterator,
  //the arraylist wont return the proper value when removing
  Serial.println();
  Serial.println("removing on list while iterating");
  for(Iterator i = list.begin(); i != list.end(); i.next()){
    Serial.print("iteration: ");Serial.print(i.getIteration());
    Serial.print("  ->  value: ");Serial.println(list.getLValue(i));
    if(list.getLValue(i) == 5){
      list.removeDelete(i);
      Serial.println("removeDelete: 5");
    }
    if(list.getLValue(i) == 9){
      list.removeDelete(i);
      Serial.println("removeDelete: 9");
    }
  }
  
  Serial.println();
  Serial.println("list after removing");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  Serial.println("////////////end");
  Serial.println(freeMemory());
}