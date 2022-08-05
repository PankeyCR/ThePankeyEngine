
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Chunk)
	#define Chunk_hpp
#endif

#ifndef Chunk_hpp
#define Chunk_hpp
#define Chunk_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class MemoryChunk;

class Chunk{
public:
Chunk(){}
virtual ~Chunk(){}

MemoryChunk* memorychunk = nullptr;
void* var = nullptr;
};

}

#endif