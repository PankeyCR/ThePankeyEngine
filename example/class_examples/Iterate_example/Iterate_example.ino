
#include "ArrayList.h"
#include "List.h"

List<int> *list;

void setup() {
  Serial.begin(9600);
  list = new ArrayList<int>();
  list->add(1);
  list->add(2);
  list->add(3);
  list->add(4);
  
  iterate(list){
    Serial.println(list->getValue());
  }
  
  iterate(list) fun(&funtionToIterate)
  
  iterate(list){
    funtionToIterate();
  }
  
}

void funtionToIterate(){
  Serial.println(list->getValue());
}

void loop(){}
