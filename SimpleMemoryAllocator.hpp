
#ifndef SimpleMemoryAllocator_hpp
	#define SimpleMemoryAllocator_hpp

	#include "MemoryAllocator.hpp"

    #ifdef SimpleMemoryAllocator_LogApp
        #include "pankey_Logger.hpp"
        #define SimpleMemoryAllocatorLog(location,method,type,mns) pankey_Log(nullptr,location,"SimpleMemoryAllocator",method,type,mns)
    #else
        #define SimpleMemoryAllocatorLog(location,method,type,mns)
    #endif

	namespace pankey{

		template<class T>
		class SimpleMemoryAllocator : public MemoryAllocator{
			public:
				SimpleMemoryAllocator(){
					m_managed = true;
				}
				SimpleMemoryAllocator(T* a_pointer){
					m_pointer = a_pointer;
					m_managed = true;
				}
				virtual ~SimpleMemoryAllocator(){}

				virtual void* create(pointer_size a_size){
                    SimpleMemoryAllocatorLog(pankey_Log_StartMethod, "create", "println","");
					if(m_pointer == nullptr){
						m_pointer = new T();
					}
                    SimpleMemoryAllocatorLog(pankey_Log_EndMethod, "create", "println","");
					return m_pointer;
				}

				virtual void* create(){
                    SimpleMemoryAllocatorLog(pankey_Log_StartMethod, "create", "println","");
					if(m_pointer == nullptr){
						m_pointer = new T();
					}
                    SimpleMemoryAllocatorLog(pankey_Log_EndMethod, "create", "println","");
					return m_pointer;
				}
				virtual void destroy(pointer_size a_size, void* a_destroy){
                    SimpleMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "println","");
					if(m_pointer == nullptr){
						return;
					}
					delete m_pointer;
                    SimpleMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "println","");
				}
				virtual void destroy(void* a_destroy){
                    SimpleMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "println","");
					if(m_pointer == nullptr){
						return;
					}
					delete m_pointer;
                    SimpleMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "println","");
				}
			protected:
				T* m_pointer = nullptr;
		};

	}

#endif