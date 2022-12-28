
#include "GameOn.hpp"
#include "GameObject.hpp"
#include "GameManager.hpp"
#include "GenericGameAction.hpp"
#include "DefaultApplication.hpp"
#include "System.hpp"

using namespace ame;

Application* app;
GameObject* object;
GameManager<GameObject,GameOn>* manager;

float event_time = 0;

void setup() {
  Serial.begin(9600);

  app = new DefaultApplication();
  
  manager = app->getStateManager()->addState(new GameManager<GameObject,GameOn>());
  object = manager->createGameObject();
  
  auto game_system = app->getStateManager()->addState(new GenericGameSystem(Class<GameOn>::getClass()));
  game_system->addSystem(TestSystem);
}

void loop() {
  app->update();
  float tpc = app->getStateManager()->tpc();
  event_time += tpc;
  if(event_time > 5){
    manager->addComponentToGameObject(object, new TestComponent());
  }
  if(event_time > 10){
    event_time = 0;
    manager->deleteAllComponentsFromGameObject(object);
  }
}

void TestSystem(GameOn* component){
  System::console.println("TestSystem");
}



//