
#ifndef Instance_hpp
	#define Instance_hpp

    #include "Pointer.hpp"

	#ifdef Instance_LogApp
		#include "higgs_Logger.hpp"
		#define InstanceLog(location,method,type,mns) higgs_Log(this,location,"Instance",method,type,mns)
	#else
		#define InstanceLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class P, class H, class M>
		class Instance : public Pointer<P,H,M>{
			public:
				
				Instance(){
					InstanceLog(higgs_Log_StartMethod, "Contructor", "println","");
					this->create();
					InstanceLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Instance(const MemoryHolder<H>& a_instance){
					InstanceLog(higgs_Log_StartMethod, "Contructor", "println","const Instance &a_instance");
                    if(!this->isMember(a_instance)){
                        InstanceLog(higgs_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_instance.getHolder());
					InstanceLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Instance(const Member<H,M>& a_instance){
					InstanceLog(higgs_Log_StartMethod, "Contructor", "println","const Instance &a_instance");
                    if(!this->sameType(a_instance.getType())){
                        InstanceLog(higgs_Log_EndMethod, "Constructor", "println","");
                        return;
                    }
                    this->setHolder(a_instance.getHolder());
					InstanceLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Instance(const Instance<P,H,M>& a_instance){
					InstanceLog(higgs_Log_StartMethod, "Contructor", "println","const Instance &a_instance");
                    this->setHolder(a_instance.getHolder());
					InstanceLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				Instance(const Pointer<P,H,M>& a_instance){
					InstanceLog(higgs_Log_StartMethod, "Contructor", "println","const Instance &a_instance");
                    this->setHolder(a_instance.getHolder());
					InstanceLog(higgs_Log_EndMethod, "Contructor", "println","");
				}

				virtual ~Instance(){
					InstanceLog(higgs_Log_StartMethod, "Destructor", "println","");
					InstanceLog(higgs_Log_EndMethod, "Destructor", "println","");
				}
		};

	}

#endif