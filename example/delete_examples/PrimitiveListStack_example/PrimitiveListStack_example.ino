
#include "PrimitiveList.h"
#include "List.h"
#include "MemoryFree.h"

bool once = true;

void setup() {
  Serial.begin(9600);
  Serial.println(freeMemory());
  PrimitiveList<float> flist(3);
  flist.add(0.5f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);
  flist.add(0.6f);
  flist.add(0.7f);
  flist.add(0.8f);
  flist.add(0.78f);

  iterateV(flist){
    Serial.println(flist.getValue());
  }

  ///////////////////////////////////////////////////
  
  //ilist = PrimitiveList<int>(3);
  PrimitiveList<int> ilist(3);
  ilist.add(5);
  ilist.add(6);
  ilist.add(7);
  ilist.add(5);
  ilist.add(6);
  ilist.add(7);
  ilist.add(5);
  ilist.add(6);
  ilist.add(7);
  ilist.add(5);
  ilist.add(6);
  ilist.add(7);
  ilist.add(5);
  ilist.add(6);
  ilist.add(7);
  ilist.add(5);
  ilist.add(6);
  ilist.add(7);
  iterateV(ilist){
    Serial.println(ilist.getValue());
  }
  
  Serial.println(freeMemory());
}

void loop() {
  if(once){
    once = false;
    Serial.println(freeMemory());
  }
}
