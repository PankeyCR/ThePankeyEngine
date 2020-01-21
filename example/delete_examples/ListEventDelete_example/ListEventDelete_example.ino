
#include "ListEvent.h"
#include "Event.h"
#include "MemoryFree.h"

Event<String>* event;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  event = new ListEvent<String>();
  event->add(&eventMethod);
  event->add(&eventMethod2);
  event->event("start");
  event->event("setup");
  instancememory = freeMemory();

  delete event;

  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {
}
void eventMethod(String nameEvent) {
  Serial.println(nameEvent);
}
void eventMethod2(String nameEvent) {
  if(nameEvent == "setup"){
    Serial.println("setup");
  }
}
