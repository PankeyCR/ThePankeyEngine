
#include "ListEvent.h"
#include "Event.h"

using namespace ame;

Event<String>* event;

void setup() {
  Serial.begin(9600);
  event = new ListEvent<String>();
  event->add(&eventMethod);
  event->add(&eventMethod2);
  event->event("start");
  event->event("setup");  
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
