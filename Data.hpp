
#ifndef Data_hpp
	#define Data_hpp

    #include "MemoryHolder.hpp"

    #ifdef Data_LogApp
        #include "higgs_Logger.hpp"
        #define DataLog(location,method,type,mns) higgs_Log(nullptr,location,"Data",method,type,mns)
    #else
        #define DataLog(location,method,type,mns)
    #endif

	namespace higgs{

        template<class H>
        class Data : public MemoryHolder<H>{
            public:

                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;
                
                MANAGER_TYPE m_manager = nullptr;
                long m_type = -1;

                Data(){
                    DataLog(higgs_Log_StartMethod, "Constructor", "println","");
                    DataLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                Data(const MemoryHolder<H>& a_holder){
                    DataLog(higgs_Log_StartMethod, "Constructor", "println","");
                    this->setManager(a_holder.getManager());
                    this->setHolder(a_holder.getHolder());
                    this->setType(a_holder.getType());
                    DataLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                Data(HOLDER_TYPE a_holder, MANAGER_TYPE a_Manager){
                    DataLog(higgs_Log_StartMethod, "Constructor", "println","");
                    this->setManager(a_Manager);
                    this->setHolder(a_holder);
                    DataLog(higgs_Log_EndMethod, "Constructor", "println","");
                }

                Data(HOLDER_TYPE a_holder, MANAGER_TYPE a_Manager, long a_type){
                    DataLog(higgs_Log_StartMethod, "Constructor", "println","");
                    this->setManager(a_Manager);
                    this->setHolder(a_holder);
                    this->setType(a_type);
                    DataLog(higgs_Log_EndMethod, "Constructor", "println","");
                }
                
                virtual ~Data(){
                    DataLog(higgs_Log_StartMethod, "Destructor", "println","");
					this->remove();
                    DataLog(higgs_Log_EndMethod, "Destructor", "println","");
                }
                    
                virtual void setManager(MANAGER_TYPE a_llocator){
                    DataLog(higgs_Log_StartMethod, "setManager", "println","");
                    m_manager = a_llocator;
                    DataLog(higgs_Log_EndMethod, "setManager", "println","");
                }

                virtual MANAGER_TYPE getManager()const{
                    DataLog(higgs_Log_StartMethod, "getManager", "println","");
                    DataLog(higgs_Log_EndMethod, "getManager", "println","");
                    return m_manager;
                }

				virtual void setType(long a_type){
                    DataLog(higgs_Log_StartMethod, "setType", "println","");
                    this->m_type = a_type;
                    DataLog(higgs_Log_EndMethod, "setType", "println","");
				}

				virtual long getType()const{
                    DataLog(higgs_Log_StartMethod, "getType", "println","");
                    DataLog(higgs_Log_EndMethod, "getType", "println","");
					return this->m_type;
				}

                virtual void operator=(const MemoryHolder<H>& a_holder){
                    DataLog(higgs_Log_StartMethod, "operator=", "println","");
                    this->setManager(a_holder.getManager());
                    this->setHolder(a_holder.getHolder());
                    this->setType(a_holder.getType());
                    DataLog(higgs_Log_EndMethod, "operator=", "println","");
                }
            
        };

	}

#endif