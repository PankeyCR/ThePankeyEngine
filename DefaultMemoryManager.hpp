
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef DefaultMemoryManager_hpp
#define DefaultMemoryManager_hpp

#include "MemoryManager.hpp"
#include "MemoryFree.hpp"

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

#endif
