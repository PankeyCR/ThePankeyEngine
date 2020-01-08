
#include "NetMap.h"
#include "Map.h"
#include "MemoryFree.h"

Map<int,float> *netmap;


void setup() {
  Serial.begin(9600);
  Serial.println(freeMemory());
  netmap = new NetMap(10);
  netmap->add(0, 0.5f);
  netmap->add(1, 0.6f);
  netmap->add(2, 0.7f);

  Serial.println(freeMemory());
  Serial.println("start");
  iterate(netmap){
    Serial.println(netmap->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  netmap->onDelete();
  Serial.println(freeMemory());
  netmap = new NetMap(10);
  netmap->add(0, 0.5f);
  netmap->add(1, 0.6f);
  netmap->add(2, 0.7f);

  Serial.println(freeMemory());
  Serial.println("start");
  iterate(netmap){
    Serial.println(netmap->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  netmap->onDelete();
  Serial.println(freeMemory());
}

void loop() {
}
