
#include "PrimitiveList.h"
#include "List.h"
#include "MemoryFree.h"

List<String> *flist;

void setup() {
  Serial.begin(9600);
  Serial.println(freeMemory());
  flist = new PrimitiveList<String>(3);
  Serial.println(freeMemory());
  flist->add("a happy");
  flist->add("b happy");
  flist->add("c happy");
  flist->add("d happy");
  flist->add("e happy");
  Serial.println(freeMemory());
  //flist->remove("e happy");//this can make a memory leak
  flist->removeDelete("b happy");//perfect

  iterate(flist){
    Serial.println(flist->getValue());
  }
  delete flist;
  
  Serial.println(freeMemory());
}

void loop() {
}
