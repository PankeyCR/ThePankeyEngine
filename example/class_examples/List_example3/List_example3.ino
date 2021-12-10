
#include "List.hpp"
#include "PList.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "Vector3f.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  //if you whant to have a variable of an element of the list, is better to do it like this,
  //is not absolutely necessary for the plist, linked list or primitive list, 
  //but to the array list it is because the pointer will be replace
  //ArrayList<Vector3f,5> list;
  //PList<Vector3f,5> list(true);
  //PrimitiveList<Vector3f> list;
  LinkedList<Vector3f> list;

  //the add method returns the pointer of variable on the list.
  //remember that on the arraylist the original point on the add method is deleted because the data type inside is a stack array (T values[size]), and the return value is the pointer inside of the list.
  //the PList, linked list, primitive list uses the same pointer that you use on the add method.
  //and all of the memory inside the list is going to be deleted when its out of scope(only if you create the list on the stack like this example, otherwise if you make the instance with new operator you have to delete the list, and by deleting the list you delete everything inside)
  Vector3f* position = list.addPointer(new Vector3f(0,1,2));
  Vector3f direction = *list.addPointer(new Vector3f(1,0,0));

  Serial.println(position->toString());
  Serial.println(direction.toString());
  Serial.println();
  Serial.println("////////////end");
  Serial.println(getRamSize());
}