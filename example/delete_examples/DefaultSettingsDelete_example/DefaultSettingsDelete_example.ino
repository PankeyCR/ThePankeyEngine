
#include "DefaultSettings.h"
#include "AppSettings.h"
#include "Vector2f.h"
#include "MemoryFree.h"

AppSettings *settings;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  settings = new DefaultSettings();  
  instancememory = freeMemory();

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
  
  delete settings;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {
}
