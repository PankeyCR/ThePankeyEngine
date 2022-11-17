
#ifndef CONFIGURATION_Chunk_hpp
#define CONFIGURATION_Chunk_hpp

	#if defined(DISABLE_cppObject) || defined(DISABLE_Memory) || defined(DISABLE_MemoryManager) || defined(DISABLE_MemoryPool) || defined(DISABLE_MemoryChunk) || defined(DISABLE_Chunk)
		#define Chunk_hpp

		#define IMPLEMENTATION_Chunk
		#define IMPLEMENTING_Chunk
	#endif
#endif

#ifndef Chunk_hpp
#define Chunk_hpp
#define Chunk_AVAILABLE

#define IMPLEMENTATION_Chunk IMPLEMENTATION(public Chunk)
#define IMPLEMENTING_Chunk IMPLEMENTING(public Chunk)

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