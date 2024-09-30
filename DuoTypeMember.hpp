
#ifndef DuoTypeMember_hpp
	#define DuoTypeMember_hpp

	#include "Member.hpp"
	#include "ClassCount.hpp"

	#ifdef DuoTypeMember_LogApp
		#include "pankey_Logger.hpp"
		#define DuoTypeMemberLog(location,method,type,mns) pankey_Log((void*)this,location,"DuoTypeMember",method,type,mns)
	#else
		#define DuoTypeMemberLog(location,method,type,mns)
	#endif

	namespace pankey{

		template <class K, class V, class H, class M>
		class DuoTypeMember : public Member<H,M>{
			public:

                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using VOID_TYPE = typename MemoryHolder<H>::VOID_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;

				DuoTypeMember(){
					DuoTypeMemberLog(pankey_Log_StartMethod, "Constructor", "println", "");
					DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				DuoTypeMember(Member<H,M> c_holder_0, Member<H,M> c_holder_1){
					DuoTypeMemberLog(pankey_Log_StartMethod, "Constructor", "println", "");
                    if(c_holder_0.sameType(ClassCount<K>::get()) || c_holder_0.sameBaseType(ClassCount<K>::get())){
                        this->setHolder(c_holder_0.getHolder());
                    }
                    if(c_holder_1.sameType(ClassCount<V>::get()) || c_holder_1.sameBaseType(ClassCount<V>::get())){
                        this->setDuoTypeHolder(c_holder_1.getHolder());
                    }
					DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				DuoTypeMember(const DuoTypeMember<K,V,H,M>& c_duo_holder){
					DuoTypeMemberLog(pankey_Log_StartMethod, "Constructor", "println", "");
                    this->setHolder(c_duo_holder.getHolder());
                    this->setDuoTypeHolder(c_duo_holder.getDuoTypeHolder());
					DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~DuoTypeMember(){
					DuoTypeMemberLog(pankey_Log_StartMethod, "Destructor", "println", "");
					this->removeDuoType();
					DuoTypeMemberLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

                virtual void copyMemoryHolder(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "copyMemoryHolder", "println","");
                    if(a_holder.isMember(this->getManager(), ClassCount<K>::get())){
                        this->setHolder(a_holder.getHolder());
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "copyMemoryHolder", "println","");
                }

                virtual void copyMember(const Member<H,M>& a_holder){
                    MemberLog(pankey_Log_StartMethod, "copyMember", "println","");
                    if(a_holder.sameType(ClassCount<K>::get()) || a_holder.sameBaseType(ClassCount<K>::get())){
                        this->setHolder(a_holder.getHolder());
                    }
                    MemberLog(pankey_Log_EndMethod, "copyMember", "println","");
                }

                virtual void copyDuoTypeMember(const Member<H,M>& a_holder){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "copyDuoTypeMember", "println","");
                    if(a_holder.sameType(ClassCount<V>::get()) || a_holder.sameBaseType(ClassCount<V>::get())){
                        this->setDuoTypeHolder(a_holder.getHolder());
                    }
                    DuoTypeMemberLog(pankey_Log_EndMethod, "copyDuoTypeMember", "println","");
                }

                virtual Member<H,M> getDuoTypeMember(){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "getDuoTypeMember", "println","");
                    Member<H,M> i_member;
                    i_member.setHolder(this->m_duo_holder);
                    DuoTypeMemberLog(pankey_Log_EndMethod, "getDuoTypeMember", "println","");
                    return i_member;
                }

                virtual void removeDuoType(){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "removeDuoType", "println","");
                    MemoryHolderManager<H>::remove(this->getManager(), this->m_duo_holder);
                    DuoTypeMemberLog(pankey_Log_EndMethod, "removeDuoType", "println","");
                }

                virtual void destroyDuoType(){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "destroyDuoType", "println","");
                    MemoryHolderManager<H>::destroy(this->getManager(), this->m_duo_holder);
                    DuoTypeMemberLog(pankey_Log_EndMethod, "destroyDuoType", "println","");
                }
                    
                //unsafe method
                virtual void setDuoTypeHolder(HOLDER_TYPE a_holder){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "setDuoTypeHolder", "println","");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), this->m_duo_holder);
					this->m_duo_holder = a_holder;
                    DuoTypeMemberLog(pankey_Log_EndMethod, "setDuoTypeHolder", "println","");
                }

                //unsafe method
                virtual HOLDER_TYPE getDuoTypeHolder()const{
                    return this->m_duo_holder;
                }

                virtual HOLDER_TYPE& getDuoTypeHolderReference(){
                    return this->m_duo_holder;
                }

                virtual bool isDuoTypeHolderNull()const{
                    return this->m_duo_holder == nullptr;
                }

                virtual void copyDuoTypeMemoryHolder(const MemoryHolder<H>& a_holder){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "copyDuoTypeMemoryHolder", "println","");
                    if(a_holder.sameType(ClassCount<V>::get()) || a_holder.sameBaseType(ClassCount<V>::get())){
                        this->setDuoTypeHolder(a_holder.getHolder());
                    }
                    DuoTypeMemberLog(pankey_Log_EndMethod, "copyDuoTypeMemoryHolder", "println","");
                }

				virtual bool sameDuoType(long a_type)const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "sameDuoType", "println","");
                    if(a_type == -1){
                        DuoTypeMemberLog(pankey_Log_Error, "sameDuoType", "println","a_type == -1");
                        DuoTypeMemberLog(pankey_Log_EndMethod, "sameDuoType", "println","");
                        return false;
                    }
                    long i_type = this->getDuoType();
                    if(i_type == -1){
                        DuoTypeMemberLog(pankey_Log_Error, "sameDuoType", "println","i_type != -1");
                        DuoTypeMemberLog(pankey_Log_EndMethod, "sameDuoType", "println","");
                        return false;
                    }
                    DuoTypeMemberLog(pankey_Log_EndMethod, "sameDuoType", "println","");
                    return i_type == a_type;
				}

				virtual bool sameDuoBaseType(long a_type)const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "sameDuoBaseType", "println","");
                    if(a_type == -1){
                        DuoTypeMemberLog(pankey_Log_Error, "sameDuoBaseType", "println","a_type == -1");
                        DuoTypeMemberLog(pankey_Log_EndMethod, "sameDuoBaseType", "println","");
                        return false;
                    }
                    long i_type = this->getDuoBaseType();
                    if(i_type == -1){
                        DuoTypeMemberLog(pankey_Log_Error, "sameDuoBaseType", "println","i_type == -1");
                        DuoTypeMemberLog(pankey_Log_EndMethod, "sameDuoBaseType", "println","");
                        return false;
                    }
                    DuoTypeMemberLog(pankey_Log_EndMethod, "sameDuoBaseType", "println","");
                    return i_type == a_type;
				}

				virtual bool isDuoTypeMember(MANAGER_TYPE a_manager, long a_type)const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "isDuoTypeMember", "println","");
                    DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMember", "println","");
                    return this->shareManager(a_manager) && (this->sameDuoType(a_type) || this->sameDuoBaseType(a_type));
				}

				virtual bool isDuoTypeMember(HOLDER_TYPE a_holder, MANAGER_TYPE a_manager)const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "isDuoTypeMember", "println","");
                    auto i_type = MemoryHolderManager<H>::getType(a_manager, a_holder);
                    DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMember", "println","");
                    return this->isDuoTypeMember(a_manager, i_type);
                }

				virtual bool isDuoTypeMember(HOLDER_TYPE a_holder)const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "isDuoTypeMember", "println","");
                    DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMember", "println","");
                    return this->isDuoTypeMember(a_holder, this->getManager());
                }

				virtual bool isDuoTypeMember(const MemoryHolder<H>& a_holder)const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "isDuoTypeMember", "println","");
                    auto i_manager = a_holder.getManager();
                    auto i_type = a_holder.getType();
                    DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMember", "println","");
                    return this->isDuoTypeMember(i_manager, i_type);
                }

				virtual void setDuoType(long a_type){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "setDuoType", "println","");
					MemoryHolderManager<H>::setType(this->getManager(), this->m_duo_holder, a_type);
                    DuoTypeMemberLog(pankey_Log_EndMethod, "setDuoType", "println","");
				}

				virtual long getDuoType()const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "getDuoType", "println","");
                    DuoTypeMemberLog(pankey_Log_EndMethod, "getDuoType", "println","");
					return MemoryHolderManager<H>::getType(this->getManager(), this->m_duo_holder);
				}

				virtual void setDuoBaseType(long a_type){
                    DuoTypeMemberLog(pankey_Log_StartMethod, "setDuoBaseType", "println","");
					MemoryHolderManager<H>::setBaseType(this->getManager(), this->m_duo_holder, a_type);
                    DuoTypeMemberLog(pankey_Log_EndMethod, "setDuoBaseType", "println","");
				}

				virtual long getDuoBaseType()const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "getDuoBaseType", "println","");
                    DuoTypeMemberLog(pankey_Log_EndMethod, "getDuoBaseType", "println","");
					return MemoryHolderManager<H>::getBaseType(this->getManager(), this->m_duo_holder);
				}

				virtual bool isDuoTypeMemoryNull()const{
					DuoTypeMemberLog(pankey_Log_StartMethod, "isDuoTypeMemoryNull", "println","");
					if(this->m_duo_holder == nullptr){
						DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMemoryNull", "println","this->m_duo_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), this->m_duo_holder);
					DuoTypeMemberLog(pankey_Log_Statement, "isDuoTypeMemoryNull", "println", "isDuoNull: ");
					DuoTypeMemberLog(pankey_Log_Statement, "isDuoTypeMemoryNull", "println", i_pointer == nullptr);
					DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMemoryNull", "println","");
					return i_pointer == nullptr;
				}

				//unsafe method
				virtual VOID_TYPE getDuoTypeRawPointer()const{
                    DuoTypeMemberLog(pankey_Log_StartMethod, "getDuoTypeRawPointer", "println","");
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), this->m_duo_holder);
					DuoTypeMemberLog(pankey_Log_Statement, "getDuoTypeRawPointer", "println","VOID_TYPE is null?");
					DuoTypeMemberLog(pankey_Log_Statement, "getDuoTypeRawPointer", "println", i_pointer == nullptr);
					DuoTypeMemberLog(pankey_Log_EndMethod, "getDuoTypeRawPointer", "println","");
					return i_pointer;
				}
				
				virtual DuoTypeMember<K,V,H,M>& operator=(const DuoTypeMember<K,V,H,M>& a_duo_member){
					DuoTypeMemberLog(pankey_Log_StartMethod, "operator=", "println", "");
                    this->setHolder(a_duo_member.getHolder());
                    this->setDuoTypeHolder(a_duo_member.getDuoTypeHolder());
					DuoTypeMemberLog(pankey_Log_EndMethod, "operator=", "println", "");
					return *this;
				}
				
				virtual void operator=(const MemoryHolder<H>& a_holder){
					DuoTypeMemberLog(pankey_Log_StartMethod, "operator=", "println", "");
                    if(a_holder.sameType(ClassCount<K>::get()) || a_holder.sameBaseType(ClassCount<K>::get())){
                        this->setHolder(a_holder.getHolder());
                        DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    if(a_holder.sameType(ClassCount<V>::get()) || a_holder.sameBaseType(ClassCount<V>::get())){
                        this->setDuoTypeHolder(a_holder.getHolder());
                        DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
					DuoTypeMemberLog(pankey_Log_EndMethod, "operator=", "println", "");
                }
				
				virtual void operator=(const Member<H,M>& a_holder){
					DuoTypeMemberLog(pankey_Log_StartMethod, "operator=", "println", "");
                    if(a_holder.sameType(ClassCount<K>::get()) || a_holder.sameBaseType(ClassCount<K>::get())){
                        this->setHolder(a_holder.getHolder());
                        DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    if(a_holder.sameType(ClassCount<V>::get()) || a_holder.sameBaseType(ClassCount<V>::get())){
                        this->setDuoTypeHolder(a_holder.getHolder());
                        DuoTypeMemberLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
					DuoTypeMemberLog(pankey_Log_EndMethod, "operator=", "println", "");
                }
				
				virtual bool operator!=(const DuoTypeMember<K,V,H,M>& a_duo_member){
					DuoTypeMemberLog(pankey_Log_StartMethod, "operator!=", "println", "");
					DuoTypeMemberLog(pankey_Log_EndMethod, "operator!=", "println", "");
                    return this->getHolder() == a_duo_member.getHolder() && this->getDuoTypeHolder() == a_duo_member.getDuoTypeHolder();
				}
				
				virtual bool operator==(const DuoTypeMember<K,V,H,M>& a_duo_member){
					DuoTypeMemberLog(pankey_Log_StartMethod, "operator==", "println", "");
					DuoTypeMemberLog(pankey_Log_EndMethod, "operator==", "println", "");
                    return this->getHolder() != a_duo_member.getHolder() && this->getDuoTypeHolder() != a_duo_member.getDuoTypeHolder();
				}
				
				virtual bool isNull()const{
					DuoTypeMemberLog(pankey_Log_StartMethod, "isDuoTypeMemberNull", "println", "");
					DuoTypeMemberLog(pankey_Log_EndMethod, "isDuoTypeMemberNull", "println", "");
					return this->isMemoryNull() && this->isDuoTypeMemoryNull();
				}
			
			protected:

                HOLDER_TYPE m_duo_holder = nullptr;
		};

	}

#endif