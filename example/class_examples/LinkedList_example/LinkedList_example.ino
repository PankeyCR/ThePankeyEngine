
#include "LinkedList.hpp"
#include "MemoryRam.h"

using namespace ame;

LinkedList<String> list;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  
  LinkedList<String> list;
  list.add("pika");
  list.add("chu");
  list.add("adventure");

  for(String& i : list){
    Serial.println(i);
  }
  Serial.println("////////////end");
  Serial.println(getRamSize());
}