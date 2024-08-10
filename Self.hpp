
#ifndef Self_hpp
	#define Self_hpp

	#include "MemoryHolder.hpp"
    #include "StaticManagerInstance.hpp"
    #include "SelfMemoryAllocator.hpp"

	#ifdef Self_LogApp
		#include "higgs_Logger.hpp"
		#define SelfLog(location,method,type,mns) higgs_Log(this,location,"Self",method,type,mns)
	#else
		#define SelfLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class P, class H, class M>
		class Self : public MemoryHolder<H>{
			public:
				using SELF_TYPE = P;
                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using VOID_TYPE = typename MemoryHolder<H>::VOID_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;

				Self(SELF_TYPE* a_Self){
					SelfLog(higgs_Log_StartMethod, "Contructor", "println","const SELF_TYPE &a_Self");
					this->m_holder = MemoryHolderManager<H>::newInstance(this->getManager(), ClassCount<P>::get(), new SelfMemoryAllocator<P>(a_Self));
					MemoryHolderManager<H>::add(this->getManager(), this->m_holder);
					MemoryHolderManager<H>::setManageableCheck(this->getManager(), this->m_holder, false);
					SelfLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				virtual ~Self(){
					SelfLog(higgs_Log_StartMethod, "Destructor", "println","");
					this->destroy();
					SelfLog(higgs_Log_EndMethod, "Destructor", "println","");
				}

                virtual MANAGER_TYPE getManager()const{
                    MemberLog(higgs_Log_StartMethod, "getManager", "println","");
                    MemberLog(higgs_Log_EndMethod, "getManager", "println","");
                    return StaticManagerInstance<H,M>::getManager();
                }

				//if theres no manager, this method crashs, always check for null
				virtual SELF_TYPE& getSelf(){
					SelfLog(higgs_Log_StartMethod, "getSelf", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					SelfLog(higgs_Log_EndMethod, "getSelf", "println","");
					return *((SELF_TYPE*)i_pointer);
				}

                virtual void setHolder(HOLDER_TYPE a_holder){
					SelfLog(higgs_Log_StartMethod, "setHolder", "println","");
					SelfLog(higgs_Log_EndMethod, "setHolder", "println","");
				}

				virtual bool operator==(const Self<P,H,M>& a_self)const{
					return a_self.getHolder() == this->getHolder();
				}
				
				virtual bool operator!=(const Self<P,H,M>& a_self)const{
					return a_self.getHolder() == this->getHolder();
				}

			protected:
		};

	}

#endif