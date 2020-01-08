
#include "DefaultSettings.h"
#include "AppSettings.h"
#include "Vector2f.h"

DefaultSettings *settings;

void setup() {
  Serial.begin(9600);
  settings = new DefaultSettings();  

  settings->addInt("not",9);
  settings->addInt("yes",8);
  settings->addInt("yes",8);
  settings->addInt("yes",8);
  settings->addInt("yes",8);
  settings->addInt("yes",8);
  settings->addInt("yes",8);
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());
  settings->addCppObject("pika",new Vector2f());

  
  iterate(settings->intMap){
    Serial.println(settings->intMap->getValue());
  }
  
}

void loop() {
}
