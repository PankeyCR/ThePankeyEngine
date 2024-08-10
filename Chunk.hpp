
#ifndef Chunk_hpp
#define Chunk_hpp

namespace higgs{

class Chunk{
	public:
	Chunk(){}
	virtual ~Chunk(){}

	MemoryChunk* memorychunk = nullptr;
	void* var = nullptr;
};

}

#endif