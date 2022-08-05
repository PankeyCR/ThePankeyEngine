
#include "ame_Enviroment.hpp"

#if defined(DISABLE_CharMemoryPool)
	#define CharMemoryPool_hpp
#endif

#ifndef CharMemoryPool_hpp
#define CharMemoryPool_hpp
#define CharMemoryPool_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryChunk.hpp"

#ifdef CharMemoryPoolLogApp
	#include "Logger.hpp"
	#define CharMemoryPoolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define CharMemoryPoolLog(name,method,type,mns) 
#endif

namespace ame{

class CharMemoryPool : public MemoryPool{
	public:
		CharMemoryPool(size_t poolsize, size_t chunksize) : MemoryPool(poolsize, chunksize){
			CharMemoryPoolLog("CharMemoryPool", "Constructor",  "println", "");
		}
		
		CharMemoryPool(size_t poolsize, size_t chunksize, void* p) : MemoryPool(poolsize, chunksize, p){
			CharMemoryPoolLog("CharMemoryPool", "Constructor",  "println", "");
		}
		virtual ~CharMemoryPool(){
			CharMemoryPoolLog("CharMemoryPool", "Destructor",  "println", "");
		}

		virtual void onRecycle(){
			
		}

		virtual void recycle(MemoryChunk* varDeleted){
			
		}

		virtual void recycle(void* varDeleted){
			
		}

		virtual void deleteMemoryPool(CharMemoryPool* CharMemoryPool){}

		virtual void deleteMemoryChunk(MemoryChunk* memorychunk){}

		virtual void initialize(){}

		virtual void update(float tpc){}

	protected:
		
};

}

#endif