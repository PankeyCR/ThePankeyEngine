
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Memory) || defined(DISABLE_MemoryManagerState) || defined(DISABLE_MemoryManager) || defined(DISABLE_MemoryPool) || defined(DISABLE_MemoryChunk)
	#define MemoryManager_hpp
#endif

#ifndef MemoryManager_hpp
#define MemoryManager_hpp
#define MemoryManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryPool.hpp"

namespace ame{
	
class MemoryManager{
	public:
		MemoryManager(){}
		virtual ~MemoryManager(){}

		virtual void initialize(long sizeofMemory){
			if(rawMemory != nullptr){
				free(rawMemory);
				memory_size = 0;
			}
			rawMemory = malloc(sizeof(char*) * ((sizeofMemory/4)-1));
			actualMemory = rawMemory;
			memory_size = sizeofMemory;
		}
		virtual void release(int sizeofMemory){
			free(rawMemory);
			rawMemory = nullptr;
			actualMemory = nullptr;
			memory_size = 0;
		}

		#ifdef ame_GENERIC_ESP32
		template<class T>
		MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			MemoryPool* pool_in = this->getRecycledMemoryPool();
			if(pool_in != nullptr){
				return pool_in;
			}
			void* pool_memory = actualMemory;
			void* in_memory = actualMemory + sizeof(T);
			actualMemory = in_memory + poolsize + chunksize;
			return new (pool_memory) T(poolsize, chunksize, in_memory);
		}
		#endif

		#ifdef ame_ADAFRUIT_FEATHER_M0
		template<class T>
		MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			return nullptr;
		}
		#endif

		virtual MemoryPool* getRecycledMemoryPool(){
			return nullptr;
		}


		virtual void recycle(MemoryPool* memorypool){}

		virtual void initialize(){}

		virtual void update(float tpc){}

	protected:
		void* rawMemory = nullptr;
		void* actualMemory = nullptr;
		long memory_size = 0;
};

}

#endif