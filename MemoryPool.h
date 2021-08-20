

#ifndef MemoryPool_h
#define MemoryPool_h

#include "Arduino.h"
#include "MemoryChunk.h"

namespace ame{

class MemoryPool{
public:
MemoryPool(size_t poolsize, size_t chunksize, void* p){
	initialMemory = p;
	poolMemory = p;
	chunkMemory = p + chunksize;
	pool_size = poolsize;
	chunk_size = chunksize;
	actualPoolMemory = poolMemory;
	actualChunkMemory = chunkMemory;
}
virtual ~MemoryPool(){}

#if defined(ARDUINO_ARCH_AVR)
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
#elif defined(ARDUINO_ARCH_SAM)
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
#elif defined(ARDUINO_ARCH_ESP8266)
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
#elif defined(ARDUINO_ESP32_DEV)
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
#endif

virtual void deleteMemoryPool(MemoryPool* memorypool){}

virtual void deleteMemoryChunk(MemoryChunk* memorychunk){}

virtual void initialize(){}

virtual void update(float tpc){}

protected:
void* initialMemory = nullptr;
void* poolMemory = nullptr;
void* chunkMemory = nullptr;
void* actualPoolMemory = nullptr;
void* actualChunkMemory = nullptr;
size_t pool_size;
size_t chunk_size;
};

}

#endif 
