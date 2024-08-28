
#ifndef MemberTableStorage_hpp
	#define MemberTableStorage_hpp

	#include "TableStorage.hpp"
	#include "Member.hpp"

	#ifdef MemberTableStorage_LogApp
		#include "pankey_Logger.hpp"
		#define MemberTableStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"MemberTableStorage",method,type,mns)
	#else
		#define MemberTableStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H, class M>
		class MemberTableStorage : virtual public TableStorage<H>{
			public:

                using MANAGER_TYPE = typename MemoryStorage<H>::MANAGER_TYPE;
                using HOLDER_TYPE = typename MemoryStorage<H>::HOLDER_TYPE;

				virtual ~MemberTableStorage(){
					MemberTableStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					MemberTableStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual Member<H,M> get(int a_position)const=0;

				virtual Member<H,M> removeByIndex(int a_position)=0;
				
		};

	}

#endif