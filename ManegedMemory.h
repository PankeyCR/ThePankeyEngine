

#ifndef ManegedMemory_h
#define ManegedMemory_h

#include "MemoryManager.h"

template<class T> struct Memory{
	static MemoryManager<T>* manager;
	static size_t objSize_t;
	template<class... args>
	static T* createMemory(bool maneged,args... x){
		T* t = new T(x...);
		if(manager != nullptr && !maneged){
			manager->removeMemory(t);
		}
		return t;
	}
	static void addMemory(T* t){
		if(manager != nullptr){
			manager->addMemory(t);
		}
	}
	static void removeMemory(T* t){
		if(manager != nullptr){
			manager->removeMemory(t);
		}
	}
	static void containMemory(T* t){
		if(manager != nullptr){
			manager->containMemory(t);
		}
	}
};
template<class T> MemoryManager<T>* Memory<T>::manager = nullptr;
template<class T> size_t Memory<T>::objSize_t;

template<class T>
class ManegedMemory{
    public:		
		ManegedMemory(){}
		virtual ~ManegedMemory(){}
		
		void* operator new(size_t size){
			Memory<T>::objSize_t = size;
			if(Memory<T>::manager == nullptr){
				return malloc(size);
			}
			return Memory<T>::manager->allocateMemory(size);
		}
		
		void operator delete(void* pointerToDelete){
			if(Memory<T>::manager == nullptr){
				free((T*)pointerToDelete);
				return;
			}
			Memory<T>::manager->deleteMemory(pointerToDelete,Memory<T>::objSize_t);
		}

		virtual void watchdog(){
			if(Memory<T>::manager != nullptr){
				Memory<T>::manager->watchdog(this);
			}
		}
		virtual size_t getsize_t(){
			return Memory<T>::objSize_t;
		}

		virtual void onRecycleMemory(){}

		virtual void onDeleteMemory(){}
		
	protected:
};


#endif 
