
#ifndef MemoryHolderManager_hpp
	#define MemoryHolderManager_hpp

    #include "MemoryManager.hpp"

    #ifdef MemoryHolderManager_LogApp
        #include "pankey_Logger.hpp"
        #define MemoryHolderManagerLog(location,method,type,mns) pankey_Log(nullptr,location,"MemoryHolderManager",method,type,mns)
    #else
        #define MemoryHolderManagerLog(location,method,type,mns)
    #endif

	namespace pankey{

        template<class H>
        class MemoryHolderManager{
            public:

            using MANAGER_TYPE = MemoryManager<H>*;
            using VOID_TYPE = typename MemoryManager<H>::VOID_TYPE;
            using HOLDER_TYPE = typename MemoryManager<H>::HOLDER_TYPE;

            static void setType(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder, long a_type){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "setType", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "setType", "println","m_allocator == nullptr");
                    return;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "setType", "println","a_holder == nullptr");
                    return;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "setType", "println","");
                a_manager->setType(a_holder, a_type);
            }
            
            static long getType(MANAGER_TYPE a_manager, const HOLDER_TYPE& a_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "getType", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "getType", "println","m_allocator == nullptr");
                    return -1;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "getType", "println","a_holder == nullptr");
                    return -1;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "getType", "println","");
                return a_manager->getType(a_holder);
            }

            static void setBaseType(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder, long a_type){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "setBaseType", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "setBaseType", "println","m_allocator == nullptr");
                    return;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "setBaseType", "println","a_holder == nullptr");
                    return;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "setBaseType", "println","");
                a_manager->setBaseType(a_holder, a_type);
            }
            
            static long getBaseType(MANAGER_TYPE a_manager, const HOLDER_TYPE& a_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "getBaseType", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "getBaseType", "println","m_allocator == nullptr");
                    return -1;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "getBaseType", "println","a_holder == nullptr");
                    return -1;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "getBaseType", "println","");
                return a_manager->getBaseType(a_holder);
            }
            
            static HOLDER_TYPE newHolder(MANAGER_TYPE a_manager){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "newHolder", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "newHolder", "println","m_allocator == nullptr");
                    return nullptr;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "newHolder", "println","");
                return a_manager->newHolder();
            }
            
            static HOLDER_TYPE newInstance(MANAGER_TYPE a_manager, long a_type, MemoryAllocator* a_allocator){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "newInstance", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "newInstance", "println","m_allocator == nullptr");
                    return nullptr;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "newInstance", "println","");
                return a_manager->newInstance(a_type, a_allocator);
            }
            
            static HOLDER_TYPE newInstance(MANAGER_TYPE a_manager, long a_type, pointer_size a_size, MemoryAllocator* a_allocator){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "newInstance", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "newInstance", "println","m_allocator == nullptr");
                    return nullptr;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "newInstance", "println","");
                return a_manager->newInstance(a_type, a_size, a_allocator);
            }
            
            static void setManageableCheck(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder, bool a_check){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "setManageableCheck", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "setManageableCheck", "println","m_allocator == nullptr");
                    return;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "setManageableCheck", "println","");
                a_manager->setManageableCheck(a_holder, a_check);
            }
            
            static void set(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder, HOLDER_TYPE& a_set_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "set", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "set", "println","m_allocator == nullptr");
                    return;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "set", "println","a_holder == nullptr");
                    return;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "set", "println","");
                a_manager->set(a_holder, a_set_holder);
            }
            
            static void add(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "add", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "add", "println","m_allocator == nullptr");
                    return;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "add", "println","a_holder == nullptr");
                    return;
                }
                a_manager->add(a_holder);
                MemoryHolderManagerLog(pankey_Log_EndMethod, "add", "println","");
            }
            
            static void remove(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "remove", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "remove", "println","m_allocator == nullptr");
                    return;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "remove", "println","a_holder == nullptr");
                    return;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "remove", "println","");
                a_manager->remove(a_holder);
            }
            
            static void destroy(MANAGER_TYPE a_manager, HOLDER_TYPE& a_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "destroy", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "destroy", "println","m_allocator == nullptr");
                    return;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "destroy", "println","a_holder == nullptr");
                    return;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "destroy", "println","");
                a_manager->destroy(a_holder);
            }
            
            static VOID_TYPE get(MANAGER_TYPE a_manager, const HOLDER_TYPE& a_holder){
                MemoryHolderManagerLog(pankey_Log_StartMethod, "get", "println","");
                if(a_manager == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "get", "println","m_allocator == nullptr");
                    return nullptr;
                }
                if(a_holder == nullptr){
                    MemoryHolderManagerLog(pankey_Log_EndMethod, "get", "println","a_holder == nullptr");
                    return nullptr;
                }
                MemoryHolderManagerLog(pankey_Log_EndMethod, "get", "println","");
                return a_manager->get(a_holder);
            }
            
        };

	}

#endif