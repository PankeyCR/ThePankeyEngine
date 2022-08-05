
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
//  ArrayList<int,15> list;
//  PList<int,15> list(true);
//  PrimitiveList<int> list;
  LinkedList<int> list;

  list.add(1);
  list.add(6);
  list.add(7);
  list.add(2);
  list.add(6);
  list.add(3);
  list.add(6);
  list.add(4);
  list.add(6);
  list.add(7);
  list.add(5);
  list.add(6);
  
  for(int& i : list){
    Serial.println(i);
  }
  
  Serial.println("removeAll 6");

  list.removeAll(6);
  
  for(int& i : list){
    Serial.println(i);
  }
  
  Serial.println("removeFirst 7");

  list.removeFirst(7);
  
  for(int& i : list){
    Serial.println(i);
  }
  
  Serial.println("removeLast 7");

  list.removeLast(7);
  
  for(int& i : list){
    Serial.println(i);
  }
  
  Serial.println();
  Serial.println("////////////end");
  Serial.println(getRamSize());
}
