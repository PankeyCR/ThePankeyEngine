

#ifndef MemoryManager_hpp
#define MemoryManager_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryPool.hpp"
#include "cppObject.hpp"

namespace ame{
	
class MemoryManager{
public:
MemoryManager(){}
virtual ~MemoryManager(){}

virtual void initialize(long sizeofMemory){
	if(rawMemory == nullptr){
		free(rawMemory);
		memory_size = 0;
	}
	rawMemory = malloc(sizeof(char*) * ((sizeofMemory/4)-1));
	memory_size = sizeofMemory;
}
virtual void release(int sizeofMemory){
	free(rawMemory);
	rawMemory = nullptr;
	memory_size = 0;
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<MemoryManager>::classType;
}

virtual cppObjectClass* getClass(){
	return Class<MemoryManager>::classType;
}

virtual MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
	return nullptr;
}

virtual void deleteMemoryPool(MemoryPool* memorypool){}

virtual void initialize(){}

virtual void update(float tpc){}

protected:
void* rawMemory = nullptr;
long memory_size = 0;
};

struct Memory{
	static MemoryManager* manager;
};

}

ame::MemoryManager* ame::Memory::manager = nullptr;

#endif 
