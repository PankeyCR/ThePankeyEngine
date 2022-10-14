
#include "List.hpp"
#include "PList.hpp"
#include "ArrayList.hpp"
#include "LinkedList.hpp"
#include "PrimitiveList.hpp"
#include "MemoryRam.h"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  ArrayList<int,15> list;
  //PList<int,15> list(true);
  //PrimitiveList<int> list;
  //LinkedList<int> list;

  //with the addPack method, you can add a secuence of any size(depending on the list class) 
  list.addPack(0,1,2,5,4);
  list.addPack(0,1,2,5,4,1,2,5,4);
  
  for(int& i : list){
    Serial.println(i);
  }
  Serial.println();
  Serial.println("////////////end");
  Serial.println(getRamSize());
}