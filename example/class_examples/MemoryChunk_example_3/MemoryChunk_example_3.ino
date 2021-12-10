
#include "MemoryRam.h"
#include "MemoryChunk.hpp"

using namespace ame;

MemoryChunk* memorychunk;

void setup(){  
  Serial.begin(9600);
  memorychunk = new MemoryChunk(10, sizeof(int), true);
}

void loop() {
  Serial.println("//////////////////////////start");
  Serial.println(getRamSize());

  if(!memorychunk->hasFreeSpace()){
    memorychunk->clear();
    Serial.println("memory full, cleaning");
  }

  int* a = memorychunk->newInstance<int,alignof(int),sizeof(int)>();
  *a = 6;
  
  Chunk* chunk = memorychunk->getChunk(a);
  
  Serial.print("int a = ");Serial.println(*a);
  Serial.print("memorychunk->getPosition() = ");Serial.println(memorychunk->getPosition());
  
  if(chunk->memorychunk == memorychunk){
    Serial.println("chunk->memorychunk == chunk");
  }
  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}
