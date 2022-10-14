
#ifndef Chunk_hpp
#define Chunk_hpp
#define Chunk_AVAILABLE

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