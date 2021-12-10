
#include "MemoryRam.h"
#include "MemoryChunk.hpp"

using namespace ame;

MemoryChunk* memorychunk;

void setup(){  
  Serial.begin(9600);
}

void loop() {
  Serial.println("//////////////////////////start");
  Serial.println(getRamSize());
  
  memorychunk = new MemoryChunk(10, sizeof(int), true);

  int* a = memorychunk->newInstance<int,alignof(int),sizeof(int)>();
  *a = 6;

  int* b = memorychunk->newInstance<int,alignof(int),sizeof(int)>();
  *b = 15;

  void* p1 = memorychunk->getPointer(sizeof(Chunk));
  void* p2 = memorychunk->getPointer(sizeof(Chunk) + sizeof(int) + sizeof(Chunk));

  if(a == p1){
    Serial.println("a == p1");
  }
  if(b == p2){
    Serial.println("b == p2");
  }

  delete memorychunk;
  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}
