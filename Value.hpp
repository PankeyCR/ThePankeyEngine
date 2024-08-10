
#ifndef Value_hpp
	#define Value_hpp

	#include "Pointer.hpp"

	#ifdef Value_LogApp
		#include "higgs_Logger.hpp"
		#define ValueLog(location,method,type,mns) higgs_Log(this,location,"Value",method,type,mns)
	#else
		#define ValueLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class P, class H, class M>
		class Value : public Pointer<P,H,M>{
			public:
				using VALUE_TYPE = P;
				using VOID_TYPE = typename Member<H,M>::VOID_TYPE;
				using HOLDER_TYPE = typename Member<H,M>::HOLDER_TYPE;
				
				Value(){
					ValueLog(higgs_Log_StartMethod, "Contructor", "println","");
					ValueLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Value(const VALUE_TYPE& a_value){
					ValueLog(higgs_Log_StartMethod, "Contructor", "println","const VALUE_TYPE &a_value");
					this->create();
                    this->setValue(a_value);
					ValueLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Value(const MemoryHolder<H>& a_value){
					ValueLog(higgs_Log_StartMethod, "Contructor", "println","const MemoryHolder &a_value");
                    if(!this->isMember(a_value)){
                        PointerLog(higgs_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_value.getHolder());
					ValueLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Value(const Member<H,M>& a_value){
					ValueLog(higgs_Log_StartMethod, "Contructor", "println","const Member &a_value");
                    if(!this->sameType(a_value.getType())){
                        ValueLog(higgs_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_value.getHolder());
					ValueLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Value(const Pointer<P,H,M>& a_pointer){
					PointerLog(higgs_Log_StartMethod, "Contructor", "println","const Pointer &a_pointer");
                    this->setHolder(a_pointer.getHolder());
					PointerLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Value(const Value<P,H,M>& a_pointer){
					PointerLog(higgs_Log_StartMethod, "Contructor", "println","const Pointer &a_pointer");
                    this->setHolder(a_pointer.getHolder());
					PointerLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				virtual ~Value(){
					ValueLog(higgs_Log_StartMethod, "Destructor", "println","");
					ValueLog(higgs_Log_EndMethod, "Destructor", "println","");
				}

				virtual void setValue(VALUE_TYPE a_value){
					ValueLog(higgs_Log_StartMethod, "setValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr){
						VALUE_TYPE* i_value_1 = (VALUE_TYPE*)i_pointer;
						*i_value_1 = a_value;
					}
					ValueLog(higgs_Log_EndMethod, "setValue", "println","");
				}

				virtual VALUE_TYPE getValue(){
					ValueLog(higgs_Log_StartMethod, "getValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();

					ValueLog(higgs_Log_Statement, "getValue", "println", "Is Holder == nullptr");
					ValueLog(higgs_Log_Statement, "getValue", "println", this->m_holder == nullptr);
					if(i_pointer != nullptr){
						ValueLog(higgs_Log_Statement, "getValue", "println", "i_pointer != nullptr");
						return *((VALUE_TYPE*)i_pointer);
					}
					ValueLog(higgs_Log_EndMethod, "getValue", "println","");
					return VALUE_TYPE();
				}

				virtual VALUE_TYPE& getReference(){
					ValueLog(higgs_Log_StartMethod, "getValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					ValueLog(higgs_Log_EndMethod, "getValue", "println","");
					return *((VALUE_TYPE*)i_pointer);
				}

				virtual Pointer<P,H,M> clone(){
					ValueLog(higgs_Log_StartMethod, "clone", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer == nullptr){
						ValueLog(higgs_Log_StartMethod, "clone", "println","i_pointer == nullptr");
						return Pointer<P,H,M>();
					}
					Pointer<P,H,M> i_clone;
					i_clone.create();
					VOID_TYPE i_pointer_2 = i_clone.getRawPointer();
					if(i_pointer_2 == nullptr){
						ValueLog(higgs_Log_StartMethod, "clone", "println","i_pointer_2 == nullptr");
						return Pointer<P,H,M>();
					}
					VALUE_TYPE* i_value_1 = (VALUE_TYPE*)i_pointer;
					VALUE_TYPE* i_value_2 = (VALUE_TYPE*)i_pointer_2;
					*i_value_2 = *i_value_1;
					ValueLog(higgs_Log_EndMethod, "clone", "println","");
					return i_clone;
				}

				virtual void operator=(const VALUE_TYPE& a_value){
					ValueLog(higgs_Log_StartMethod, "operator=", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer == nullptr){
						this->create();
					}
					this->setValue(a_value);
					ValueLog(higgs_Log_EndMethod, "operator=", "println","");
				}

				virtual bool operator==(const VALUE_TYPE& a_value){
					ValueLog(higgs_Log_StartMethod, "operator==", "println","");
					ValueLog(higgs_Log_EndMethod, "operator==", "println","");
					return this->getValue() == a_value;
				}

				virtual bool operator!=(const VALUE_TYPE& a_value){
					ValueLog(higgs_Log_StartMethod, "operator!=", "println","");
					ValueLog(higgs_Log_EndMethod, "operator!=", "println","");
					return this->getValue() != a_value;
				}

			protected:
		};

	}

#endif