
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Memory) || defined(DISABLE_MemoryManagerState) || defined(DISABLE_MemoryManager) || defined(DISABLE_MemoryPool) || defined(DISABLE_MemoryChunk)
	#define MemoryPool_hpp 
	#define ame_HAS_NO_MEMORYMANGEMENT 
#endif

#ifndef MemoryPool_hpp
#define MemoryPool_hpp
#define MemoryPool_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MemoryChunk.hpp"

#ifdef MemoryPoolLogApp
	#include "Logger.hpp"
	#define MemoryPoolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MemoryPoolLog(name,method,type,mns) 
#endif

namespace ame{

class MemoryPool{
	public:
		MemoryPool(){}
		
		MemoryPool(size_t poolsize, size_t chunksize){
			MemoryPoolLog("MemoryPool", "Constructor",  "println", "");
			initialMemory = malloc(poolsize + chunksize);
			poolMemory = initialMemory;
			chunkMemory = initialMemory + poolsize;
			pool_size = poolsize;
			chunk_size = chunksize;
			actualPoolMemory = poolMemory;
			actualChunkMemory = chunkMemory;
		}
		
		MemoryPool(size_t poolsize, size_t chunksize, void* p){
			MemoryPoolLog("MemoryPool", "Constructor",  "println", "");
			initialMemory = p;
			poolMemory = initialMemory;
			chunkMemory = initialMemory + poolsize;
			pool_size = poolsize;
			chunk_size = chunksize;
			actualPoolMemory = poolMemory;
			actualChunkMemory = chunkMemory;
		}
		virtual ~MemoryPool(){
			MemoryPoolLog("MemoryPool", "Destructor",  "println", "");
			free(initialMemory);
		}

		#if defined(ame_GENERIC_ARDUINO)
		virtual MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			// if(initialMemory == nullptr){
				// return nullptr;
			// }
			// if((actualPoolMemory + poolsize + chunksize) >= (initialMemory + pool_size)){
				// return nullptr;
			// }
			// alignas(alignof(MemoryPool)) MemoryPool* pool_1 = new(actualPoolMemory) MemoryPool(poolsize,chunksize,actualPoolMemory + sizeof(MemoryPool));
			// actualPoolMemory = actualPoolMemory + sizeof(MemoryPool) + poolsize + chunksize;
			// return pool_1;
			return nullptr;
		}

		virtual MemoryChunk* createMemoryChunk(int elements, size_t msz){
			// alignas(alignof(MemoryChunk)) MemoryChunk* chunk = new(actualChunkMemory) MemoryChunk(elements, msz);
			// chunk->setMemory(((MemoryChunk*)actualChunkMemory)+1);
			// actualChunkMemory = actualChunkMemory + sizeof(MemoryChunk) + (msz * elements);
			// return chunk;
			return nullptr;
		}
		#elif defined(ame_ADAFRUIT_FEATHER_M0)
		virtual MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			// if(initialMemory == nullptr){
				// return nullptr;
			// }
			// if((actualPoolMemory + poolsize + chunksize) >= (initialMemory + pool_size)){
				// return nullptr;
			// }
			// alignas(alignof(MemoryPool)) MemoryPool* pool_1 = new(actualPoolMemory) MemoryPool(poolsize,chunksize,actualPoolMemory + sizeof(MemoryPool));
			// actualPoolMemory = actualPoolMemory + sizeof(MemoryPool) + poolsize + chunksize;
			// return pool_1;
			return nullptr;
		}

		virtual MemoryChunk* createMemoryChunk(int elements, size_t msz){
			// alignas(alignof(MemoryChunk)) MemoryChunk* chunk = new(actualChunkMemory) MemoryChunk(elements, msz);
			// chunk->setMemory(((MemoryChunk*)actualChunkMemory)+1);
			// actualChunkMemory = actualChunkMemory + sizeof(MemoryChunk) + (msz * elements);
			// return chunk;
			return nullptr;
		}
		#elif defined(ame_GENERIC_ESP8266)
		virtual MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			if(initialMemory == nullptr){
				return nullptr;
			}
			if((actualPoolMemory + poolsize + chunksize) >= (initialMemory + pool_size)){
				return nullptr;
			}
			alignas(alignof(MemoryPool)) MemoryPool* pool_1 = new(actualPoolMemory) MemoryPool(poolsize,chunksize,actualPoolMemory + sizeof(MemoryPool));
			actualPoolMemory = actualPoolMemory + sizeof(MemoryPool) + poolsize + chunksize;
			return pool_1;
		}

		virtual MemoryChunk* createMemoryChunk(int elements, size_t msz){
			alignas(alignof(MemoryChunk)) MemoryChunk* chunk = new(actualChunkMemory) MemoryChunk(elements, msz);
			chunk->setMemory(((MemoryChunk*)actualChunkMemory)+1);
			actualChunkMemory = actualChunkMemory + sizeof(MemoryChunk) + (msz * elements);
			return chunk;
		}
		
		#elif defined(ame_GENERIC_ESP32)
		virtual MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			if(initialMemory == nullptr){
				return nullptr;
			}
			if((actualPoolMemory + poolsize + chunksize) >= (initialMemory + pool_size)){
				return nullptr;
			}
			alignas(alignof(MemoryPool)) MemoryPool* pool_1 = new (actualPoolMemory) MemoryPool(poolsize,chunksize,actualPoolMemory + sizeof(MemoryPool));
			actualPoolMemory = actualPoolMemory + sizeof(MemoryPool) + poolsize + chunksize;
			return pool_1;
		}

		virtual MemoryChunk* createMemoryChunk(int elements, size_t msz){
			alignas(alignof(MemoryChunk)) MemoryChunk* chunk = new (actualChunkMemory) MemoryChunk(elements, msz);
			chunk->setMemory(((MemoryChunk*)actualChunkMemory)+1);
			actualChunkMemory = actualChunkMemory + sizeof(MemoryChunk) + (msz * elements);
			return chunk;
		}
		
		template<class T>
		T* newInstance(int i_size){
			// MemoryChunk* chunk_in = this->getRecycledMemoryChunk(i_size);
			// if(chunk_in != nullptr){
				// if(chunk_in->hasFreeSpace()){
					// return chunk_in->newInstance<T, alignof(T), sizeof(T)>(i_size);
				// }
			// }
			// MemoryChunk* chunk_in2 = this->createMemoryChunk(sizeof(T) * i_size);
			// return chunk_in2->newInstance<T, alignof(T), sizeof(T)>(i_size);
			return nullptr;
		}
		#endif
		
		virtual size_t getPoolSize(){
			return pool_size;
		}
		
		virtual size_t getChunkSize(){
			return chunk_size;
		}

		virtual MemoryChunk* createMemoryChunk(size_t msz){
			return nullptr;
		}

		virtual void onRecycle(){
			
		}

		virtual void recycle(MemoryChunk* varDeleted){
			
		}

		virtual void recycle(void* varDeleted){
			
		}

		virtual void deleteMemoryPool(MemoryPool* memorypool){}

		virtual void deleteMemoryChunk(MemoryChunk* memorychunk){}

		virtual void initialize(){}

		virtual void update(float tpc){}

		virtual void operator=(MemoryPool b){
			
		}
		virtual bool operator==(MemoryPool b){
				return false;
		}
		virtual bool operator!=(MemoryPool b){
				return false;
		}
		
	protected:
		void* initialMemory = nullptr;
		void* poolMemory = nullptr;
		void* chunkMemory = nullptr;
		void* actualPoolMemory = nullptr;
		void* actualChunkMemory = nullptr;
		size_t pool_size = 0;
		size_t chunk_size = 0;
};

}

#endif