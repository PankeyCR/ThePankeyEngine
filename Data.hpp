
#ifndef Data_hpp
	#define Data_hpp

    #include "MemoryHolder.hpp"

    #ifdef Data_LogApp
        #include "pankey_Logger.hpp"
        #define DataLog(location,method,type,mns) pankey_Log(nullptr,location,"Data",method,type,mns)
    #else
        #define DataLog(location,method,type,mns)
    #endif

	namespace pankey{

        template<class H>
        class Data : public MemoryHolder<H>{
            public:

                using MANAGER_TYPE = typename MemoryHolder<H>::MANAGER_TYPE;
                using HOLDER_TYPE = typename MemoryHolder<H>::HOLDER_TYPE;
                
                MANAGER_TYPE m_manager = nullptr;

                Data(){
                    DataLog(pankey_Log_StartMethod, "Constructor", "println","");
                    DataLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Data(const MemoryHolder<H>& a_holder){
                    DataLog(pankey_Log_StartMethod, "Constructor", "println","const MemoryHolder<H>& a_holder");
                    auto i_manager = a_holder.getManager();
                    if(i_manager == nullptr){
                        DataLog(pankey_Log_Statement, "Constructor", "println","i_manager == nullptr");
                        DataLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setManager(i_manager);
                    this->setHolder(a_holder.getHolder());
                    DataLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Data(const Data<H>& a_holder){
                    DataLog(pankey_Log_StartMethod, "Constructor", "println","const Data<H>& a_holder");
                    auto i_manager = a_holder.getManager();
                    if(i_manager == nullptr){
                        DataLog(pankey_Log_Statement, "Constructor", "println","i_manager == nullptr");
                        DataLog(pankey_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setManager(i_manager);
                    this->setHolder(a_holder.getHolder());
                    DataLog(pankey_Log_EndMethod, "Constructor", "println","");
                }

                Data(HOLDER_TYPE a_holder, MANAGER_TYPE a_Manager){
                    DataLog(pankey_Log_StartMethod, "Constructor", "println","HOLDER_TYPE a_holder, MANAGER_TYPE a_Manager");
                    this->setManager(a_Manager);
                    this->setHolder(a_holder);
                    DataLog(pankey_Log_EndMethod, "Constructor", "println","");
                }
                
                virtual ~Data(){
                    DataLog(pankey_Log_StartMethod, "Destructor", "println","");
					this->remove();
                    DataLog(pankey_Log_EndMethod, "Destructor", "println","");
                }
                    
                virtual void setManager(MANAGER_TYPE a_llocator){
                    DataLog(pankey_Log_StartMethod, "setManager", "println","");
                    m_manager = a_llocator;
                    DataLog(pankey_Log_EndMethod, "setManager", "println","");
                }

                virtual MANAGER_TYPE getManager()const{
                    DataLog(pankey_Log_StartMethod, "getManager", "println","");
                    DataLog(pankey_Log_Statement, "getManager", "println","Is Null?");
                    DataLog(pankey_Log_Statement, "getManager", "println",m_manager == nullptr);
                    DataLog(pankey_Log_EndMethod, "getManager", "println","");
                    return m_manager;
                }

                virtual void operator=(const MemoryHolder<H>& a_holder){
                    DataLog(pankey_Log_StartMethod, "operator=", "println","");
                    auto i_manager = a_holder.getManager();
                    if(i_manager == nullptr){
                        DataLog(pankey_Log_EndMethod, "operator=", "println","");
                        return;
                    }
                    this->setManager(i_manager);
                    this->setHolder(a_holder.getHolder());
                    DataLog(pankey_Log_EndMethod, "operator=", "println","");
                }
            
        };

	}

#endif