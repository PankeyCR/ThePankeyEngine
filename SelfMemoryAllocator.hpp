
#ifndef SelfMemoryAllocator_hpp
	#define SelfMemoryAllocator_hpp

	#include "MemoryAllocator.hpp"

    #ifdef SelfMemoryAllocator_LogApp
        #include "pankey_Logger.hpp"
        #define SelfMemoryAllocatorLog(location,method,type,mns) pankey_Log(nullptr,location,"SelfMemoryAllocator",method,type,mns)
    #else
        #define SelfMemoryAllocatorLog(location,method,type,mns)
    #endif

	namespace pankey{

		template<class T>
		class SelfMemoryAllocator : public MemoryAllocator{
			public:
				SelfMemoryAllocator(T* a_pointer){
					m_pointer = a_pointer;
					m_managed = true;
				}
				virtual ~SelfMemoryAllocator(){}

				virtual void* create(pointer_size a_size){
                    SelfMemoryAllocatorLog(pankey_Log_StartMethod, "create", "println","");
                    SelfMemoryAllocatorLog(pankey_Log_EndMethod, "create", "println","");
					return m_pointer;
				}

				virtual void* create(){
                    SelfMemoryAllocatorLog(pankey_Log_StartMethod, "create", "println","");
                    SelfMemoryAllocatorLog(pankey_Log_EndMethod, "create", "println","");
					return m_pointer;
				}
				virtual void destroy(void* a_destroy){
                    SelfMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "println","")
                    SelfMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "println","");
				}
			protected:
				T* m_pointer = nullptr;
		};

	}

#endif