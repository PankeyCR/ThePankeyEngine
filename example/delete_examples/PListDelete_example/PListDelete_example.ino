
#include "PList.h"
#include "List.h"
#include "MemoryFree.h"

List<String> *testList;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  testList = new PList<String,10>();

  testList->add(new String("names"));
  testList->add(new String("node"));
  testList->add(new String("pankey"));
  testList->add(new String("test"));
  testList->add(new String("monkey"));
  
  instancememory = freeMemory();
  
  testList->onDelete();
  delete testList;

  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);

  
}
void loop() {
  

}
