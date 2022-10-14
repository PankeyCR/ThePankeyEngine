
#include "List.hpp"
#include "PList.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  //when your adding stuff to any of this lists, they will work the same,
  //but with different mechanisms inside
  //ArrayList<int,5> list;
  //PList<int,5> list(true);//if you dont set true the contructors parameter, it wont manage the memory and have memory leak
  PrimitiveList<int> list;
  //LinkedList<int> list;
  
  list[0] = 1;
  list[1] = 11;
  list[2] = 111;
  list[3] = 1111;
  list[4] = 11111;

  //to add stuff to the list with the [] operator and use the iterator, you have to add stuff in order
  Serial.println("list after adding throught []");
  for(int& i : list){
    Serial.println(i);
  }

  //the arraylist wont delete delete any pointer, but it will make the list to reset, because its and stack array
  //the plist, linked list and the primitive list will delete the pointers only if they have onwership over the values it has
  //plist by default doesnt have ownership over the values but linked list and primitive list does has ownership
  list.resetDelete();
  
  list.addLValue(2);
  list.addLValue(22);
  list.addLValue(222);
  list.addLValue(2222);
  list.addLValue(22222);
  
  Serial.println("list after adding with the add(lvalue) method");
  for(int& i : list){
    Serial.println(i);
  }

  list.resetDelete();

  list.addPointer(new int(3));
  list.addPointer(new int(33));
  list.addPointer(new int(333));
  list.addPointer(new int(5));
  list.addPointer(new int(555));

  //the array list will asign the value of the pointer to the list and then it deletes that pointer, 
  //just to prevent any memory leak
  //for the plist, linked list and primitive list, the pointer added is the pointer saved on the list
  Serial.println("list after adding with the add(pointer) method");
  for(int& i : list){
    Serial.println(i);
  }
  Serial.println("////////////end");
  Serial.println(getRamSize());
}