
#include "MemoryRam.h"
#include "MemoryChunk.hpp"

using namespace ame;

void setup(){  
  Serial.begin(9600);
}

void loop() {
  Serial.println("//////////////////////////start");
  Serial.println(getRamSize());
  
  MemoryChunk* memorychunk = new MemoryChunk(10, sizeof(int), true);

  int* a = memorychunk->newInstance<int,alignof(int),sizeof(int)>();

  Chunk* chunk = memorychunk->getChunk(a);
  
  Serial.print("memorychunk: ");Serial.printf("%p\n", memorychunk);
  Serial.print("chunk: ");Serial.printf("%p\n", chunk);
  Serial.print("int a: ");Serial.printf("%p\n", a);
  Serial.print("chunk->memorychunk: ");Serial.printf("%p\n", chunk->memorychunk);
  Serial.print("chunk->var: ");Serial.printf("%p\n", chunk->var);

  if(chunk->memorychunk == memorychunk){
    Serial.println("chunk->memorychunk == chunk");
  }

  delete memorychunk;
  
  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}
