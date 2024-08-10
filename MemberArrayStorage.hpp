
#ifndef MemberArrayStorage_hpp
	#define MemberArrayStorage_hpp

	#include "ArrayStorage.hpp"
	#include "MemberStorage.hpp"
	#include "MemoryHolderManager.hpp"

	#ifdef MemberArrayStorage_LogApp
		#include "higgs_Logger.hpp"
		#define MemberArrayStorageLog(location,method,type,mns) higgs_Log((void*)this,location,"MemberArrayStorage",method,type,mns)
	#else
		#define MemberArrayStorageLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class H, class M>
		class MemberArrayStorage : public ArrayStorage<H>, virtual public MemberStorage<H,M>{
			public:
                using MANAGER_TYPE = typename ArrayStorage<H>::MANAGER_TYPE;
                using HOLDER_TYPE = typename ArrayStorage<H>::HOLDER_TYPE;
                using HOLDER_ARRAY_TYPE = typename ArrayStorage<H>::HOLDER_ARRAY_TYPE;

				MemberArrayStorage(){
					MemberArrayStorageLog(higgs_Log_StartMethod, "Constructor", "println", "");
					MemberArrayStorageLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~MemberArrayStorage(){
					MemberArrayStorageLog(higgs_Log_StartMethod, "Destructor", "println", "");
					this->destroy();
					MemberArrayStorageLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual void setManager(MANAGER_TYPE a_manager){
					MemberArrayStorageLog(higgs_Log_StartMethod, "setManager", "println", "");
					MemberArrayStorageLog(higgs_Log_EndMethod, "setManager", "println", "");
				}
				
				virtual MANAGER_TYPE getManager()const{
					MemberArrayStorageLog(higgs_Log_StartMethod, "getManager", "println", "");
					MemberArrayStorageLog(higgs_Log_Statement, "getManager", "println", "is Manager null: ");
					MemberArrayStorageLog(higgs_Log_Statement, "getManager", "println", (StaticManagerInstance<H,M>::getManager() == nullptr));
					MemberArrayStorageLog(higgs_Log_EndMethod, "getManager", "println", "");
					return StaticManagerInstance<H,M>::getManager();
				}
				
				virtual Member<H,M> get(int a_position)const{
					MemberArrayStorageLog(higgs_Log_StartMethod, "get", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						MemberArrayStorageLog(higgs_Log_EndMethod, "get", "println", "");
						return Member<H,M>();
					}

					Member<H,M> i_pointer;
					i_pointer.setHolder(this->m_values[a_position]);

					MemberArrayStorageLog(higgs_Log_EndMethod, "get", "println", "");
					return i_pointer;
				}

				virtual Member<H,M> removeByIndex(int a_position){
					MemberArrayStorageLog(higgs_Log_StartMethod, "removeByIndex", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						MemberArrayStorageLog(higgs_Log_EndMethod, "removeByIndex", "println", "");
						return Member<H,M>();
					}
					Member<H,M> i_pointer;
					i_pointer.setHolder(this->m_values[a_position]);
					MemoryHolderManager<H>::remove(this->getManager(), this->m_values[a_position]);
					MemberArrayStorageLog(higgs_Log_EndMethod, "removeByIndex", "println", "");
					return i_pointer;
				}
		};

	}

#endif