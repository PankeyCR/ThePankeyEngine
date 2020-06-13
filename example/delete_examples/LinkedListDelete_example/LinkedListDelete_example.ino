
#include "LinkedList.h"
#include "MemoryFree.h"

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  LinkedList<String>* list = new LinkedList<String>();
  list->add("pika");
  list->add("chu");
  list->add(new String("no leaks"));
  instancememory = freeMemory();
  delete list;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
}

void loop() {
}
