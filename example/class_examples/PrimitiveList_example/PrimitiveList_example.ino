
#include "PrimitiveList.h"
#include "List.h"
#include "MemoryFree.h"

List<float> *flist;
List<int> *ilist;
List<double> *dlist;
List<bool> *blist;


void setup() {
  Serial.begin(9600);
  Serial.println(freeMemory());
  flist = new PrimitiveList<float>(3);
  Serial.println(freeMemory());
  flist->add(0.5f);
  flist->add(0.6f);
  flist->add(0.7f);
  flist->add(0.8f);
  flist->add(0.78f);
  flist->add(24.78f);
  flist->add(0.6f);
  flist->add(0.7f);
  flist->add(0.8f);
  flist->add(0.78f);
  flist->add(24.78f);
  flist->add(0.6f);
  flist->add(0.7f);
  flist->add(0.8f);
  flist->add(0.78f);
  flist->add(24.78f);
  flist->add(0.6f);
  flist->add(0.7f);
  flist->add(0.8f);
  flist->add(0.78f);
  flist->add(24.78f);

  Serial.println("start");
  Serial.println(freeMemory());
  iterate(flist){
    Serial.println(flist->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  delete flist;
  Serial.println(freeMemory());

  ///////////////////////////////////////////////////
  
  ilist = new PrimitiveList<int>(3);
  Serial.println(freeMemory());
  ilist->add(5);
  ilist->add(6);
  ilist->add(7);

  Serial.println("start");
  Serial.println(freeMemory());
  iterate(ilist){
    Serial.println(ilist->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  delete ilist;
  Serial.println(freeMemory());

  ///////////////////////////////////////////////////
  
  dlist = new PrimitiveList<double>(3);
  Serial.println(freeMemory());
  dlist->add(5.00d);
  dlist->add(6.01d);
  dlist->add(7.05d);

  Serial.println("start");
  Serial.println(freeMemory());
  iterate(dlist){
    Serial.println(dlist->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  delete dlist;
  Serial.println(freeMemory());

  ///////////////////////////////////////////////////
  
  blist = new PrimitiveList<bool>(3);
  Serial.println(freeMemory());
  blist->add(true);
  blist->add(false);
  blist->add(true);

  Serial.println("start");
  Serial.println(freeMemory());
  iterate(blist){
    Serial.println(blist->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  delete blist;
  Serial.println(freeMemory());
  
}

void loop() {
}
