
#include "InputState.hpp"

using namespace ame;

bool runEvents(int interrupt, long milli, Input* input){
  InputStateMethodLog(ame_Log_StartMethod, "runEvents", "println", "");
  bool pinState = digitalRead(input->pin);
  if(pinState == input->state){
    InputStateMethodLog(ame_Log_EndMethod, "runEvents", "println", "");
    return false;
  }
  input->state = pinState;
  InputStateMethodLog(ame_Log_EndMethod, "runEvents", "println", "");
  return true;
}

void event(int interrupt, long milli, bool state){
  Serial.println("Event");
}

void setup() {
  Serial.begin(9600);

  auto inputEvents = createInputEvent<1>();
  
  inputEvents->input = new Input(26,false,false);
  inputEvents->action = new InputActionMethod<Input>(runEvents);
  inputEvents->events.add(event);
  
  attachInputEvent<1>(26);
}

void loop() {
  updateInputEvent<1>();
}




//