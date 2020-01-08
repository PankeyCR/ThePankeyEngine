
#include "KVMap.h"
#include "Map.h"
#include "MemoryFree.h"

Map<String,int> *testMap;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  testMap = new KVMap<String,int,10>();
  instancememory = freeMemory();
  
  testMap->add("test", 15);
  testMap->add("a", 10);
  testMap->add("in", 40);
  testMap->add("monkey", 20);
  testMap->add("total", 50);
  testMap->add("engine", 30);
  testMap->add("go", 7);
  
  delete testMap;
  deletememory = freeMemory();
  
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}
void loop(){}
