
#include "Iterator.h"
#include "ArrayList.h"

ArrayList<int,10> list;

void setup() {
  Serial.begin(9600);
  list.addLValue(1);
  list.addLValue(2);
  list.addLValue(3);
  list.addLValue(4);
}

void loop(){
  Serial.println("///////////////start");
  for(Iterator i : list){
    Serial.println(list.getLValue(i));
  }
  Serial.println("///////////////end");
}