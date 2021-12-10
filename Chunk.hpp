
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Chunk_hpp
#define Chunk_hpp

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

#endif 
