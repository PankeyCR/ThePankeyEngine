
#include "GameObject.h"
#include "PNeuron.h"
#include "MemoryFree.h"

GameObject* entity;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  
  entity = new PNeuron<5>("parent");
  entity->attach(new PNeuron<2>("arm_left"));
  entity->attach(new PNeuron<2>("arm_right"));
  entity->attach(new PNeuron<2>("leg_left"));
  entity->attach(new PNeuron<2>("leg_right"));
 
  instancememory = freeMemory();
  entity->onDelete();
  delete entity;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {

}
