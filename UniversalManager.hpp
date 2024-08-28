
#ifndef UniversalManager_hpp
	#define UniversalManager_hpp

	#include "MemoryManager.hpp"
	#include "UniversalHolder.hpp"
	#include "PointerSize.hpp"

	#ifdef UniversalManager_LogApp
		#include "pankey_Logger.hpp"
		#define UniversalManagerLog(location,method,type,mns) pankey_Log((void*)this,location,"UniversalManager",method,type,mns)
	#else
		#define UniversalManagerLog(location,method,type,mns)
	#endif

	namespace pankey{

		class UniversalManager : public MemoryManager<UniversalHolder>{
			public:
				using VOID_TYPE = typename MemoryManager<UniversalHolder>::VOID_TYPE;
				using HOLDER_TYPE = typename MemoryManager<UniversalHolder>::HOLDER_TYPE;
				
				UniversalManager(){
					UniversalManagerLog(pankey_Log_StartMethod, "Constructor", "println", "");
					UniversalManagerLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~UniversalManager(){
					UniversalManagerLog(pankey_Log_StartMethod, "Destructor", "println", "");
					UniversalManagerLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual void setType(HOLDER_TYPE& a_holder, long a_type){
					UniversalManagerLog(pankey_Log_StartMethod, "setType", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "setType", "println", "a_holder == nullptr");
						return;
					}
					a_holder->m_type = a_type;
					UniversalManagerLog(pankey_Log_EndMethod, "setType", "println", "");
				}

				virtual long getType(const HOLDER_TYPE& a_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "getType", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "getType", "println", "a_holder == nullptr");
						return -1;
					}
					UniversalManagerLog(pankey_Log_EndMethod, "getType", "println", "");
					return a_holder->m_type;
				}

				virtual void setBaseType(HOLDER_TYPE& a_holder, long a_type){
					UniversalManagerLog(pankey_Log_StartMethod, "setBaseType", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "setBaseType", "println", "a_holder == nullptr");
						return;
					}
					a_holder->m_base_type = a_type;
					UniversalManagerLog(pankey_Log_EndMethod, "setBaseType", "println", "");
				}

				virtual long getBaseType(const HOLDER_TYPE& a_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "getBaseType", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "getBaseType", "println", "a_holder == nullptr");
						return -1;
					}
					UniversalManagerLog(pankey_Log_EndMethod, "getBaseType", "println", "");
					return a_holder->m_base_type;
				}

				virtual HOLDER_TYPE newHolder(){
					UniversalManagerLog(pankey_Log_StartMethod, "newHolder", "println", "");
					UniversalHolder* i_erf =  new UniversalHolder();
					UniversalManagerLog(pankey_Log_EndMethod, "newHolder", "println", "");
					return i_erf;
				}

				virtual HOLDER_TYPE newInstance(long a_type, MemoryAllocator* a_allocator){
					UniversalManagerLog(pankey_Log_StartMethod, "newInstance", "println", "with void*");
					UniversalHolder* i_holder =  new UniversalHolder();
					i_holder->m_allocator = a_allocator;
					if(a_allocator != nullptr){
						i_holder->m_pointer = a_allocator->create();
					}
					i_holder->m_type = a_type;
					UniversalManagerLog(pankey_Log_EndMethod, "newInstance", "println", "");
					return i_holder;
				}

				virtual HOLDER_TYPE newInstance(long a_type, pointer_size a_size, MemoryAllocator* a_allocator){
					UniversalManagerLog(pankey_Log_StartMethod, "newInstance", "println", "with void*");
					UniversalHolder* i_holder =  new UniversalHolder();
					i_holder->m_allocator = a_allocator;
					if(a_allocator != nullptr){
						i_holder->m_pointer = a_allocator->create(a_size);
					}
					i_holder->m_type = a_type;
					UniversalManagerLog(pankey_Log_EndMethod, "newInstance", "println", "");
					return i_holder;
				}

				virtual void setManageableCheck(HOLDER_TYPE& a_holder, bool a_check){
					UniversalManagerLog(pankey_Log_StartMethod, "setManageableCheck", "println", "with void*");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "setManageableCheck", "println", "a_holder == nullptr");
						return;
					}
					a_holder->m_maneged = a_check;
					UniversalManagerLog(pankey_Log_EndMethod, "setManageableCheck", "println", "");
				}

				virtual void set(HOLDER_TYPE& a_holder, HOLDER_TYPE& a_set_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "set", "println", "");
					a_holder = a_set_holder;
					UniversalManagerLog(pankey_Log_EndMethod, "set", "println", "");
				}

				virtual void add(HOLDER_TYPE& a_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "add", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "add", "println", "a_holder == nullptr");
						return;
					}
					a_holder->m_count++;
					UniversalManagerLog(pankey_Log_Statement, "add", "println", "Count: ");
					UniversalManagerLog(pankey_Log_Statement, "add", "println", a_holder->m_count);
					UniversalManagerLog(pankey_Log_EndMethod, "add", "println", "");
				}

				virtual void remove(HOLDER_TYPE& a_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "remove", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "remove", "println", "a_holder == nullptr");
						return;
					}

					UniversalManagerLog(pankey_Log_Statement, "remove", "println", "Count before: ");
					UniversalManagerLog(pankey_Log_Statement, "remove", "println", a_holder->m_count);

					a_holder->m_count--;

					UniversalManagerLog(pankey_Log_Statement, "remove", "println", "Count after: ");
					UniversalManagerLog(pankey_Log_Statement, "remove", "println", a_holder->m_count);

					if(a_holder->m_count <= 0){
						if(a_holder->m_allocator != nullptr){
							UniversalManagerLog(pankey_Log_Statement, "remove", "println", "a_holder->m_allocator != nullptr");
							if(a_holder->m_pointer != nullptr && a_holder->m_maneged){
								UniversalManagerLog(pankey_Log_Statement, "remove", "println", "a_holder->m_pointer != nullptr");
								UniversalManagerLog(pankey_Log_Statement, "remove", "println", "m_allocator->destroy");
								a_holder->m_allocator->destroy(a_holder->m_pointer);
							}
							if(a_holder->m_allocator->isManaged()){
								delete a_holder->m_allocator;
							}
						}

						delete a_holder;

						a_holder->m_allocator = nullptr;
						a_holder->m_pointer = nullptr;
						a_holder = nullptr;
						UniversalManagerLog(pankey_Log_Statement, "remove", "println", "full remove");
					}else{
						a_holder = nullptr;
						UniversalManagerLog(pankey_Log_Statement, "remove", "println", "partial null remove");
					}
					UniversalManagerLog(pankey_Log_EndMethod, "remove", "println", "");
				}

				virtual void destroy(HOLDER_TYPE& a_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "destroy", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "destroy", "println", "a_holder == nullptr");
						return;
					}

					UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "Count before: ");
					UniversalManagerLog(pankey_Log_Statement, "destroy", "println", a_holder->m_count);

					a_holder->m_count--;

					UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "Count after: ");
					UniversalManagerLog(pankey_Log_Statement, "destroy", "println", a_holder->m_count);

					if(a_holder->m_count <= 0){
						if(a_holder->m_allocator != nullptr){
							UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "a_holder->m_allocator != nullptr");
							if(a_holder->m_pointer != nullptr && a_holder->m_maneged){
								UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "a_holder->m_pointer != nullptr");
								UniversalManagerLog(pankey_Log_Statement, "remove", "println", "m_allocator->destroy");
								a_holder->m_allocator->destroy(a_holder->m_pointer);
							}
							if(a_holder->m_allocator->isManaged()){
								delete a_holder->m_allocator;
							}
						}

						delete a_holder;

						a_holder->m_allocator = nullptr;
						a_holder->m_pointer = nullptr;
						a_holder = nullptr;
						UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "full remove");
					}else{
						if(a_holder->m_allocator != nullptr){
							UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "a_holder->m_allocator != nullptr");
							if(a_holder->m_pointer != nullptr && a_holder->m_maneged){
								UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "a_holder->m_pointer != nullptr");
								UniversalManagerLog(pankey_Log_Statement, "remove", "println", "m_allocator->destroy");
								a_holder->m_allocator->destroy(a_holder->m_pointer);
							}
							if(a_holder->m_allocator->isManaged()){
								delete a_holder->m_allocator;
							}
						}

						a_holder->m_allocator = nullptr;
						a_holder->m_pointer = nullptr;
						a_holder = nullptr;
						UniversalManagerLog(pankey_Log_Statement, "destroy", "println", "partial null remove");
					}
					UniversalManagerLog(pankey_Log_EndMethod, "destroy", "println", "");
				}

				virtual VOID_TYPE get(const HOLDER_TYPE& a_holder){
					UniversalManagerLog(pankey_Log_StartMethod, "get", "println", "");
					if(a_holder == nullptr){
						UniversalManagerLog(pankey_Log_EndMethod, "get", "println", "a_holder == nullptr");
						return nullptr;
					}
					UniversalManagerLog(pankey_Log_EndMethod, "get", "println", "");
					return a_holder->m_pointer;
				}
		};

	}

#endif