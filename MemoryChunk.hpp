

#ifndef MemoryChunk_hpp
#define MemoryChunk_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Chunk.hpp"

namespace ame{

class MemoryChunk{
public:

MemoryChunk(int elements, size_t msz){
	m_elements = elements;
	m_sizet = msz + sizeof(Chunk);
}

MemoryChunk(int elements, size_t msz, bool createChunk){
	m_elements = elements;
	m_sizet = msz + sizeof(Chunk);
	if(createChunk){
		m_chunkMem = malloc(m_sizet * m_elements);
		m_chunkActualMem = m_chunkMem;
	}
}

virtual ~MemoryChunk(){
	if(m_chunkMem != nullptr){
		delete m_chunkMem;
	}
}

#if defined(ARDUINO_ARCH_AVR)
template<class T, size_t A , size_t S>
T* newInstance(){
	// if(m_chunkMem == nullptr){
		// return nullptr;
	// }
	// if(m_elements == 0){
		// return nullptr;
	// }
	// if(m_position >= m_elements){
		// return nullptr;
	// }
	// alignas(alignof(Chunk)) Chunk* chunk_1 = new(m_chunkActualMem) Chunk();
	// m_chunkActualMem = m_chunkActualMem + sizeof(Chunk);
	// alignas(A) T* m = new(m_chunkActualMem) T();
	// chunk_1->memorychunk = this;
	// chunk_1->var = m;
	// m_chunkActualMem = m_chunkActualMem + S;
	// m_position++;
	// return m;
	return nullptr;
}
#elif defined(ARDUINO_ARCH_SAM)
template<class T, size_t A , size_t S>
T* newInstance(){
	// if(m_chunkMem == nullptr){
		// return nullptr;
	// }
	// if(m_elements == 0){
		// return nullptr;
	// }
	// if(m_position >= m_elements){
		// return nullptr;
	// }
	// alignas(alignof(Chunk)) Chunk* chunk_1 = new(m_chunkActualMem) Chunk();
	// m_chunkActualMem = m_chunkActualMem + sizeof(Chunk);
	// alignas(A) T* m = new(m_chunkActualMem) T();
	// chunk_1->memorychunk = this;
	// chunk_1->var = m;
	// m_chunkActualMem = m_chunkActualMem + S;
	// m_position++;
	// return m;
	return nullptr;
}
#elif defined(ARDUINO_ARCH_ESP8266)
template<class T, size_t A , size_t S>
T* newInstance(){
	if(m_chunkMem == nullptr){
		return nullptr;
	}
	if(m_elements == 0){
		return nullptr;
	}
	if(m_position >= m_elements){
		return nullptr;
	}
	alignas(alignof(Chunk)) Chunk* chunk_1 = new(m_chunkActualMem) Chunk();
	m_chunkActualMem = m_chunkActualMem + sizeof(Chunk);
	alignas(A) T* m = new(m_chunkActualMem) T();
	chunk_1->memorychunk = this;
	chunk_1->var = m;
	m_chunkActualMem = m_chunkActualMem + S;
	m_position++;
	return m;
}
#elif defined(ARDUINO_ESP32_DEV)
template<class T, size_t A , size_t S>
T* newInstance(){
	if(m_chunkMem == nullptr){
		return nullptr;
	}
	if(m_elements == 0){
		return nullptr;
	}
	if(m_position >= m_elements){
		return nullptr;
	}
	alignas(alignof(Chunk)) Chunk* chunk_1 = new(m_chunkActualMem) Chunk();
	m_chunkActualMem = m_chunkActualMem + sizeof(Chunk);
	alignas(A) T* m = new(m_chunkActualMem) T();
	chunk_1->memorychunk = this;
	chunk_1->var = m;
	m_chunkActualMem = m_chunkActualMem + S;
	m_position++;
	return m;
}
#endif


static Chunk* getChunk(void* p){
	p = p - sizeof(Chunk);
	return (Chunk*)p;
}

virtual void setMemory(void* m_cM){
	m_chunkMem = m_cM;
	m_chunkActualMem = m_chunkMem;
}

virtual void* getMemory(){
	return m_chunkMem;
}

virtual bool hasMemory(){
	if(m_chunkMem == nullptr){
		return false;
	}
	return true;
}

virtual bool hasFreeSpace(){
	if(m_chunkMem == nullptr){
		return false;
	}
	if(m_chunkActualMem == nullptr){
		return false;
	}
	if(m_chunkActualMem >= (m_chunkMem + (m_sizet * m_elements))){
		return false;
	}
	return true;
}

virtual void clear(){
	m_position = 0;
	m_chunkActualMem = m_chunkMem;
}

virtual void* getPointer(size_t m_cM){
	if(m_chunkMem == nullptr){
		return nullptr;
	}
	void* m = ((m_chunkMem) + (m_cM));
	return m;
}

virtual int getPosition(){
	return m_position;
}

virtual MemoryChunk& operator=(const MemoryChunk& b){
	return *this;
}

virtual bool operator==(const MemoryChunk& b){
	return true;
}
virtual bool operator!=(const MemoryChunk& b){
	return true;
}
protected:
void* m_chunkMem = nullptr;
void* m_chunkActualMem = nullptr;

size_t m_sizet = 0;
int m_elements = 0;
int m_position = 0;

};

}

#endif 
