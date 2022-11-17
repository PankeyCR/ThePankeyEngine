
#include "InterruptState.hpp"
#include "DebounceInterruptAction.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
  
  createInterruptEvent<1>(new DebounceInterruptAction(), Interrupt_0);
  attachInterruptEvent<1>(35);
}

void loop() {
}

void Interrupt_0(int interrupt, long millis, bool state){

}



//