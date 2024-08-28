
#ifndef MemberArrayTableStorage_hpp
	#define MemberArrayTableStorage_hpp

	#include "ArrayTableStorage.hpp"
	#include "MemberTableStorage.hpp"
	#include "MemoryHolderManager.hpp"

	#ifdef MemberArrayTableStorage_LogApp
		#include "pankey_Logger.hpp"
		#define MemberArrayTableStorageLog(location,method,type,mns) pankey_Log((void*)this,location,"MemberArrayTableStorage",method,type,mns)
	#else
		#define MemberArrayTableStorageLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class H, class M>
		class MemberArrayTableStorage : public ArrayTableStorage<H>, virtual public MemberTableStorage<H,M>{
			public:
                using MANAGER_TYPE = typename ArrayTableStorage<H>::MANAGER_TYPE;
                using HOLDER_TYPE = typename ArrayTableStorage<H>::HOLDER_TYPE;

				MemberArrayTableStorage(){
					MemberArrayTableStorageLog(pankey_Log_StartMethod, "Constructor", "println", "");
					MemberArrayTableStorageLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

				virtual ~MemberArrayTableStorage(){
					MemberArrayTableStorageLog(pankey_Log_StartMethod, "Destructor", "println", "");
					this->destroy();
					MemberArrayTableStorageLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual void setManager(MANAGER_TYPE a_manager){
					MemberArrayTableStorageLog(pankey_Log_StartMethod, "setManager", "println", "");
					MemberArrayTableStorageLog(pankey_Log_EndMethod, "setManager", "println", "");
				}
				
				virtual MANAGER_TYPE getManager()const{
					MemberArrayTableStorageLog(pankey_Log_StartMethod, "getManager", "println", "");
					MemberArrayTableStorageLog(pankey_Log_Statement, "getManager", "println", "is Manager null: ");
					MemberArrayTableStorageLog(pankey_Log_Statement, "getManager", "println", (StaticManagerInstance<H,M>::getManager() == nullptr));
					MemberArrayTableStorageLog(pankey_Log_EndMethod, "getManager", "println", "");
					return StaticManagerInstance<H,M>::getManager();
				}
				
				virtual Member<H,M> get(int a_position)const{
					MemberArrayTableStorageLog(pankey_Log_StartMethod, "get", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						MemberArrayTableStorageLog(pankey_Log_EndMethod, "get", "println", "");
						return Member<H,M>();
					}

					Member<H,M> i_pointer;
					// i_pointer.setHolder(this->m_values[a_position]);

					MemberArrayTableStorageLog(pankey_Log_EndMethod, "get", "println", "");
					return i_pointer;
				}

				virtual Member<H,M> removeByIndex(int a_position){
					MemberArrayTableStorageLog(pankey_Log_StartMethod, "removeByIndex", "println", "");
					if(this->isNull() || a_position >= this->getSize() || a_position < 0){
						MemberArrayTableStorageLog(pankey_Log_EndMethod, "removeByIndex", "println", "");
						return Member<H,M>();
					}
					Member<H,M> i_pointer;
					// i_pointer.setHolder(this->m_values[a_position]);
					// MemoryHolderManager<H>::remove(this->getManager(), this->m_values[a_position]);
					// MemberArrayTableStorageLog(pankey_Log_EndMethod, "removeByIndex", "println", "");
					return i_pointer;
				}
		};

	}

#endif