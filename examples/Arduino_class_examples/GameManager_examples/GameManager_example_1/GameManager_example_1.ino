
#include "GameOn.hpp"
#include "GameObject.hpp"
#include "GameManager.hpp"

#include "EventState.hpp"

using namespace ame;

CreateComponentMacro(TestGameAction);
CreateComponentMacro(TestGameTimedAction);
CreateComponentMacro(TestGameSystem);

Application* app;
GameObject* object;
GameManager<GameObject,GameOn>* manager;

EventState* events;

void setup() {
  Serial.begin(9600);

  events.addEvent(new TimeActivation(2), Event_1);
  events.addEvent(new TimeActivation(4), Event_2);
  events.addEvent(new TimeActivation(6), Event_3);
  events.addEvent(new TimeActivation(8), Event_4);
  events.addMetaEvent(new TimeActivation(10), Event_5);
  
  GameManager<GameObject,GameOn>* manager = new GameManager<GameObject,GameOn>();
  object = manager->createGameObject();

  app = new DefaultApplication();
  app->getStateManager()->add(manager);
  
  app->getStateManager()->addState(new GenericGameAction(Action, Class<TestGameAction>::getClass()));
  app->getStateManager()->addState(new GenericGameTimedAction(TimedAction, Class<TestGameTimedAction>::getClass()));
  app->getStateManager()->addState(new GenericGameSystem(System, Class<TestGameSystem>::getClass()));
}

void loop() {
  app->update();
  float tpc = app->getStateManager()->tpc();
  time += tpc;
}

void Event_1(){
  manager->addComponentToGameObject(object, new InterruptGameAction());
}

void Interrupt_1(int interrupt, long millis, bool state){
  manager->addComponentToGameObject(object, new InterruptGameTimedAction());
}

void Interrupt_2(int interrupt, long millis, bool state){
  manager->removeComponentFromGameObject(object, Class<InterruptGameTimedAction>::getClass());
}

void Interrupt_3(int interrupt, long millis, bool state){
  manager->addComponentToGameObject(object, new InterruptGameSystem());
}

void Interrupt_4(int interrupt, long millis, bool state){
  manager->removeComponentFromGameObject(object, Class<InterruptGameSystem>::getClass());
}

void Action(GameOn* component){
  System::console.println("Action");
}

void TimedAction(GameOn* component){
  System::console.println("TimedAction");
}

void System(GameOn* component, float tpc){
  System::console.println("System");
}



//