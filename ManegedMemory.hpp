
#ifndef ManegedMemory_hpp
#define ManegedMemory_hpp

#include "MemoryManager.hpp"

namespace ame{

class ManegedMemory{
    public:
		ManegedMemory(){}
		virtual ~ManegedMemory(){}
		
		void* operator new(size_t size){
			if(Memory::manager == nullptr){
				return malloc(size);
			}
			return Memory::manager->allocateMemory(size);
		}
		
		void operator delete(void* pointerToDelete){
			if(Memory::manager == nullptr){
				free(pointerToDelete);
				return;
			}
			Memory::manager->deleteMemory(pointerToDelete);
		}

		virtual void onRecycleMemory(){}

		virtual void onDeleteMemory(){}
		
	protected:
};

}

#endif 
