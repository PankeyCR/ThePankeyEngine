
#ifndef Variable_hpp
	#define Variable_hpp

    #include "Member.hpp"
    #include "ClassCount.hpp"
    #include "Data.hpp"
    #include "Pointer.hpp"
    #include "Value.hpp"
    #include "Object.hpp"
    #include "Self.hpp"
    #include "StaticAllocatorInstance.hpp"
    #include "PointerSize.hpp"
    #include "type_traits.hpp"

    #ifdef Variable_LogApp
        #include "pankey_Logger.hpp"
        #define VariableLog(location,method,type,mns) pankey_Log(nullptr,location,"Variable",method,type,mns)
    #else
        #define VariableLog(location,method,type,mns)
    #endif

	namespace pankey{

        template<class H, class M>
        class Variable : public Member<H,M>{
            public:

                using MANAGER_TYPE = typename Member<H,M>::MANAGER_TYPE;
                using VOID_TYPE = typename Member<H,M>::VOID_TYPE;
                using HOLDER_TYPE = typename Member<H,M>::HOLDER_TYPE;

                Variable(){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","default");
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Variable(const Member<H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Variable(const Variable<H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Variable(const Data<H>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    if(!this->isMember(a_holder)){
                        VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Variable(const Pointer<P,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Variable(const Value<P,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                template<class O>
                Variable(const Object<O,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Variable(const Self<P,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Variable(const P& a_value){
                    VariableLog(pankey_Log_StartMethod, "Constructor", "println","value constructor");

					if(is_base_of<MemoryHolder<H>, P>::value){
						this->copyType(&a_value);
                    	ObjectLog(pankey_Log_EndMethod, "Constructor", "println","memoryholder asignment");
						return;
					}

                    this->create<P>();
                    this->setValue<P>(a_value);
                    VariableLog(pankey_Log_EndMethod, "Constructor", "println","");
                }
                
                virtual ~Variable(){
                    VariableLog(pankey_Log_StartMethod, "Destructor", "println","");
                    VariableLog(pankey_Log_EndMethod, "Destructor", "println","");
                }

                void copyType(const void* a_holder){
                    VariableLog(pankey_Log_StartMethod, "copyType", "println","fix");
                    const MemoryHolder<H>* i_holder = (const MemoryHolder<H>*)a_holder;
					if(i_holder == nullptr){
						return;
					}
					this->copyMemoryHolder(*i_holder);
                    VariableLog(pankey_Log_EndMethod, "copyType", "println","");
                }

				template<class P>
                void create(){
					VariableLog(pankey_Log_StartMethod, "create", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr){
					    VariableLog(pankey_Log_EndMethod, "create", "println","");
                        return;
                    }
                    VariableLog(pankey_Log_Statement, "create", "println","creating new instance");
                    HOLDER_TYPE i_holder = MemoryHolderManager<H>::newInstance(this->getManager(), ClassCount<P>::get(), sizeOfPointer<P>(), StaticAllocatorInstance<P>::getAllocator());
                    this->setHolder(i_holder);
					VariableLog(pankey_Log_EndMethod, "create", "println","");
				}

				template<class P>
				void setValue(P a_value){
					VariableLog(pankey_Log_StartMethod, "setValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr && this->getType() == ClassCount<P>::get()){
						P* i_value_1 = (P*)i_pointer;
					    VariableLog(pankey_Log_Statement, "setValue", "println","asign value with assignment operator");
						*i_value_1 = a_value;
					}
					VariableLog(pankey_Log_EndMethod, "setValue", "println","");
				}

				template<class P>
				P getValue(){
					VariableLog(pankey_Log_StartMethod, "getValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();

					VariableLog(pankey_Log_Statement, "getValue", "println", "Is Holder == nullptr");
					VariableLog(pankey_Log_Statement, "getValue", "println", this->m_holder == nullptr);
					if(i_pointer != nullptr){
						if(this->getType() == ClassCount<P>::get() || this->getBaseType() == ClassCount<P>::get()){
							VariableLog(pankey_Log_Statement, "getValue", "println", "i_pointer != nullptr");
							//VariableLog(pankey_Log_EndMethod, "getValue", "println", *((P*)i_pointer));
							return *((P*)i_pointer);
						}
					}
					VariableLog(pankey_Log_EndMethod, "getValue", "println","");
					return P();
				}

				template<class P>
				P& getReference(){
					VariableLog(pankey_Log_StartMethod, "getValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					VariableLog(pankey_Log_EndMethod, "getValue", "println","");
					return *((P*)i_pointer);
				}

                void operator=(const Member<H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                void operator=(const Variable<H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                void operator=(const Data<H>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    if(!this->isMember(a_holder)){
                        VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                template<class P>
                void operator=(const Pointer<P,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                template<class P>
                void operator=(const Value<P,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                template<class O>
                void operator=(const Object<O,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                template<class P>
                void operator=(const Self<P,H,M>& a_holder){
                    VariableLog(pankey_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    VariableLog(pankey_Log_EndMethod, "void operator=", "println","");
                }

                template<class P>
                void operator=(const P& a_value){
                    VariableLog(pankey_Log_StartMethod, "operator=", "println","");

					if(is_base_of<MemoryHolder<H>, P>::value){
						this->copyType(&a_value);
                    	ObjectLog(pankey_Log_EndMethod, "operator=", "println","memoryholder asignment");
						return;
					}

					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer == nullptr){
						this->create<P>();
					}
					this->setValue<P>(a_value);
                    VariableLog(pankey_Log_EndMethod, "operator=", "println","");
                }
            
        };

        template<class H, class M>
        Variable<H,M> Var(const Member<H,M>& a_holder){
            Variable<H,M> i_var;
            i_var.copyMember(a_holder);
            return i_var;
        }

        template<class H, class M>
        Variable<H,M> VarMemoryHolder(const MemoryHolder<H>& a_holder){
            Variable<H,M> i_var;
            i_var.copyMemoryHolder(a_holder);
            return i_var;
        }

	}

#endif