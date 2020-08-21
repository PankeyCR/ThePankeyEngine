#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"

void setup() {
  Serial.begin(9600);
  //the set method works the same for every list, 
  //but the insert method look different from the arraylist and plist to the primitivelist and linked list, because of the fix size on the arraylist and the plist
  ArrayList<int,5> list;
  //PList<int,5> list;
  //PrimitiveList<int> list;
  //LinkedList<int> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  Serial.println("original list");
  iterateV(list){
    Serial.println(list.getValue());
  }
  //the set method will replace the value on that precise position of the list, and if the list has ownership over the values it will delete that previous value
  list.set(1,22);
  list.set(3,new int(2222));
  
  Serial.println("set list value on fix position(replacement)");
  iterateV(list){
    Serial.println(list.getValue());
  }
  //the insert method will put the new value on that position, and move all of the next values over
  //for the arraylist and the plist, is it moves the values over the limit size, they will disappear, and if the plist has ownership over the value, it will be deleted
  list.insert(1,33);
  list.insert(3,333);
  
  Serial.println("insert list value on fix position(moving the values)");
  iterateV(list){
    Serial.println(list.getValue());
  }
}

void loop() {
  
}
