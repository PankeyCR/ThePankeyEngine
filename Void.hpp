
#ifndef Void_hpp
	#define Void_hpp

	#include "MemoryAllocator.hpp"
	#include "MemoryHolder.hpp"

	#ifdef Void_LogApp
		#include "higgs_Logger.hpp"
		#define VoidLog(location,method,type,mns) higgs_Log(this,location,"Void",method,type,mns)
	#else
		#define VoidLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class H>
		class Void{
			public:
				using POINTER_TYPE = typename MemoryAllocator<H>::POINTER_TYPE;
				using HOLDER_TYPE = typename MemoryAllocator<H>::HOLDER_TYPE;
				
				Void(){
					VoidLog(higgs_Log_StartMethod, "Contructor", "println","");
					VoidLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Void(const Void<H>& a_Void){
					VoidLog(higgs_Log_StartMethod, "Contructor", "println","const Void &a_Void");
					m_holder = a_Void.m_holder;
					m_allocator = a_Void.m_allocator;
					if(m_holder == nullptr || m_allocator == nullptr){
						VoidLog(higgs_Log_EndMethod, "Contructor", "println","m_holder == nullptr || m_allocator == nullptr");
						return;
					}
					m_allocator->add(m_holder);
					VoidLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Void(const MemoryHolder<H>& a_holder){
					VoidLog(higgs_Log_StartMethod, "Contructor", "println","const Void &a_Void");
					m_holder = a_holder.m_holder;
					m_allocator = a_holder.m_allocator;
					MemoryHolder<H>::add(m_allocator, m_holder);
					VoidLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				virtual ~Void(){
					VoidLog(higgs_Log_StartMethod, "Destructor", "println","");
					if(m_holder == nullptr || m_allocator == nullptr){
						VoidLog(higgs_Log_EndMethod, "Destructor", "println","m_holder == nullptr || m_allocator == nullptr");
						return;
					}
					m_allocator->remove(m_holder);
					VoidLog(higgs_Log_EndMethod, "Destructor", "println","");
				}

				virtual long getType()const{
					if(m_holder == nullptr || m_allocator == nullptr){
						VoidLog(higgs_Log_EndMethod, "getType", "println","m_holder == nullptr || m_allocator == nullptr");
						return;
					}
					return m_allocator->getType(m_holder);
				}

				virtual bool isNull(){
					VoidLog(higgs_Log_StartMethod, "isNull", "println","");
					if(m_holder == nullptr || m_allocator == nullptr){
						VoidLog(higgs_Log_EndMethod, "isNull", "println","m_holder == nullptr || m_allocator == nullptr");
						return true;
					}
					POINTER_TYPE i_Void = m_allocator->get(m_holder);
					VoidLog(higgs_Log_Statement, "isNull", "println", "isNull: ");
					VoidLog(higgs_Log_Statement, "isNull", "println", i_Void == nullptr);
					VoidLog(higgs_Log_EndMethod, "isNull", "println","");
					return i_Void == nullptr;
				}

				virtual void operator=(const Void<H>& a_Void){
					VoidLog(higgs_Log_StartMethod, "operator=", "println","");
					if(m_allocator == nullptr){
						VoidLog(higgs_Log_EndMethod, "operator=", "println","m_allocator == nullptr");
						return true;
					}
					m_allocator->remove(m_holder);
					m_holder = a_Void.m_holder;
					m_allocator->add(m_holder);
					VoidLog(higgs_Log_EndMethod, "operator=", "println","");
				}

				virtual bool operator==(const Void<P,H,A>& a_Void){
					VoidLog(higgs_Log_StartMethod, "operator==", "println","");
					VoidLog(higgs_Log_EndMethod, "operator==", "println", m_holder == a_Void.m_holder);
					return m_holder == a_Void.m_holder;
				}

				virtual bool operator!=(const Void<P,H,A>& a_Void){
					VoidLog(higgs_Log_StartMethod, "operator!=", "println","");
					VoidLog(higgs_Log_EndMethod, "operator!=", "println", m_holder == a_Void.m_holder);
					return m_holder != a_Void.m_holder;
				}

				template<class P, class A>
				bool operator!=(const Pointer<P,H,A>& a_Void){
					VoidLog(higgs_Log_StartMethod, "operator==", "println","");
					VoidLog(higgs_Log_EndMethod, "operator==", "println", m_holder == a_Void.m_holder);
					return m_holder == a_Void.m_holder;
				}

				template<class P, class A>
				bool operator!=(const Void<P,H,A>& a_Void){
					VoidLog(higgs_Log_StartMethod, "operator!=", "println","");
					VoidLog(higgs_Log_EndMethod, "operator!=", "println", m_holder == a_Void.m_holder);
					return m_holder != a_Void.m_holder;
				}

			protected:
            	MemoryAllocator<H>* m_allocator = nullptr;
				HOLDER_TYPE m_holder = nullptr;
		};

	}

#endif