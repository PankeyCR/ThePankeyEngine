
#include "DefaultSettings.hpp"
#include "AppSettings.hpp"
#include "Vector2f.hpp"
#include "Vector3f.hpp"

using namespace ame;

DefaultSettings *settings;

void setup() {
  Serial.begin(9600);
  settings = new DefaultSettings();  

  settings->addInt("speed",100);
  settings->addCppObject("direction",new Vector2f(1,0));
  settings->addCppObject("position",new Vector3f(1,2,3));
}

void loop() {
  int speed = settings->getInt("speed");
  Serial.println(speed);
  
  Vector2f* direction = (Vector2f*)settings->getCppObject("direction");
  Serial.println(direction->toNote());
  
  Vector3f* position = (Vector3f*)settings->getCppObject("position");
  Serial.println(position->toNote());
}