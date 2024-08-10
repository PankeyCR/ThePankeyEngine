
#ifndef Pointer_hpp
	#define Pointer_hpp

	#include "StaticManagerInstance.hpp"
	#include "MemoryHolderManager.hpp"
	#include "ClassCount.hpp"
	#include "MemoryHolder.hpp"
    #include "Member.hpp"
    #include "StaticAllocatorInstance.hpp"
    #include "PointerSize.hpp"

	#ifdef Pointer_LogApp
		#include "higgs_Logger.hpp"
		#define PointerLog(location,method,type,mns) higgs_Log(this,location,"Pointer",method,type,mns)
	#else
		#define PointerLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class P, class H, class M>
		class Pointer : public Member<H,M>{
			public:
				using INSTANCE_TYPE = P*;
                using MANAGER_TYPE = typename Member<H,M>::MANAGER_TYPE;
                using VOID_TYPE = typename Member<H,M>::VOID_TYPE;
                using HOLDER_TYPE = typename Member<H,M>::HOLDER_TYPE;
				
				Pointer(){
					PointerLog(higgs_Log_StartMethod, "Contructor", "println","");
					PointerLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(const MemoryHolder<H>& a_pointer){
					PointerLog(higgs_Log_StartMethod, "Contructor", "println","const Pointer &a_pointer");
                    if(!this->isMember(a_pointer)){
                        PointerLog(higgs_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_pointer.getHolder());
					PointerLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(const Member<H,M>& a_pointer){
					PointerLog(higgs_Log_StartMethod, "Contructor", "println","const Pointer &a_pointer");
                    if(!this->sameType(a_pointer.getType())){
                        PointerLog(higgs_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_pointer.getHolder());
					PointerLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(const Pointer<P,H,M>& a_pointer){
					PointerLog(higgs_Log_StartMethod, "Contructor", "println","const Pointer &a_pointer");
                    this->setHolder(a_pointer.getHolder());
					PointerLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				virtual ~Pointer(){
					PointerLog(higgs_Log_StartMethod, "Destructor", "println","");
					PointerLog(higgs_Log_EndMethod, "Destructor", "println","");
				}

				virtual void create(){
					PointerLog(higgs_Log_StartMethod, "create", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr){
						return;
					}
					HOLDER_TYPE i_holder = MemoryHolderManager<H>::newInstance(this->getManager(), ClassCount<P>::get(), sizeOfPointer<P>(), StaticAllocatorInstance<P>::getAllocator());
					this->setHolder(i_holder);
					PointerLog(higgs_Log_EndMethod, "create", "println","");
				}

				//unsafe method
				virtual INSTANCE_TYPE operator ->(){
					PointerLog(higgs_Log_StartMethod, "operator ->", "println","");
					PointerLog(higgs_Log_EndMethod, "operator ->", "println","");
					return (INSTANCE_TYPE)MemoryHolderManager<H>::get(StaticManagerInstance<H,M>::getManager(), this->getHolder());
				}

				//unsafe method
				virtual INSTANCE_TYPE get()const{
					return (INSTANCE_TYPE)MemoryHolderManager<H>::get(StaticManagerInstance<H,M>::getManager(), this->getHolder());
				}
		};

	}

#endif