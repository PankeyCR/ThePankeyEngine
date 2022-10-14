
#ifndef Chunk_hpp
#define Chunk_hpp
#define Chunk_AVAILABLE

namespace ame{

class Chunk{
	public:
	Chunk(){}
	virtual ~Chunk(){}

	MemoryChunk* memorychunk = nullptr;
	void* var = nullptr;
};

}

#endif