
#include "MonkeyTime.hpp"
#include "ClassStateMachineSystem.hpp"

using namespace ame;

class State_1 : public MachineState<float>{
  public:
  State_1(){}
  virtual ~State_1(){}
  virtual void update(ClassStateMachineSystem<float>* system, float* t, float tpc){
    *t += tpc;
    if(*t > 3.0f){
      *t = 0;
      system->nextState();
      Serial.println("nextState 2");
    }
  }
};

class State_2 : public MachineState<float>{
  public:
  State_2(){}
  virtual ~State_2(){}
  virtual void update(ClassStateMachineSystem<float>* system, float* t, float tpc){
    *t += tpc;
    if(*t > 3.0f){
      *t = 0;
      system->nextState();
      Serial.println("nextState 3");
    }
  }
};

class State_3 : public MachineState<float>{
  public:
  State_3(){}
  virtual ~State_3(){}
  virtual void update(ClassStateMachineSystem<float>* system, float* t, float tpc){
    *t += tpc;
    if(*t > 3.0f){
      *t = 0;
      system->setState("State_1");
      Serial.println("restart");
    }
  }
};

MonkeyTime timer;
ClassStateMachineSystem<float> states;

void setup() {
  Serial.begin(9600);

  states.addState("State_1", new State_1());
  states.addState("State_2", new State_2());
  states.addState("State_3", new State_3());
  
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
