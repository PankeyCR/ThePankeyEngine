
#ifndef MemoryManager_hpp
#define MemoryManager_hpp
#define MemoryManager_AVAILABLE

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