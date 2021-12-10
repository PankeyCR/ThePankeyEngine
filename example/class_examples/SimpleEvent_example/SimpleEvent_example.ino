
#include "SimpleEvent.hpp"
#include "Event.hpp"
#include "MemoryRam.h"

using namespace ame;

Event<String>* event;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = getRamSize();
  event = new SimpleEvent<String>();
  event->add(&eventMethod);
  event->event("start");
  instancememory = getRamSize();

  delete event;

  deletememory = getRamSize();
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
