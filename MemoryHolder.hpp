
#ifndef MemoryHolder_hpp
	#define MemoryHolder_hpp

    #include "MemoryManager.hpp"
	#include "MemoryHolderManager.hpp"

    #ifdef MemoryHolder_LogApp
        #include "pankey_Logger.hpp"
        #define MemoryHolderLog(location,method,type,mns) pankey_Log(nullptr,location,"MemoryHolder",method,type,mns)
    #else
        #define MemoryHolderLog(location,method,type,mns)
    #endif

	namespace pankey{

        template<class H>
        class MemoryHolder{
            public:
				using HOLDER_TYPE = H*;

                using MANAGER_TYPE = MemoryManager<H>*;
                using VOID_TYPE = void*;
                
                virtual ~MemoryHolder(){
                    MemoryHolderLog(pankey_Log_StartMethod, "Destructor", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "Destructor", "println","");
                }

                virtual void remove(){
                    MemoryHolderLog(pankey_Log_StartMethod, "remove", "println","");
                    MemoryHolderManager<H>::remove(this->getManager(), m_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "remove", "println","");
                }

                virtual void destroy(){
                    MemoryHolderLog(pankey_Log_StartMethod, "destroy", "println","");
                    MemoryHolderManager<H>::destroy(this->getManager(), m_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "destroy", "println","");
                }
                    
                //unsafe method
                virtual void setHolder(HOLDER_TYPE a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "setHolder", "println","");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), m_holder);
					m_holder = a_holder;
                    MemoryHolderLog(pankey_Log_EndMethod, "setHolder", "println","");
                }

                //unsafe method
                virtual HOLDER_TYPE getHolder()const{
                    return m_holder;
                }

                virtual HOLDER_TYPE& getHolderReference(){
                    return m_holder;
                }

                virtual bool isHolderNull()const{
                    return m_holder == nullptr;
                }
                    
                virtual void setManager(MANAGER_TYPE a_llocator){
                    MemoryHolderLog(pankey_Log_StartMethod, "setManager", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "setManager", "println","");
                }

                virtual MANAGER_TYPE getManager()const=0;

                virtual bool isManagerNull()const{
                    return this->getManager() == nullptr;
                }

                virtual void copyMemoryHolder(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "copyMemoryHolder", "println","");
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "copyMemoryHolder", "println","");
                }

				virtual bool shareManager(MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "shareManager", "println","");
                    if(a_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "println","The variable cheching has no Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    auto i_manager = this->getManager();
                    if(i_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "println","MemoryHolder doesnt have Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println",a_manager == i_manager);
                    return a_manager == i_manager;
				}

				virtual bool shareManager(const MemoryHolder<H>& a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "shareManager", "println","");
                    auto i_manager_in = a_holder.getManager();
                    if(i_manager_in == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "println","The variable cheching has no Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    auto i_manager = this->getManager();
                    if(i_manager == nullptr){
                        MemoryHolderLog(pankey_Log_Error, "shareManager", "println","MemoryHolder doesnt have Manager");
                        MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "shareManager", "println",i_manager_in == i_manager);
                    return i_manager_in == i_manager;
				}

				virtual bool sameType(long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "sameType", "println","");
                    MemoryHolderLog(pankey_Log_Statement, "sameType", "println","a_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameType", "println",a_type);
                    if(a_type == -1){
                        MemoryHolderLog(pankey_Log_Error, "sameType", "println","The variable cheching has no type");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    long i_type = this->getType();
                    MemoryHolderLog(pankey_Log_Statement, "sameType", "println","i_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameType", "println",i_type);
                    if(i_type == -1){
                        MemoryHolderLog(pankey_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "sameType", "println",i_type == a_type);
                    return i_type == a_type;
				}

				virtual bool sameBaseType(long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "sameBaseType", "println","");
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", "println","a_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", "println",a_type);
                    if(a_type == -1){
                        MemoryHolderLog(pankey_Log_Error, "sameBaseType", "println","The variable cheching has no type");
                        MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    long i_type = this->getBaseType();
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", "println","i_type:");
                    MemoryHolderLog(pankey_Log_Statement, "sameBaseType", "println",i_type);
                    if(i_type == -1){
                        MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    MemoryHolderLog(pankey_Log_EndMethod, "sameBaseType", "println",i_type == a_type);
                    return i_type == a_type;
				}

				virtual bool isMember(MANAGER_TYPE a_manager, long a_type)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","MANAGER_TYPE a_manager, long a_type");
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return (this->sameType(a_type) || this->sameBaseType(a_type)) && this->shareManager(a_manager);
				}

				virtual bool isMember(HOLDER_TYPE a_holder, MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","HOLDER_TYPE a_holder, MANAGER_TYPE a_manage");
                    auto i_type = MemoryHolderManager<H>::getType(a_manager, a_holder);
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->isMember(a_manager, i_type);
                }

				virtual bool isMember(HOLDER_TYPE a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","HOLDER_TYPE a_holder");
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->isMember(a_holder, this->getManager());
                }

				virtual bool isMember(const MemoryHolder<H>& a_holder)const{
                    MemoryHolderLog(pankey_Log_StartMethod, "isMember", "println","const MemoryHolder<H>& a_holder");
                    auto i_manager = a_holder.getManager();
                    auto i_type = a_holder.getType();
                    MemoryHolderLog(pankey_Log_EndMethod, "isMember", "println","");
                    return this->isMember(i_manager, i_type);
                }

				virtual void setType(long a_type){
                    MemoryHolderLog(pankey_Log_StartMethod, "setType", "println","");
					MemoryHolderManager<H>::setType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(pankey_Log_EndMethod, "setType", "println","");
				}

				virtual long getType()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getType", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "getType", "println","");
					return MemoryHolderManager<H>::getType(this->getManager(), this->m_holder);
				}

				virtual void setBaseType(long a_type){
                    MemoryHolderLog(pankey_Log_StartMethod, "setBaseType", "println","");
					MemoryHolderManager<H>::setBaseType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(pankey_Log_EndMethod, "setBaseType", "println","");
				}

				virtual long getBaseType()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getBaseType", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "getBaseType", "println","");
					return MemoryHolderManager<H>::getBaseType(this->getManager(), this->m_holder);
				}

				virtual bool isMemoryNull()const{
					MemoryHolderLog(pankey_Log_StartMethod, "isMemoryNull", "println","");
					if(m_holder == nullptr){
						MemoryHolderLog(pankey_Log_EndMethod, "isMemoryNull", "println","m_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "isMemoryNull", "println", "isNull: ");
					MemoryHolderLog(pankey_Log_Statement, "isMemoryNull", "println", i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "isMemoryNull", "println","");
					return i_pointer == nullptr;
				}

				virtual bool isNull()const{
					MemoryHolderLog(pankey_Log_StartMethod, "isNull", "println","");
					if(m_holder == nullptr){
						MemoryHolderLog(pankey_Log_EndMethod, "isNull", "println","m_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "isNull", "println", "isNull: ");
					MemoryHolderLog(pankey_Log_Statement, "isNull", "println", i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "isNull", "println","");
					return i_pointer == nullptr;
				}

				//unsafe method
				virtual VOID_TYPE getRawPointer()const{
                    MemoryHolderLog(pankey_Log_StartMethod, "getRawPointer", "println","");
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(pankey_Log_Statement, "getRawPointer", "println","VOID_TYPE is null?");
					MemoryHolderLog(pankey_Log_Statement, "getRawPointer", "println", i_pointer == nullptr);
					MemoryHolderLog(pankey_Log_EndMethod, "getRawPointer", "println","");
					return i_pointer;
				}

                virtual void operator=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator=", "println","");
                    if(!this->shareManager(a_holder)){
                        MemoryHolderLog(pankey_Log_Error, "operator=", "println", "MemoryHolder is not Member of Variable");
                        MemoryHolderLog(pankey_Log_EndMethod, "operator=", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(pankey_Log_EndMethod, "operator=", "println","");
                }

                virtual bool operator==(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator==", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "operator==", "println", this->getHolder() == a_holder.getHolder());
                    return this->getHolder() == a_holder.getHolder();
                }

                virtual bool operator!=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(pankey_Log_StartMethod, "operator!=", "println","");
                    MemoryHolderLog(pankey_Log_EndMethod, "operator!=", "println", this->getHolder() != a_holder.getHolder());
                    return this->getHolder() != a_holder.getHolder();
                }

            protected:

                HOLDER_TYPE m_holder = nullptr;
            
        };

	}

#endif