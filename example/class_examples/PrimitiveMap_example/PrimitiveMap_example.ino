
#include "PrimitiveMap.h"
#include "MemoryFree.h"

using namespace ame;

Map<String,String> *mapp;

void setup() {
  Serial.begin(9600);
  int startmemory = freeMemory();
  
  mapp = new PrimitiveMap<String,String>(1); 
  int instancememory = freeMemory();
  //mapp->expandSize = 1;
  mapp->add("metadata","no data");
  mapp->add("superdata","at data");
  mapp->add("interdata","in data");
  mapp->add("fowarddata","plus data");
  
  int varmemory = freeMemory();
  /*
  iterate(mapp){
    Serial.println(mapp->getIteration());
    Serial.println(mapp->getKey());
    Serial.println(mapp->getValue());
  }*/
  delete mapp;
  int deletememory = freeMemory();

  
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("afterinstancememory ");Serial.println(instancememory);
  Serial.print("deletememory ");Serial.println(deletememory);
  Serial.print("instancememory ");Serial.println(startmemory-instancememory);
  Serial.print("variables memory ");Serial.println(instancememory-varmemory);
  Serial.print("total memory used ");Serial.println(startmemory-varmemory);
  Serial.print("leak ");Serial.println(startmemory-deletememory);
}

void loop() {
}
