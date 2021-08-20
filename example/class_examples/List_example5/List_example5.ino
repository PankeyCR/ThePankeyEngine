
#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"
#include "MemoryFree.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(freeMemory());
  //the set method works the same for every list, 
  //but the insert method look different from the arraylist and plist to the primitivelist and linked list, because of the fix size on the arraylist and the plist
  //ArrayList<int,5> list;
  //PList<int,5> list(true);
  //PrimitiveList<int> list;
  LinkedList<int> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  Serial.println("original list");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  //the set method will replace the value on that precise position of the list, and if the list has ownership over the values it will delete that previous value
  list.setLValue(1,22);
  list.setPointer(3,new int(2222));
  
  Serial.println("set list value on fix position(replacement)");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  //the insert method will put the new value on that position, and move all of the next values over
  //for the arraylist and the plist, is it moves the values over the limit size, they will disappear, and if the plist has ownership over the value, it will be deleted
  list.insertLValue(1,33);
  list.insertLValue(3,333);
  
  Serial.println("insert list value on fix position(moving the values)");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  Serial.println();
  Serial.println("////////////end");
  Serial.println(freeMemory());
}