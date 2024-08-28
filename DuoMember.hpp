
#ifndef DuoMember_hpp
	#define DuoMember_hpp

	#include "Member.hpp"

	#ifdef DuoMember_LogApp
		#include "pankey_Logger.hpp"
		#define DuoMemberLog(location,method,type,mns) pankey_Log((void*)this,location,"DuoMember",method,type,mns)
	#else
		#define DuoMemberLog(location,method,type,mns)
	#endif

	namespace pankey{

		template <class H, class M>
		class DuoMember : public Member<H,M>{
			public:

                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using VOID_TYPE = typename MemoryHolder<H>::VOID_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;

				DuoMember(){
					DuoMemberLog(pankey_Log_StartMethod, "Constructor", "println", "");
					DuoMemberLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}

                DuoMember(const MemoryHolder<H>& a_holder){
                    DuoMemberLog(pankey_Log_StartMethod, "Constructor", "println","");
                    if(!this->isMember(a_holder)){
                        DuoMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    DuoMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                DuoMember(const Member<H,M>& a_holder){
                    DuoMemberLog(pankey_Log_StartMethod, "Constructor", "println","");
                    this->setHolder(a_holder.getHolder());
                    DuoMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                }
				
				DuoMember(Member<H,M> c_holder_0, Member<H,M> c_holder_1){
					DuoMemberLog(pankey_Log_StartMethod, "Constructor", "println", "");
                    this->setHolder(c_holder_0.getHolder());
                    this->setDuoHolder(c_holder_1.getHolder());
					DuoMemberLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				DuoMember(const DuoMember<H,M>& c_duo_holder){
					DuoMemberLog(pankey_Log_StartMethod, "Constructor", "println", "");
                    this->setHolder(c_duo_holder.getHolder());
                    this->setDuoHolder(c_duo_holder.getDuoHolder());
					DuoMemberLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~DuoMember(){
					DuoMemberLog(pankey_Log_StartMethod, "Destructor", "println", "");
					this->removeDuo();
					DuoMemberLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

                virtual void copyDuoMember(const Member<H,M>& a_holder){
                    DuoMemberLog(pankey_Log_StartMethod, "copyDuoMember", "println","");
                    this->setDuoHolder(a_holder.getHolder());
                    DuoMemberLog(pankey_Log_EndMethod, "copyDuoMember", "println","");
                }

                virtual Member<H,M> getDuoMember(){
                    DuoMemberLog(pankey_Log_StartMethod, "getDuoMember", "println","");
                    Member<H,M> i_member;
                    i_member.setHolder(this->m_duo_holder);
                    DuoMemberLog(pankey_Log_EndMethod, "getDuoMember", "println","");
                    return i_member;
                }

                virtual void removeDuo(){
                    DuoMemberLog(pankey_Log_StartMethod, "remove", "println","");
                    MemoryHolderManager<H>::remove(this->getManager(), this->m_duo_holder);
                    DuoMemberLog(pankey_Log_EndMethod, "remove", "println","");
                }

                virtual void destroyDuo(){
                    DuoMemberLog(pankey_Log_StartMethod, "destroy", "println","");
                    MemoryHolderManager<H>::destroy(this->getManager(), this->m_duo_holder);
                    DuoMemberLog(pankey_Log_EndMethod, "destroy", "println","");
                }
                    
                //unsafe method
                virtual void setDuoHolder(HOLDER_TYPE a_holder){
                    DuoMemberLog(pankey_Log_StartMethod, "setDuoHolder", "println","");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), this->m_duo_holder);
					this->m_duo_holder = a_holder;
                    DuoMemberLog(pankey_Log_EndMethod, "setDuoHolder", "println","");
                }

                //unsafe method
                virtual HOLDER_TYPE getDuoHolder()const{
                    return this->m_duo_holder;
                }

                virtual HOLDER_TYPE& getDuoHolderReference(){
                    return this->m_duo_holder;
                }

                virtual bool isDuoHolderNull()const{
                    return this->m_duo_holder == nullptr;
                }

                virtual void copyDuoMemoryHolder(const MemoryHolder<H>& a_holder){
                    DuoMemberLog(pankey_Log_StartMethod, "copyDuoMemoryHolder", "println","");
                    if(!this->isDuoMember(a_holder)){
                        DuoMemberLog(pankey_Log_Error, "copyDuoMemoryHolder", "println", "Variable is not Member of Variable");
                        DuoMemberLog(pankey_Log_EndMethod, "copyDuoMemoryHolder", "println","");
                        return;
                    }
                    this->setDuoHolder(a_holder.getHolder());
                    DuoMemberLog(pankey_Log_EndMethod, "copyDuoMemoryHolder", "println","");
                }

				virtual bool sameDuoType(long a_type)const{
                    DuoMemberLog(pankey_Log_StartMethod, "sameDuoType", "println","");
                    if(a_type == -1){
                        DuoMemberLog(pankey_Log_Error, "sameDuoType", "println","The variable cheching has no type");
                        DuoMemberLog(pankey_Log_EndMethod, "sameDuoType", "println","");
                        return false;
                    }
                    long i_type = this->getDuoType();
                    if(i_type != a_type && i_type != -1){
                        DuoMemberLog(pankey_Log_Error, "sameDuoType", "println","Not a memeber because it has diferent types");
                        DuoMemberLog(pankey_Log_EndMethod, "sameDuoType", "println","");
                        return false;
                    }
                    DuoMemberLog(pankey_Log_EndMethod, "sameDuoType", "println","");
                    return true;
				}

				virtual bool sameDuoBaseType(long a_type)const{
                    DuoMemberLog(pankey_Log_StartMethod, "sameDuoBaseType", "println","");
                    if(a_type == -1){
                        DuoMemberLog(pankey_Log_Error, "sameDuoBaseType", "println","The variable cheching has no type");
                        DuoMemberLog(pankey_Log_EndMethod, "sameDuoBaseType", "println","");
                        return false;
                    }
                    long i_type = this->getDuoBaseType();
                    if(i_type != a_type && i_type != -1){
                        DuoMemberLog(pankey_Log_Error, "sameDuoBaseType", "println","Not a memeber because it has diferent types");
                        DuoMemberLog(pankey_Log_EndMethod, "sameDuoBaseType", "println","");
                        return false;
                    }
                    DuoMemberLog(pankey_Log_EndMethod, "sameDuoBaseType", "println","");
                    return true;
				}

				virtual bool isDuoMember(MANAGER_TYPE a_manager, long a_type)const{
                    DuoMemberLog(pankey_Log_StartMethod, "isDuoMember", "println","");
                    DuoMemberLog(pankey_Log_EndMethod, "isDuoMember", "println","");
                    return this->shareManager(a_manager) && this->sameDuoType(a_type);
				}

				virtual bool isDuoMember(HOLDER_TYPE a_holder, MANAGER_TYPE a_manager)const{
                    DuoMemberLog(pankey_Log_StartMethod, "isDuoMember", "println","");
                    auto i_type = MemoryHolderManager<H>::getType(a_manager, a_holder);
                    DuoMemberLog(pankey_Log_EndMethod, "isDuoMember", "println","");
                    return this->isDuoMember(a_manager, i_type);
                }

				virtual bool isDuoMember(HOLDER_TYPE a_holder)const{
                    DuoMemberLog(pankey_Log_StartMethod, "isDuoMember", "println","");
                    DuoMemberLog(pankey_Log_EndMethod, "isDuoMember", "println","");
                    return this->isDuoMember(a_holder, this->getManager());
                }

				virtual bool isDuoMember(const MemoryHolder<H>& a_holder)const{
                    DuoMemberLog(pankey_Log_StartMethod, "isDuoMember", "println","");
                    auto i_manager = a_holder.getManager();
                    auto i_type = a_holder.getType();
                    DuoMemberLog(pankey_Log_EndMethod, "isDuoMember", "println","");
                    return this->isDuoMember(i_manager, i_type);
                }

				virtual void setDuoType(long a_type){
                    DuoMemberLog(pankey_Log_StartMethod, "setDuoType", "println","");
					MemoryHolderManager<H>::setType(this->getManager(), this->m_duo_holder, a_type);
                    DuoMemberLog(pankey_Log_EndMethod, "setDuoType", "println","");
				}

				virtual long getDuoType()const{
                    DuoMemberLog(pankey_Log_StartMethod, "getDuoType", "println","");
                    DuoMemberLog(pankey_Log_EndMethod, "getDuoType", "println","");
					return MemoryHolderManager<H>::getType(this->getManager(), this->m_duo_holder);
				}

				virtual void setDuoBaseType(long a_type){
                    DuoMemberLog(pankey_Log_StartMethod, "setDuoBaseType", "println","");
					MemoryHolderManager<H>::setBaseType(this->getManager(), this->m_duo_holder, a_type);
                    DuoMemberLog(pankey_Log_EndMethod, "setDuoBaseType", "println","");
				}

				virtual long getDuoBaseType()const{
                    DuoMemberLog(pankey_Log_StartMethod, "getDuoBaseType", "println","");
                    DuoMemberLog(pankey_Log_EndMethod, "getDuoBaseType", "println","");
					return MemoryHolderManager<H>::getBaseType(this->getManager(), this->m_duo_holder);
				}

				virtual bool isDuoMemoryNull()const{
					DuoMemberLog(pankey_Log_StartMethod, "isDuoMemoryNull", "println","");
					if(this->m_duo_holder == nullptr){
						DuoMemberLog(pankey_Log_EndMethod, "isDuoMemoryNull", "println","this->m_duo_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), this->m_duo_holder);
					DuoMemberLog(pankey_Log_Statement, "isDuoMemoryNull", "println", "isDuoNull: ");
					DuoMemberLog(pankey_Log_Statement, "isDuoMemoryNull", "println", i_pointer == nullptr);
					DuoMemberLog(pankey_Log_EndMethod, "isDuoMemoryNull", "println","");
					return i_pointer == nullptr;
				}

				//unsafe method
				virtual VOID_TYPE getDuoRawPointer()const{
                    DuoMemberLog(pankey_Log_StartMethod, "getDuoRawPointer", "println","");
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), this->m_duo_holder);
					DuoMemberLog(pankey_Log_Statement, "getDuoRawPointer", "println","VOID_TYPE is null?");
					DuoMemberLog(pankey_Log_Statement, "getDuoRawPointer", "println", i_pointer == nullptr);
					DuoMemberLog(pankey_Log_EndMethod, "getDuoRawPointer", "println","");
					return i_pointer;
				}
				
				virtual DuoMember& operator=(const DuoMember<H,M>& a_duo_member){
					DuoMemberLog(pankey_Log_StartMethod, "operator=", "println", "");
                    this->setDuoHolder(a_duo_member.getDuoHolder());
                    this->setHolder(a_duo_member.getHolder());
					DuoMemberLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
				
				virtual bool operator!=(const DuoMember<H,M>& a_duo_member){
					DuoMemberLog(pankey_Log_StartMethod, "operator!=", "println", "");
					DuoMemberLog(pankey_Log_EndMethod, "operator!=", "println", "");
                    return this->getHolder() == a_duo_member.getHolder() && this->getDuoHolder() == a_duo_member.getDuoHolder();
				}
				
				virtual bool operator==(const DuoMember<H,M>& a_duo_member){
					DuoMemberLog(pankey_Log_StartMethod, "operator==", "println", "");
					DuoMemberLog(pankey_Log_EndMethod, "operator==", "println", "");
                    return this->getHolder() != a_duo_member.getHolder() && this->getDuoHolder() != a_duo_member.getDuoHolder();
				}
				
				virtual bool isNull()const{
					DuoMemberLog(pankey_Log_StartMethod, "isDuoMemberNull", "println", "");
					DuoMemberLog(pankey_Log_EndMethod, "isDuoMemberNull", "println", "");
					return this->isMemoryNull() && this->isDuoMemoryNull();
				}
			
			protected:

                HOLDER_TYPE m_duo_holder = nullptr;
		};

	}

#endif