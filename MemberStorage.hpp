
#ifndef MemberStorage_hpp
	#define MemberStorage_hpp

	#include "MemoryStorage.hpp"
	#include "Member.hpp"

	#ifdef MemberStorage_LogApp
		#include "pankey_Logger.hpp"
		#define MemberStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"MemberStorage",method,type,mns)
	#else
		#define MemberStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H, class M>
		class MemberStorage : virtual public MemoryStorage<H>{
			public:

                using MANAGER_TYPE = typename MemoryStorage<H>::MANAGER_TYPE;
                using HOLDER_TYPE = typename MemoryStorage<H>::HOLDER_TYPE;
                using HOLDER_ARRAY_TYPE = typename MemoryStorage<H>::HOLDER_ARRAY_TYPE;

				virtual ~MemberStorage(){
					MemberStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					MemberStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual Member<H,M> get(int a_position)const=0;

				virtual Member<H,M> removeByIndex(int a_position)=0;
				
				template<class IM>
				Member<H,M> getMember(IM a_iteration_method){
					MemoryStorageLog(pankey_Log_StartMethod, "getMember", "println", "");
					if(this->isNull() || this->getSize() <= 0){
						MemoryStorageLog(pankey_Log_EndMethod, "getMember", "println", "this->isNull() || this->getSize() <= 0");
						return Member<H,M>();
					}
					for(int x = 0; x < this->getSize(); x++){
						Member<H,M> f_member = this->get(x);
						if (a_iteration_method(x, this->getSize(), f_member)){
							return f_member;
						}
					}
					MemoryStorageLog(pankey_Log_EndMethod, "getMember", "println", "");
					return Member<H,M>();
				}
				
		};

	}

#endif