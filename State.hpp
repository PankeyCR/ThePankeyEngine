
#ifndef State_hpp
	#define State_hpp

	#ifdef State_LogApp
		#include "pankey_Logger.hpp"
		#define StateLog(location,method,type,mns) pankey_Log(this,location,"State",method,type,mns)
	#else
		#define StateLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class... Args>
		class State{
			public:
				State(){
					StateLog(pankey_Log_StartMethod, "Contructor", "println","");
					StateLog(pankey_Log_EndMethod, "Contructor", "println","");
				}
				virtual ~State(){
					StateLog(pankey_Log_StartMethod, "Destructor", "println","");
					StateLog(pankey_Log_EndMethod, "Destructor", "println","");
				}

				virtual void initialize(){
					StateLog(pankey_Log_StartMethod, "initialize", "println","");
					this->initializeState();
					StateLog(pankey_Log_EndMethod, "initialize", "println","");
				}
				virtual void initializeState(){
					StateLog(pankey_Log_StartMethod, "initializeState", "println","");
					StateLog(pankey_Log_EndMethod, "initializeState", "println","");
				}
				virtual bool hasInitialize(){
					StateLog(pankey_Log_StartMethod, "hasInitialize", "println","");
					StateLog(pankey_Log_EndMethod, "hasInitialize", "println","");
					return false;
				}
				virtual void onEnable(){
					StateLog(pankey_Log_StartMethod, "onEnable", "println","");
					StateLog(pankey_Log_EndMethod, "onEnable", "println","");
				}
				virtual void onDisable(){
					StateLog(pankey_Log_StartMethod, "onDisable", "println","");
					StateLog(pankey_Log_EndMethod, "onDisable", "println","");
				}
				virtual void update(Args... a_values){
					StateLog(pankey_Log_StartMethod, "update", "println","");
					this->updateState(a_values...);
					StateLog(pankey_Log_EndMethod, "update", "println","");
				}
				virtual void updateState(Args... a_values){
					StateLog(pankey_Log_StartMethod, "updateState", "println","");
					StateLog(pankey_Log_EndMethod, "updateState", "println","");
				}
				
				virtual void operator=(const State<Args...>& a_state){
					StateLog(pankey_Log_StartMethod, "operator=", "println","");
					StateLog(pankey_Log_EndMethod, "operator=", "println","");
				}
				virtual bool operator==(const State<Args...>& a_state){
					StateLog(pankey_Log_StartMethod, "operator==", "println","");
					StateLog(pankey_Log_EndMethod, "operator==", "println","");
					return false;
				}
				virtual bool operator!=(const State<Args...>& a_state){
					StateLog(pankey_Log_StartMethod, "operator!=", "println","");
					StateLog(pankey_Log_EndMethod, "operator!=", "println","");
					return true;
				}
				
			protected:
		};

	}

#endif
