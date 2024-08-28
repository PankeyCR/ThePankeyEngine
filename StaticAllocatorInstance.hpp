
#ifndef StaticAllocatorInstance_hpp
	#define StaticAllocatorInstance_hpp

    #include "MemoryAllocator.hpp"
    #include "TemplateMemoryAllocator.hpp"

    #ifdef StaticAllocatorInstance_LogApp
        #include "pankey_Logger.hpp"
        #define StaticAllocatorInstanceLog(location,method,type,mns) pankey_Log(nullptr,location,"StaticAllocatorInstance",method,type,mns)
    #else
        #define StaticAllocatorInstanceLog(location,method,type,mns)
    #endif

	namespace pankey{

        template<class T>
        struct StaticAllocatorInstance{
            static MemoryAllocator* m_Allocator;

			static MemoryAllocator* getAllocator(){
				StaticAllocatorInstanceLog(pankey_Log_StartMethod, "getAllocator", "println","");
				StaticAllocatorInstanceLog(pankey_Log_Statement, "getAllocator", "println", m_Allocator == nullptr);
				StaticAllocatorInstanceLog(pankey_Log_EndMethod, "getAllocator", "println","");
				return m_Allocator;
			}
        };

        template<class T>
        MemoryAllocator* StaticAllocatorInstance<T>::m_Allocator = new TemplateMemoryAllocator<T>();
	}

#endif