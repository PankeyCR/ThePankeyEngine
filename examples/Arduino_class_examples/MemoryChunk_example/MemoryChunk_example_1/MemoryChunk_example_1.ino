
#include "MemoryRam.h"
#include "MemoryChunk.hpp"

using namespace ame;

void setup(){  
  Serial.begin(9600);
}

void loop() {
  Serial.println("//////////////////////////start");
  Serial.println(getRamSize());

  MemoryChunk* memorychunk = new MemoryChunk(10, sizeof(int), true);//true parameter to create automatic the memory on ram
//  memorychunk->setChunk(malloc(sizeof(int)*10));// if you set the last parameter on the MemoryChunk class to false, it wont create the chunk memory and youll have to create it manually
  
  int* a = memorychunk->newInstance<int,alignof(int),sizeof(int)>(1);
  *a = 6;
  
  Serial.print("int a = ");Serial.println(*a);

  delete memorychunk;
  
  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}
