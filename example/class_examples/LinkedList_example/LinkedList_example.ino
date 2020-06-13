
#include "LinkedList.h"

LinkedList<String> list;

void setup() {
  Serial.begin(9600);
  LinkedList<String> list;
  list.add("pika");
  list.add("chu");
  list.add("adventure");

  iterateV(list){
    Serial.println(list.getValue());
  }
}

void loop() {
}
