
#include "PrimitiveMap.h"
#include "MemoryFree.h"

bool once = true;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  
  PrimitiveMap<String,String> map(1);
  instancememory = freeMemory();
  
  map.expandSize = 1;
  Serial.println(freeMemory());
  map.add("metadata","no data");
  map.add("superdata","at data");
  map.add("interdata","in data");
  map.add("fowarddata","plus data");
  
  Serial.println(freeMemory());
  Serial.println("start");
  
  iterateV(map){
    Serial.println(map.getIteration());
    Serial.println(map.getKey());
    Serial.println(map.getValue());
  }
  
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  
}

void loop() {
  if(once){
    once = false;
    deletememory = freeMemory();
    Serial.println(freeMemory());
    Serial.print("delete ");Serial.println(startmemory-deletememory);
  }
}
