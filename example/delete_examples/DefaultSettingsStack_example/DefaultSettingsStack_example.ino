
#include "DefaultSettings.h"
#include "AppSettings.h"
#include "MemoryFree.h"
#include "Vector2f.h"

bool once = true;

  int startmemory;
  int deletememory;
void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  DefaultSettings settings;  
  int instancememory = freeMemory();

  settings.addInt("not",9);
  settings.addInt("yes",8);
  settings.addInt("yes",8);
  settings.addInt("yes",8);
  settings.addCppObject("pika",new Vector2f());
  settings.addCppObject("pika",new Vector2f());
  int varmemory = freeMemory();
  
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("afterinstancememory ");Serial.println(instancememory);
  Serial.print("instancememory ");Serial.println(startmemory-instancememory);
  Serial.print("variables memory ");Serial.println(instancememory-varmemory);
  Serial.print("total memory used ");Serial.println(startmemory-varmemory);
}

void loop() {
  if(once){
    once = false;
    deletememory = freeMemory();
    Serial.print("deletememory ");Serial.println(deletememory);
    Serial.print("leak ");Serial.println(startmemory-deletememory);
  }
}
