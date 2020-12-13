

#ifndef ManegedMemory_h
#define ManegedMemory_h

#include "MemoryManager.h"

template<class T> struct Memory{
	static MemoryManager* manager;
};
template<class T> MemoryManager* Memory<T>::manager = nullptr;

template<class T>
class ManegedMemory{
    public:		
		ManegedMemory(){}
		virtual ~ManegedMemory(){}
		
		void* operator new(size_t size){
				// return malloc(size);
			if(Memory<T>::manager == nullptr){
				return malloc(size);
			}
			return Memory<T>::manager->allocateMemory(size);
		}
		
		void operator delete(void* pointerToDelete){
				// free(pointerToDelete);
			if(Memory<T>::manager == nullptr){
				free((T*)pointerToDelete);
				return;
			}
			Memory<T>::manager->deleteMemory(pointerToDelete);
		}

		virtual void watchdog(){
			if(Memory<T>::manager != nullptr){
				Memory<T>::manager->watchdog(this);
			}
		}

		virtual void onRecycleMemory(){}

		virtual void onDeleteMemory(){}
		
	protected:
};


#endif 
