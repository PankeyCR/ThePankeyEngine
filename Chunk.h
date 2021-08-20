

#ifndef Chunk_h
#define Chunk_h

namespace ame{

class MemoryChunk;

class Chunk{
public:
Chunk(){
}
virtual ~Chunk(){}

MemoryChunk* memorychunk = nullptr;
void* var = nullptr;
};

}

#endif 
