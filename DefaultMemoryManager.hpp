
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultMemoryManager)
	#define DefaultMemoryManager_hpp
#endif

#ifndef DefaultMemoryManager_hpp
#define DefaultMemoryManager_hpp
#define DefaultMemoryManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryManager.hpp"
#include "MemoryPool.hpp"
#include "PrimitiveList.hpp"

namespace ame{

class DefaultMemoryManager : public MemoryManager{
public:		
	DefaultMemoryManager(int size_m) : pool_m(size_m){}
	DefaultMemoryManager() : pool_m(20){}

	virtual ~DefaultMemoryManager(){}

	virtual MemoryPool* getRecycledMemoryPool(){
		
		return nullptr;
	}

	virtual void recycle(MemoryPool* memorypool){
		pool_m.addPointer(memorypool);
		memorypool->onRecycle();
	}

	virtual void initialize(){

	}

	void update(float tpc){
		
	}

	protected:
		PrimitiveList<MemoryPool> pool_m;
};

}

#endif