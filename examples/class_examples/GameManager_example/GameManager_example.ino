

#include "GameManager.h"
#include "Application.h"
#include "DefaultApplication.h"
#include "NTCRelay.h"
#include "NTC.h"
#include "TemperatureNTCSystem.h"
#include "TemperatureNTCRelaySystem.h"

Application* app;

void setup() {
  Serial.begin(9600);
  GameManager* manager = new GameManager();
  int entity = manager->createEntity();
  manager->addComponent(entity, new NTC(A4));
  manager->addComponent(entity, new NTCRelay(46,40));

  app = new DefaultApplication();
  app->getStateManager()->add(manager);//gamemanager has to be added firts
  app->getStateManager()->add(new TemperatureNTCSystem());
  app->getStateManager()->add(new TemperatureNTCRelaySystem());
}

void loop() {
  app->update();
}
