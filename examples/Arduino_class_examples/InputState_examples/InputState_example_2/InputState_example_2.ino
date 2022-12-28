
#include "InputState.hpp"

using namespace ame;

Input* input;

bool runEvents(int interrupt, long milli, Input* input){
  InputStateMethodLog(ame_Log_StartMethod, "runEvents", "println", "");
  bool pinState = digitalRead(input->pin);
  if(pinState == input->state){
    InputStateMethodLog(ame_Log_EndMethod, "runEvents", "println", "false");
    return false;
  }
  input->state = pinState;
  InputStateMethodLog(ame_Log_EndMethod, "runEvents", "println", "true");
  return true;
}

void setup() {
  Serial.begin(9600);

  input = new Input(26,false,false);
  
  auto inputEvents = createInputEvent<1>(input, runEvents);
  
  attachInputEvent<1>(26);//pin 26
}

void loop() {
  updateInputEvent<1>();
  
  Serial.print("state ");
  Serial.println(input->state);
}




//