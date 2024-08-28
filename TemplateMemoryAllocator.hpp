
#ifndef TemplateMemoryAllocator_hpp
	#define TemplateMemoryAllocator_hpp

	#include "MemoryAllocator.hpp"
	#include "PointerSize.hpp"

    #ifdef TemplateMemoryAllocator_LogApp
        #include "pankey_Logger.hpp"
        #define TemplateMemoryAllocatorLog(location,method,type,mns) pankey_Log(nullptr,location,"TemplateMemoryAllocator",method,type,mns)
    #else
        #define TemplateMemoryAllocatorLog(location,method,type,mns)
    #endif

	namespace pankey{

		template<class T>
		class TemplateMemoryAllocator : public MemoryAllocator{
			public:
				TemplateMemoryAllocator(){}
				virtual ~TemplateMemoryAllocator(){}

				virtual void* create(pointer_size a_size){
                    TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "create", "println","");
					if(a_size != sizeOfPointer<T>()){
						return nullptr;
					}
                    TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "create", "println","");
					return new T();
				}

				virtual void* create(){
                    TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "create", "println","");
                    TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "create", "println","");
					return new T();
				}
				
				virtual void destroy(pointer_size a_size, void* a_destroy){
                    TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "println","");
					if(a_destroy == nullptr){
						return;
					}
					if(a_size != sizeOfPointer<T>()){
						return;
					}
					T* i_var = (T*)a_destroy;
					delete i_var;
                    TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "println","");
				}
				
				virtual void destroy(void* a_destroy){
                    TemplateMemoryAllocatorLog(pankey_Log_StartMethod, "destroy", "println","");
					if(a_destroy == nullptr){
						return;
					}
					T* i_var = (T*)a_destroy;
					delete i_var;
                    TemplateMemoryAllocatorLog(pankey_Log_EndMethod, "destroy", "println","");
				}
		};

	}

#endif