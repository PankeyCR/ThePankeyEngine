
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
  
  memorychunk = new MemoryChunk(10, sizeof(char) * 5, true);

  char* a = memorychunk->newInstance<char,alignof(int),sizeof(char)>(5);
  *(a) = 'h';
  *(a+1) = 'o';
  *(a+2) = 'l';
  *(a+3) = 'a';
  *(a+4) = '\0';

  Serial.println(a);

  delete memorychunk;
  Serial.println("//////////////////////////end");
  Serial.println(getRamSize());
}
