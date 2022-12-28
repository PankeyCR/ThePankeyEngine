
#include "InputState.hpp"

using namespace ame;

Input* input;

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

void setup() {
  Serial.begin(9600);

  auto inputEvents = createInputEvent<1>();
  
  inputEvents->input = new Input(26,false,false);//pin 26
  inputEvents->action = new InputActionMethod<Input>(runEvents);
  
  attachInputEvent<1>(26);//pin 26

  input = inputEvents->input;
}

void loop() {
  updateInputEvent<1>();
  
  Serial.print("state ");
  Serial.println(input->state);
}




//