
#ifndef CONFIGURATION_MemoryManager_hpp
#define CONFIGURATION_MemoryManager_hpp

	#if defined(DISABLE_cppObject) || defined(DISABLE_Memory) || defined(DISABLE_MemoryManager) || defined(DISABLE_MemoryPool) || defined(DISABLE_MemoryChunk) || defined(DISABLE_Chunk)
		#define MemoryManager_hpp

		#define IMPLEMENTATION_MemoryManager
		#define IMPLEMENTING_MemoryManager
	#endif
#endif

#ifndef MemoryManager_hpp
#define MemoryManager_hpp
#define MemoryManager_AVAILABLE

#define IMPLEMENTATION_MemoryManager IMPLEMENTATION(public MemoryManager)
#define IMPLEMENTING_MemoryManager IMPLEMENTING(public MemoryManager)

#include "MemoryPool.hpp"

namespace ame{
	
class MemoryManager : public MemoryPool{
	public:
		MemoryManager(){}
		virtual ~MemoryManager(){}
		
		virtual void initialize(long sizeofMemory, int a_reference_tracker){}
		virtual void release(){}

	protected:
};

}

#endif