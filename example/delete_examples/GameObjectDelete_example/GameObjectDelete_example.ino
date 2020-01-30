
#include "GameObject.h"
#include "Entity.h"
#include "PNeuron.h"
#include "MemoryFree.h"

GameObject* entity;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  
  entity = new Entity("parent");
  entity->attach(new Entity("arm_left"));
  entity->attach(new Entity("arm_right"));
  entity->attach(new Entity("leg_left"));
  entity->attach(new Entity("leg_right"));
  
  instancememory = freeMemory();
  delete entity;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {

}
