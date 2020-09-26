

#include "GameManager.h"
#include "Application.h"
#include "SimpleApplication.h"
#include "TemperatureNTCRelay.h"
#include "NTC.h"
#include "TemperatureNTCSystem.h"
#include "TemperatureNTCRelaySystem.h"

Application* app;

void setup() {
  Serial.begin(9600);
  GameManager* manager = new GameManager();
  int entity = manager->createEntity();
  manager->addComponent(entity, new NTC(A4));
  manager->addComponent(entity, new TemperatureNTCRelay(46,40));

  app = new SimpleApplication<3,2>();
  app->getStateManager()->add(new TemperatureNTCSystem(manager));
  app->getStateManager()->add(new TemperatureNTCRelaySystem(manager));
}

void loop() {
  app->update();
}
