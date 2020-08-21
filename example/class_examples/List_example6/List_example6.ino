#include "List.h"
#include "PList.h"
#include "ArrayList.h"
#include "LinkedList.h"
#include "PrimitiveList.h"

//when to use one type of list over another

//the best list are the primitive list and the linked list, because they grow dynamically,
//but they are very diffenrent by disign

//the arraylist and the plist are similar in a way that they have a fix array size, 
//but the arraylist holds lvalue variables and the plist holds pointers

//the primitive list
//pros
//is consumes less memory than the linked list
//easier to manipulate internally

//cons
//every time it grows dynamically, creates a new pointer array and then moves the old pointers to
//the new array, this consumes a lot of memory is the list is very large

//the linked list
//pros
//when it grows dynamically, it does it verry smuthly with out consuming extra memory for a moment
//its not made with and array, so its better when the memory is largely consume

//cons 
//the overall memory consumtion is larger then the primitive list



void setup() {
  Serial.begin(9600);
  Serial.println("a large example will be added eventually to show the best way to use them");
}

void loop() {
  
}
