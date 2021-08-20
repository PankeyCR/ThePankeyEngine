
#ifndef DefaultMemoryManager_h
#define DefaultMemoryManager_h

#include "MemoryManager.h"
#include "MemoryFree.h"

namespace ame{

class DefaultMemoryManager : public MemoryManager{
public:		
DefaultMemoryManager(){
	
}

virtual ~DefaultMemoryManager(){
	
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<DefaultMemoryManager>::classType || MemoryManager::instanceof(cls);
}

virtual cppObjectClass* getClass(){
	return Class<DefaultMemoryManager>::classType;
}

virtual void initialize(){

}

void update(float tpc){
	
}

protected:
};

}


#endif