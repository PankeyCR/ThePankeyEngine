
#include "NetVList.h"
#include "List.h"
#include "MemoryFree.h"

List<float> *netlist;

void setup() {
  Serial.begin(9600);
  Serial.println(freeMemory());
  netlist = new NetVList<5>();
  netlist->add(0.5f);
  netlist->add(0.6f);
  netlist->add(0.7f);

  Serial.println(freeMemory());
  Serial.println("start");
  iterate(netlist){
    Serial.println(netlist->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  netlist->onDelete();
  Serial.println(freeMemory());
  delete netlist;
  Serial.println(freeMemory());
  netlist = new NetVList<5>();
  netlist->add(0.5f);
  netlist->add(0.6f);
  netlist->add(0.7f);

  Serial.println(freeMemory());
  Serial.println("start");
  iterate(netlist){
    Serial.println(netlist->getValue());
  }
  Serial.println("end");
  Serial.println(freeMemory());
  netlist->onDelete();
  Serial.println(freeMemory());
  delete netlist;
  Serial.println(freeMemory());
}

void loop() {
}
