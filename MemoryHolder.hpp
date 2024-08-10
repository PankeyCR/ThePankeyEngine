
#ifndef MemoryHolder_hpp
	#define MemoryHolder_hpp

    #include "MemoryManager.hpp"
	#include "MemoryHolderManager.hpp"

    #ifdef MemoryHolder_LogApp
        #include "higgs_Logger.hpp"
        #define MemoryHolderLog(location,method,type,mns) higgs_Log(nullptr,location,"MemoryHolder",method,type,mns)
    #else
        #define MemoryHolderLog(location,method,type,mns)
    #endif

	namespace higgs{

        template<class H>
        class MemoryHolder{
            public:
				using HOLDER_TYPE = H*;

                using MANAGER_TYPE = MemoryManager<H>*;
                using VOID_TYPE = void*;
                
                virtual ~MemoryHolder(){
                    MemoryHolderLog(higgs_Log_StartMethod, "Destructor", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "Destructor", "println","");
                }

                virtual void remove(){
                    MemoryHolderLog(higgs_Log_StartMethod, "remove", "println","");
                    MemoryHolderManager<H>::remove(this->getManager(), m_holder);
                    MemoryHolderLog(higgs_Log_EndMethod, "remove", "println","");
                }

                virtual void destroy(){
                    MemoryHolderLog(higgs_Log_StartMethod, "destroy", "println","");
                    MemoryHolderManager<H>::destroy(this->getManager(), m_holder);
                    MemoryHolderLog(higgs_Log_EndMethod, "destroy", "println","");
                }
                    
                //unsafe method
                virtual void setHolder(HOLDER_TYPE a_holder){
                    MemoryHolderLog(higgs_Log_StartMethod, "setHolder", "println","");
					MemoryHolderManager<H>::add(this->getManager(), a_holder);
					MemoryHolderManager<H>::remove(this->getManager(), m_holder);
					m_holder = a_holder;
                    MemoryHolderLog(higgs_Log_EndMethod, "setHolder", "println","");
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
                    MemoryHolderLog(higgs_Log_StartMethod, "setManager", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "setManager", "println","");
                }

                virtual MANAGER_TYPE getManager()const=0;

                virtual bool isManagerNull()const{
                    return this->getManager() == nullptr;
                }

                virtual void copyMemoryHolder(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(higgs_Log_StartMethod, "copyMemoryHolder", "println","");
                    if(!this->isMember(a_holder)){
                        MemoryHolderLog(higgs_Log_Error, "copyMemoryHolder", "println", "Variable is not Member of Variable");
                        MemoryHolderLog(higgs_Log_EndMethod, "copyMemoryHolder", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(higgs_Log_EndMethod, "copyMemoryHolder", "println","");
                }

				virtual bool shareManager(MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "shareManager", "println","");
                    if(a_manager == nullptr){
                        MemoryHolderLog(higgs_Log_Error, "shareManager", "println","The variable cheching has no Manager");
                        MemoryHolderLog(higgs_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    auto i_manager = this->getManager();
                    if(i_manager != a_manager && i_manager != nullptr){
                        MemoryHolderLog(higgs_Log_Error, "shareManager", "println","Not a memeber because it has diferent Manager");
                        MemoryHolderLog(higgs_Log_EndMethod, "shareManager", "println","");
                        return false;
                    }
                    MemoryHolderLog(higgs_Log_EndMethod, "shareManager", "println","");
                    return true;
				}

				virtual bool sameType(long a_type)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "sameType", "println","");
                    if(a_type == -1){
                        MemoryHolderLog(higgs_Log_Error, "sameType", "println","The variable cheching has no type");
                        MemoryHolderLog(higgs_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    long i_type = this->getType();
                    if(i_type != a_type && i_type != -1){
                        MemoryHolderLog(higgs_Log_Error, "sameType", "println","Not a memeber because it has diferent types");
                        MemoryHolderLog(higgs_Log_EndMethod, "sameType", "println","");
                        return false;
                    }
                    MemoryHolderLog(higgs_Log_EndMethod, "sameType", "println","");
                    return true;
				}

				virtual bool sameBaseType(long a_type)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "sameBaseType", "println","");
                    if(a_type == -1){
                        MemoryHolderLog(higgs_Log_Error, "sameBaseType", "println","The variable cheching has no type");
                        MemoryHolderLog(higgs_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    long i_type = this->getBaseType();
                    if(i_type != a_type && i_type != -1){
                        MemoryHolderLog(higgs_Log_Error, "sameBaseType", "println","Not a memeber because it has diferent types");
                        MemoryHolderLog(higgs_Log_EndMethod, "sameBaseType", "println","");
                        return false;
                    }
                    MemoryHolderLog(higgs_Log_EndMethod, "sameBaseType", "println","");
                    return true;
				}

				virtual bool isMember(MANAGER_TYPE a_manager, long a_type)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "isMember", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "isMember", "println","");
                    return this->shareManager(a_manager) && this->sameType(a_type);
				}

				virtual bool isMember(HOLDER_TYPE a_holder, MANAGER_TYPE a_manager)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "isMember", "println","");
                    auto i_type = MemoryHolderManager<H>::getType(a_manager, a_holder);
                    MemoryHolderLog(higgs_Log_EndMethod, "isMember", "println","");
                    return this->isMember(a_manager, i_type);
                }

				virtual bool isMember(HOLDER_TYPE a_holder)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "isMember", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "isMember", "println","");
                    return this->isMember(a_holder, this->getManager());
                }

				virtual bool isMember(const MemoryHolder<H>& a_holder)const{
                    MemoryHolderLog(higgs_Log_StartMethod, "isMember", "println","");
                    auto i_manager = a_holder.getManager();
                    auto i_type = a_holder.getType();
                    MemoryHolderLog(higgs_Log_EndMethod, "isMember", "println","");
                    return this->isMember(i_manager, i_type);
                }

				virtual void setType(long a_type){
                    MemoryHolderLog(higgs_Log_StartMethod, "setType", "println","");
					MemoryHolderManager<H>::setType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(higgs_Log_EndMethod, "setType", "println","");
				}

				virtual long getType()const{
                    MemoryHolderLog(higgs_Log_StartMethod, "getType", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "getType", "println","");
					return MemoryHolderManager<H>::getType(this->getManager(), this->m_holder);
				}

				virtual void setBaseType(long a_type){
                    MemoryHolderLog(higgs_Log_StartMethod, "setBaseType", "println","");
					MemoryHolderManager<H>::setBaseType(this->getManager(), this->m_holder, a_type);
                    MemoryHolderLog(higgs_Log_EndMethod, "setBaseType", "println","");
				}

				virtual long getBaseType()const{
                    MemoryHolderLog(higgs_Log_StartMethod, "getBaseType", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "getBaseType", "println","");
					return MemoryHolderManager<H>::getBaseType(this->getManager(), this->m_holder);
				}

				virtual bool isMemoryNull()const{
					MemoryHolderLog(higgs_Log_StartMethod, "isMemoryNull", "println","");
					if(m_holder == nullptr){
						MemoryHolderLog(higgs_Log_EndMethod, "isMemoryNull", "println","m_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(higgs_Log_Statement, "isMemoryNull", "println", "isNull: ");
					MemoryHolderLog(higgs_Log_Statement, "isMemoryNull", "println", i_pointer == nullptr);
					MemoryHolderLog(higgs_Log_EndMethod, "isMemoryNull", "println","");
					return i_pointer == nullptr;
				}

				virtual bool isNull()const{
					MemoryHolderLog(higgs_Log_StartMethod, "isNull", "println","");
					if(m_holder == nullptr){
						MemoryHolderLog(higgs_Log_EndMethod, "isNull", "println","m_holder == nullptr");
						return true;
					}
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(higgs_Log_Statement, "isNull", "println", "isNull: ");
					MemoryHolderLog(higgs_Log_Statement, "isNull", "println", i_pointer == nullptr);
					MemoryHolderLog(higgs_Log_EndMethod, "isNull", "println","");
					return i_pointer == nullptr;
				}

				//unsafe method
				virtual VOID_TYPE getRawPointer()const{
                    MemoryHolderLog(higgs_Log_StartMethod, "getRawPointer", "println","");
					VOID_TYPE i_pointer = MemoryHolderManager<H>::get(this->getManager(), m_holder);
					MemoryHolderLog(higgs_Log_Statement, "getRawPointer", "println","VOID_TYPE is null?");
					MemoryHolderLog(higgs_Log_Statement, "getRawPointer", "println", i_pointer == nullptr);
					MemoryHolderLog(higgs_Log_EndMethod, "getRawPointer", "println","");
					return i_pointer;
				}

                virtual void operator=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(higgs_Log_StartMethod, "operator=", "println","");
                    if(!this->isMember(a_holder)){
                        MemoryHolderLog(higgs_Log_Error, "operator=", "println", "MemoryHolder is not Member of Variable");
                        MemoryHolderLog(higgs_Log_EndMethod, "operator=", "println","");
                        return;
                    }
                    this->setHolder(a_holder.getHolder());
                    MemoryHolderLog(higgs_Log_EndMethod, "operator=", "println","");
                }

                virtual bool operator==(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(higgs_Log_StartMethod, "operator==", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "operator==", "println", this->getHolder() == a_holder.getHolder());
                    return this->getHolder() == a_holder.getHolder();
                }

                virtual bool operator!=(const MemoryHolder<H>& a_holder){
                    MemoryHolderLog(higgs_Log_StartMethod, "operator!=", "println","");
                    MemoryHolderLog(higgs_Log_EndMethod, "operator!=", "println", this->getHolder() != a_holder.getHolder());
                    return this->getHolder() != a_holder.getHolder();
                }

            protected:

                HOLDER_TYPE m_holder = nullptr;
            
        };

	}

#endif