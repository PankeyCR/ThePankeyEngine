
#ifndef Pointer_hpp
	#define Pointer_hpp

	#include "StaticManagerInstance.hpp"
	#include "MemoryHolderManager.hpp"
	#include "ClassCount.hpp"
	#include "MemoryHolder.hpp"
    #include "Member.hpp"
    #include "StaticAllocatorInstance.hpp"
    #include "SimpleMemoryAllocator.hpp"
    #include "PointerSize.hpp"

	#ifdef Pointer_LogApp
		#include "pankey_Logger.hpp"
		#define PointerLog(location,method,type,mns) pankey_Log(this,location,"Pointer",method,type,mns)
	#else
		#define PointerLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class P, class H, class M>
		class Pointer : public Member<H,M>{
			public:
				using INSTANCE_TYPE = P*;
                using MANAGER_TYPE = typename Member<H,M>::MANAGER_TYPE;
                using VOID_TYPE = typename Member<H,M>::VOID_TYPE;
                using HOLDER_TYPE = typename Member<H,M>::HOLDER_TYPE;
				
				Pointer(){
					PointerLog(pankey_Log_StartMethod, "Contructor", "println","");
					PointerLog(pankey_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(const MemoryHolder<H>& a_pointer){
					PointerLog(pankey_Log_StartMethod, "Contructor", "println","const MemoryHolder<H>&");
                    if(!a_pointer.isMember(this->getManager(), ClassCount<P>::get())){
                        PointerLog(pankey_Log_EndMethod, "Constructor", "println","!a_pointer.isMember(this->getManager(), ClassCount<P>::get())");
                        return;
                    }
                    this->setHolder(a_pointer.getHolder());
					PointerLog(pankey_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(const Member<H,M>& a_pointer){
					PointerLog(pankey_Log_StartMethod, "Contructor", "println","const Member<H,M>&");
                    if(!a_pointer.sameType(ClassCount<P>::get())){
                        PointerLog(pankey_Log_EndMethod, "Constructor", "println","!a_pointer.sameType(ClassCount<P>::get())");
                        return;
                    }
                    this->setHolder(a_pointer.getHolder());
					PointerLog(pankey_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(const Pointer<P,H,M>& a_pointer){
					PointerLog(pankey_Log_StartMethod, "Contructor", "println","const Pointer<P,H,M>&");
                    this->setHolder(a_pointer.getHolder());
					PointerLog(pankey_Log_EndMethod, "Contructor", "println","");
				}

				Pointer(P* a_pointer){
					PointerLog(pankey_Log_StartMethod, "Contructor", "println","const Pointer<P,H,M>&");
					this->m_holder = MemoryHolderManager<H>::newInstance(this->getManager(), ClassCount<P>::get(), new SimpleMemoryAllocator<P>(a_pointer));
					MemoryHolderManager<H>::add(this->getManager(), this->m_holder);
					PointerLog(pankey_Log_EndMethod, "Contructor", "println","");
				}

				virtual ~Pointer(){
					PointerLog(pankey_Log_StartMethod, "Destructor", "println","");
					PointerLog(pankey_Log_EndMethod, "Destructor", "println","");
				}

				virtual void create(){
					PointerLog(pankey_Log_StartMethod, "create", "println", "");
					PointerLog(pankey_Log_Statement, "create", "println", "ClassCount<P>::get(): ");
					PointerLog(pankey_Log_Statement, "create", "println", ClassCount<P>::get());
					PointerLog(pankey_Log_Statement, "create", "println", "sizeOfPointer<P>(): ");
					PointerLog(pankey_Log_Statement, "create", "println", sizeOfPointer<P>());
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr){
						return;
					}
					HOLDER_TYPE i_holder = MemoryHolderManager<H>::newInstance(this->getManager(), ClassCount<P>::get(), sizeOfPointer<P>(), StaticAllocatorInstance<P>::getAllocator());
					this->setHolder(i_holder);
					this->setBaseType(ClassCount<P>::get());
					PointerLog(pankey_Log_EndMethod, "create", "println","");
				}

				//unsafe method
				virtual INSTANCE_TYPE operator ->(){
					PointerLog(pankey_Log_StartMethod, "operator ->", "println","");
					PointerLog(pankey_Log_EndMethod, "operator ->", "println","");
					return (INSTANCE_TYPE)MemoryHolderManager<H>::get(StaticManagerInstance<H,M>::getManager(), this->getHolder());
				}

				//unsafe method
				virtual INSTANCE_TYPE get()const{
					return (INSTANCE_TYPE)MemoryHolderManager<H>::get(StaticManagerInstance<H,M>::getManager(), this->getHolder());
				}
		};

	}

#endif