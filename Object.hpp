
#ifndef Object_hpp
	#define Object_hpp

    #include "Member.hpp"
    #include "ClassCount.hpp"
    #include "Data.hpp"
    #include "Pointer.hpp"
    #include "Value.hpp"
    #include "Variable.hpp"
    #include "StaticAllocatorInstance.hpp"
    #include "PointerSize.hpp"
    #include "type_traits.hpp"

	#ifdef Object_LogApp
		#include "higgs_Logger.hpp"
		#define ObjectLog(location,method,type,mns) higgs_Log(this,location,"Object",method,type,mns)
	#else
		#define ObjectLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class O, class H, class M>
		class Object : public Member<H,M>{
			public:
				using OBJECT_TYPE = O;
				using INSTANCE_TYPE = O*;
                using MANAGER_TYPE = typename Member<H,M>::MANAGER_TYPE;
                using VOID_TYPE = typename Member<H,M>::VOID_TYPE;
                using HOLDER_TYPE = typename Member<H,M>::HOLDER_TYPE;
				
				Object(){
					ObjectLog(higgs_Log_StartMethod, "Contructor", "println","");
					ObjectLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Object(const Object<O,H,M>& a_obj){
					ObjectLog(higgs_Log_StartMethod, "Contructor", "println","const Object &a_Object");
                    this->setHolder(a_obj.getHolder());
					ObjectLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

                Object(const Member<H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "Constructor", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "Constructor", "println","holder doesnt have same base clase");
						return;
					}
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                Object(const Data<H>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "Constructor", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "Constructor", "println","holder doesnt have same base clase");
						return;
					}
                    if(!this->isMember(a_holder)){
                        ObjectLog(higgs_Log_EndMethod, "Constructor", "println","holder isnt member");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Object(const Pointer<P,H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "Constructor", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "void operator=", "println","holder doesnt have same base clase");
						return;
					}
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Object(const Value<P,H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "Constructor", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "void operator=", "println","holder doesnt have same base clase");
						return;
					}
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                template<class P>
                Object(const P& a_value){
                    ObjectLog(higgs_Log_StartMethod, "Constructor", "println","value constructor");

					if(is_base_of<MemoryHolder<H>, P>::value){
						this->copyType(&a_value);
                    	ObjectLog(higgs_Log_EndMethod, "Constructor", "println","memoryholder asignment");
						return;
					}

					if(is_base_of<O, P>::value){
						this->create<P>();
						this->setValue<P>(a_value);
                    	ObjectLog(higgs_Log_EndMethod, "Constructor", "println","object asignment");
						return;
					}

                    ObjectLog(higgs_Log_EndMethod, "Constructor", "println","no initialization");
                }

				virtual ~Object(){
					ObjectLog(higgs_Log_StartMethod, "Destructor", "println","");
					ObjectLog(higgs_Log_EndMethod, "Destructor", "println","");
				}

                void copyType(const void* a_holder){
                    ObjectLog(higgs_Log_StartMethod, "copyMemoryHolder", "println","fix");
                    const MemoryHolder<H>* i_holder = (const MemoryHolder<H>*)a_holder;
					if(i_holder == nullptr){
						return;
					}
					if(ClassCount<O>::get() != i_holder->getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "copyMemoryHolder", "println","holder doesnt have same base clase");
						return;
					}
					this->copyMemoryHolder(*i_holder);
                    ObjectLog(higgs_Log_EndMethod, "copyMemoryHolder", "println","");
                }

				template<class P>
                void create(){
					ObjectLog(higgs_Log_StartMethod, "create", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr){
					    ObjectLog(higgs_Log_EndMethod, "create", "println","");
                        return;
                    }
                    ObjectLog(higgs_Log_Statement, "create", "println","creating new instance");
                    HOLDER_TYPE i_holder = MemoryHolderManager<H>::newInstance(this->getManager(), ClassCount<P>::get(), sizeOfPointer<P>(), StaticAllocatorInstance<P>::getAllocator());
                    this->setHolder(i_holder);
					this->setBaseType(ClassCount<O>::get());
					ObjectLog(higgs_Log_EndMethod, "create", "println","");
				}

				template<class P>
				void setValue(P a_value){
					ObjectLog(higgs_Log_StartMethod, "setValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer != nullptr && this->getType() == ClassCount<P>::get()){
						P* i_value_1 = (P*)i_pointer;
					    ObjectLog(higgs_Log_Statement, "setValue", "println","asign value with assignment operator");
						*i_value_1 = a_value;
					}
					ObjectLog(higgs_Log_EndMethod, "setValue", "println","");
				}

				template<class P>
				P getValue(){
					ObjectLog(higgs_Log_StartMethod, "getValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();

					ObjectLog(higgs_Log_Statement, "getValue", "println", "Is Holder == nullptr");
					ObjectLog(higgs_Log_Statement, "getValue", "println", this->m_holder == nullptr);
					if(i_pointer != nullptr){
						if(this->getType() == ClassCount<P>::get() || this->getBaseType() == ClassCount<P>::get()){
							ObjectLog(higgs_Log_Statement, "getValue", "println", "i_pointer != nullptr");
							//ObjectLog(higgs_Log_EndMethod, "getValue", "println", *((P*)i_pointer));
							return *((P*)i_pointer);
						}
					}
					ObjectLog(higgs_Log_EndMethod, "getValue", "println","");
					return P();
				}

				template<class P>
				bool isValidObject(){
					ObjectLog(higgs_Log_StartMethod, "isValidObject", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					if(i_pointer == nullptr){
						ObjectLog(higgs_Log_EndMethod, "isValidObject", "println", "notValidObject");
						return false;
					}
					ObjectLog(higgs_Log_Statement, "isValidObject", "println","");
					if(this->getType() == ClassCount<P>::get()){
						ObjectLog(higgs_Log_EndMethod, "isValidObject", "println", "isValidObject");
						return true;
					}
					ObjectLog(higgs_Log_EndMethod, "isValidObject", "println","notValidObject");
					return false;
				}

				template<class P>
				P& getReference(){
					ObjectLog(higgs_Log_StartMethod, "getValue", "println","");
					VOID_TYPE i_pointer = this->getRawPointer();
					ObjectLog(higgs_Log_EndMethod, "getValue", "println","");
					return *((P*)i_pointer);
				}

				//unsafe method
				virtual INSTANCE_TYPE operator ->(){
					ObjectLog(higgs_Log_StartMethod, "operator ->", "println","");
					ObjectLog(higgs_Log_EndMethod, "operator ->", "println","");
					return (INSTANCE_TYPE)MemoryHolderManager<H>::get(StaticManagerInstance<H,M>::getManager(), this->getHolder());
				}

                void operator=(const Object<O,H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "void operator=", "println","");
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "void operator=", "println","");
                }

                void operator=(const Member<H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "void operator=", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "void operator=", "println","holder doesnt have same base clase");
						return;
					}
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "void operator=", "println","");
                }

                void operator=(const Data<H>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "void operator=", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "void operator=", "println","holder doesnt have same base clase");
						return;
					}
                    if(!this->isMember(a_holder)){
                        ObjectLog(higgs_Log_EndMethod, "void operator=", "println","holder isnt member");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "void operator=", "println","");
                }

                template<class P>
                void operator=(const Pointer<P,H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "void operator=", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "void operator=", "println","holder doesnt have same base clase");
						return;
					}
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "void operator=", "println","");
                }

                template<class P>
                void operator=(const Value<P,H,M>& a_holder){
                    ObjectLog(higgs_Log_StartMethod, "void operator=", "println","");
					if(ClassCount<O>::get() != a_holder.getBaseType()){
                    	ObjectLog(higgs_Log_StartMethod, "void operator=", "println","holder doesnt have same base clase");
						return;
					}
                    this->setHolder(a_holder.getHolder());
                    ObjectLog(higgs_Log_EndMethod, "void operator=", "println","");
                }


                template<class P>
                void operator=(const P& a_value){
                    ObjectLog(higgs_Log_StartMethod, "operator=", "println","");

					if(is_base_of<MemoryHolder<H>, P>::value){
						this->copyType(&a_value);
                    	ObjectLog(higgs_Log_EndMethod, "Constructor", "println","memoryholder asignment");
						return;
					}

					if(is_base_of<O, P>::value){
						VOID_TYPE i_pointer = this->getRawPointer();
						if(i_pointer == nullptr){
							this->create<P>();
						}
						this->setValue<P>(a_value);
                    	ObjectLog(higgs_Log_EndMethod, "Constructor", "println","object asignment");
						return;
					}

                    ObjectLog(higgs_Log_EndMethod, "operator=", "println","");
                }

				template<class... Args>
				void invoke(char* a_method, Args... args){
					ObjectLog(higgs_Log_StartMethod, "create", "println","");
					
					ObjectLog(higgs_Log_EndMethod, "create", "println","");
				}

			protected:
		};

        template<class O, class H, class M>
        Object<O,H,M> Var(const Member<H,M>& a_holder){
            Object<O,H,M> i_obj;
            i_obj.copyMember(a_holder);
            return i_obj;
        }

        template<class O, class H, class M>
        Object<O,H,M> VarMemoryHolder(const MemoryHolder<H>& a_holder){
            Object<O,H,M> i_obj;
            i_obj.copyMemoryHolder(a_holder);
            return i_obj;
        }

        // template<>
        // template<>
        // void MemoryHolder<UniversalHolder>::copyType<MemoryHolder<UniversalHolder>>(const MemoryHolder<UniversalHolder>& a_holder){
        //     MemoryHolderLog(higgs_Log_StartMethod, "copyMemoryHolder", "println","");
        //     if(!this->isMember(a_holder)){
        //         MemoryHolderLog(higgs_Log_Error, "copyMemoryHolder", "println", "Variable is not Member of Variable");
        //         MemoryHolderLog(higgs_Log_EndMethod, "copyMemoryHolder", "println","");
        //         return;
        //     }
        //     this->setHolder(a_holder.getHolder());
        //     MemoryHolderLog(higgs_Log_EndMethod, "copyMemoryHolder", "println","");
        // }

	}

#endif