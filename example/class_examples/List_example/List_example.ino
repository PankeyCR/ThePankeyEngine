#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"

void setup() {
  Serial.begin(9600);
  //when your adding stuff to any of this lists, they will work the same,
  //but with different mechanisms inside
  ArrayList<int,5> list;
  //PList<int,5> list;
  //PrimitiveList<int> list;
  //LinkedList<int> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  //to add stuff to the list with the [] operator and use the iterator, you have to add stuff in order
  Serial.println("list after adding throught []");
  iterateV(list){
    Serial.println(list.getValue());
  }

  //the arraylist wont delete delete any pointer, but it will make the list to reset, because its and stack array
  //the plist, linked list and the primitive list will delete the pointers only if they have onwership over the values it has
  //plist by default doesnt have ownership over the values but linked list and primitive list does has ownership
  list.resetDelete();
  
  list.add(2);
  list.add(22);
  list.add(222);
  list.add(2222);
  list.add(22222);
  
  Serial.println("list after adding with the add(lvalue) method");
  iterateV(list){
    Serial.println(list.getValue());
  }

  list.resetDelete();

  list.add(new int(3));
  list.add(new int(33));
  list.add(new int(333));
  list.add(new int(5));
  list.add(new int(555));

  //the array list will asign the value of the pointer to the list and then it deletes that pointer, 
  //just to prevent any memory leak
  //for the plist, linked list and primitive list, the pointer added is the pointer saved on the list
  Serial.println("list after adding with the add(pointer) method");
  iterateV(list){
    Serial.println(list.getValue());
  }
}

void loop() {
  
}
