
#ifndef MemoryPool_hpp
#define MemoryPool_hpp
#define MemoryPool_AVAILABLE

#include "MemoryChunk.hpp"

namespace ame{
	
class cppObject;

class MemoryPool{
	public:
		MemoryPool(){}
		virtual ~MemoryPool(){}
	
		virtual cppObject* newObject(size_t a_size){
			return nullptr;
		}
		
		virtual cppObject* newObject(cppObject* a_obj){
			return nullptr;
		}
		
		virtual void deleteObject(cppObject* a_obj){}

		virtual MemoryPool* createMemoryPool(size_t poolsize, size_t chunksize){
			return nullptr;
		}

		virtual MemoryChunk* createMemoryChunk(int elements, size_t msz){
			return nullptr;
		}
		
		virtual void* newInstance(size_t i_size){
			return nullptr;
		}
		
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

		virtual void recycle(MemoryPool* varDeleted){
			
		}

		virtual void recycle(MemoryChunk* varDeleted){
			
		}

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
		size_t pool_size = 0;
		size_t chunk_size = 0;
		
		/* cppObjectList list; */
};

}

#endif