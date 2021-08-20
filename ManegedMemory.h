

#ifndef ManegedMemory_h
#define ManegedMemory_h

#include "MemoryManager.h"

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
