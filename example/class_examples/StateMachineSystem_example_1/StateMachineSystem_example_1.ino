
#include "MonkeyTime.hpp"
#include "StateMachineSystem.hpp"

using namespace ame;

void State_1(StateMachineSystem<float>* system, float* t, float tpc){
  *t += tpc;
  if(*t > 3.0f){
    *t = 0;
    system->nextState();
    Serial.println("nextState 2");
  }
}

void State_2(StateMachineSystem<float>* system, float* t, float tpc){
  *t += tpc;
  if(*t > 3.0f){
    *t = 0;
    system->nextState();
    Serial.println("nextState 3");
  }
}

void State_3(StateMachineSystem<float>* system, float* t, float tpc){
  *t += tpc;
  if(*t > 3.0f){
    *t = 0;
    system->setState("State_1");
    Serial.println("setState State_1");
  }
}

MonkeyTime timer;
StateMachineSystem<float> states;

void setup() {
  Serial.begin(9600);

  states.addState("State_1", State_1);
  states.addState("State_2", State_2);
  states.addState("State_3", State_3);
  
  states.setSystem(new float());
  states.setState("State_1");

  timer.run();
  timer.start();
}

void loop() {
  timer.computeTime(0.1f);
  float tpc = timer.getTPC();
  states.update(tpc);
}











//
