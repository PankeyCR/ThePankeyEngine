
#include "GameOn.hpp"
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "DefaultApplication.hpp"
#include "DebounceInterruptAction.hpp"

using namespace ame;

CreateComponentMacro(InterruptGameAction);
CreateComponentMacro(InterruptGameSystem);

Application* app;
GameObject* object;
GameManager<GameObject,GameOn>* manager;

void setup() {
  Serial.begin(9600);
  
  GameManager<GameObject,GameOn>* manager = new GameManager<GameObject,GameOn>();
  object = manager->createGameObject();

  app = new DefaultApplication();
  app->getStateManager()->add(manager);
  
  InterruptState* interrupt = app->getStateManager()->addState(new InterruptState());
  
  interrupt->createInterrupt(0);
  interrupt->setAction(0, new DebounceInterruptAction(A0));
  interrupt->addEvent(0, Interrupt_0);
  
  interrupt->createInterrupt(1);
  interrupt->setAction(1, new DebounceInterruptAction(A1));
  interrupt->addEvent(1, Interrupt_1);
  
  interrupt->createInterrupt(2);
  interrupt->setAction(2, new DebounceInterruptAction(A2));
  interrupt->addEvent(2, Interrupt_2);
  
  interrupt->createInterrupt(3);
  interrupt->setAction(3, new DebounceInterruptAction(A3));
  interrupt->addEvent(3, Interrupt_3);
  
  interrupt->createInterrupt(4);
  interrupt->setAction(4, new DebounceInterruptAction(A3));
  interrupt->addEvent(4, Interrupt_4);
  
  app->getStateManager()->addState(new GenericGameAction(Action, Class<InterruptGameAction>::getClass()));
  app->getStateManager()->addState(new GenericGameTimedAction(TimedAction, Class<InterruptGameTimedAction>::getClass()));
  app->getStateManager()->addState(new GenericGameSystem(System, Class<InterruptGameSystem>::getClass()));
}

void loop() {
  app->update();
}

void Interrupt_0(int interrupt, long millis, bool state){
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