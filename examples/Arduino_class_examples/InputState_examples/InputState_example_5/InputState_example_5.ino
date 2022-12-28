
#include "InputState.hpp"
#include "DebounceInput.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  
  auto inputEvents = createInputEvent<1,DebounceInput>(new DebounceInput(100,26,false,false), DebounceInputAction);
  inputEvents->events.add(event);
  
  attachInputEvent<1>(26);
}

void loop() {
  updateInputEvent<1,DebounceInput>();
}

void event(int interrupt, long milli, bool state){
  Serial.println("Event");
}




//