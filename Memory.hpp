
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Memory) || defined(DISABLE_MemoryManagerState) || defined(DISABLE_MemoryManager) || defined(DISABLE_MemoryPool) || defined(DISABLE_MemoryChunk)
	#define Memory_hpp
	#define ame_HAS_NO_MEMORYMANGEMENT 
#endif

#ifndef Memory_hpp
#define Memory_hpp
#define Memory_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryManager.hpp"

namespace ame{

struct Memory{
	static MemoryManager* manager;
};

MemoryManager* Memory::manager = nullptr;

}

#endif