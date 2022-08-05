
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ManegedMemory)
	#define ManegedMemory_hpp
#endif

#ifndef ManegedMemory_hpp
#define ManegedMemory_hpp
#define ManegedMemory_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

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