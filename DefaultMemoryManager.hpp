
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
#include "cppObjectList.hpp"

namespace ame{

class DefaultMemoryManager : public MemoryManager{
	public:		
		DefaultMemoryManager(int m_obj_size) : 
												m_objs(m_obj_size), 
												m_objs_remove(m_obj_size/2), 
												m_objs_recycle(m_obj_size/2){}
		DefaultMemoryManager() : 
								m_objs(1000), 
								m_objs_remove(500), 
								m_objs_recycle(500){}

		virtual ~DefaultMemoryManager(){}
	
		virtual cppObject* newObject(size_t a_size){
			cppObject* i_obj = m_objs.addPointer((cppObject*)malloc(a_size));
			return i_obj;
		}
		
		virtual cppObject* newObject(cppObject* a_obj){
			cppObject* i_obj = m_objs.addPointer(a_obj);
			return i_obj;
		}
		
		virtual void deleteObject(cppObject* a_obj){
			cppObject* i_obj = m_objs.removeByPointer(a_obj);
			m_objs_remove.addPointer(i_obj);
		}

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

		virtual void update(float tpc){
			m_time_remove += tpc;
			m_time_recycle += tpc;
			if(m_time_remove > m_time_limit_remove){
				
			}
			if(m_time_recycle > m_time_limit_recycle){
				
			}
		}

	protected:
		PrimitiveList<MemoryPool> m_pool;
		
		cppObjectList m_objs;
		cppObjectList m_objs_remove;
		cppObjectList m_objs_recycle;
		
		float m_time_remove = 0;
		float m_time_limit_remove = 1.5f;
		
		float m_time_recycle = 0;
		float m_time_limit_recycle = 1.5f;
};

}

#endif