
#include "LinkedList.hpp"
#include "System.hpp"

using namespace ame;

LinkedList<int> list;

void setup() {
  Serial.begin(9600);

  list.add(5);
  list.add(10);
  list.add(15);
  list.add(20);
  list.add(25);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  LinkedListNode<int>* node = list.getStartNode();
  while(node != nullptr){
    int* f_pointer = node->get();
    if(f_pointer != nullptr){
      System::console.println(*f_pointer);
    }
    node = node->next;
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}