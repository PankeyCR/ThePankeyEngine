
#include "DefaultSettings.h"
#include "AppSettings.h"
#include "Vector2f.h"
#include "GameManager.h"

DefaultSettings *settings;

void setup() {
  Serial.begin(9600);
  settings = new DefaultSettings();  

  settings->addInt("speed",100);
  settings->addCppObject("direction",new Vector2f(1,0));
  settings->addCppObject("GameManager",new GameManager());

  int speed = settings->getInt("speed");
  Serial.println(speed);
  
  Vector2f* direction = (Vector2f*)settings->getCppObject("direction");
  Serial.println(direction->toString());
  
  GameManager* manager = (GameManager*)settings->getCppObject("GameManager");
  Serial.println(manager->getClassName());
}

void loop() {
}