
#ifndef UniversalAllocator_hpp
	#define UniversalAllocator_hpp

	#include "MemoryAllocator.hpp"

	#ifdef UniversalManager_LogApp
		#include "pankey_Logger.hpp"
		#define UniversalManagerLog(location,method,type,mns) pankey_Log((void*)this,location,"UniversalManager",method,type,mns)
	#else
		#define UniversalManagerLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H>
		class UniversalAllocator : public MemoryAllocator<H>{
			public:
				using HOLDER_TYPE = UniversalAllocator<H>::HOLDER_TYPE;

				UniversalAllocator(){}
				virtual ~UniversalAllocator(){}

				virtual HOLDER_TYPE newHolder(){
					UniversalManagerLog(pankey_Log_StartMethod, "newHolder", "println", "");
					UniversalHolder* i_erf =  new UniversalHolder();
					UniversalManagerLog(pankey_Log_EndMethod, "newHolder", "println", "");
					return i_erf;
				}

				virtual HOLDER_TYPE newInstance(long a_type){
					UniversalManagerLog(pankey_Log_StartMethod, "newInstance", "println", "with void*");
					UniversalHolder* i_holder =  new UniversalHolder();
					TemplateMemory i_memory;
					i_holder->m_pointer = i_memory.create(a_type);
					i_holder->m_type = a_type;
					UniversalManagerLog(pankey_Log_EndMethod, "newInstance", "println", "");
					return i_holder;
				}

				virtual HOLDER_TYPE newInstance(long a_type, pointer_size a_size){
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
		};

	}

#endif