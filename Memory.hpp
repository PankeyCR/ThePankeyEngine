
#ifndef Memory_hpp
#define Memory_hpp
#define Memory_AVAILABLE

#include "MemoryManager.hpp"

namespace ame{
	
class cppObject;

struct Memory{
	static MemoryManager* manager;
	
	static cppObject* newObject(size_t a_size){
		if(manager == nullptr){
			return (cppObject*)malloc(a_size);
		}
		return manager->newObject(a_size);
	}
	
	static cppObject* newObject(cppObject* a_obj){
		if(manager == nullptr){
			return a_obj;
		}
		return manager->newObject(a_obj);
	}
	
	static void deleteObject(cppObject* a_obj){
		if(manager == nullptr){
			free(a_obj);
			return;
		}
		manager->deleteObject(a_obj);
	}
};

MemoryManager* Memory::manager = nullptr;

}

#endif