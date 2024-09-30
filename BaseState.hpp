
#ifndef BaseState_hpp
	#define BaseState_hpp

	#include "State.hpp"

	#ifdef BaseState_LogApp
		#include "pankey_Logger.hpp"
		#define BaseStateLog(location,method,type,mns) pankey_Log((void*)this,location,"BaseState",method,type,mns)
	#else
		#define BaseStateLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class... Args>
		class BaseState : public State<Args...>{
			public:
				BaseState(){
					BaseStateLog(pankey_Log_StartMethod, "Contructor", "println", "");
					BaseStateLog(pankey_Log_EndMethod, "Contructor", "println", "");
				}
				virtual ~BaseState(){
					BaseStateLog(pankey_Log_StartMethod, "Destructor", "println", "");
					BaseStateLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}
				
				virtual void initialize(){
					BaseStateLog(pankey_Log_StartMethod, "initialize", "println", "");
					m_init = true;
					initializeState();
					BaseStateLog(pankey_Log_EndMethod, "initialize", "println", "");
				}
				
				virtual void initializeState(){
					BaseStateLog(pankey_Log_StartMethod, "initializeState", "println", "");
					BaseStateLog(pankey_Log_EndMethod, "initializeState", "println", "");
				}
				virtual bool hasInitialize(){
					BaseStateLog(pankey_Log_StartMethod, "initializeState", "println", "");
					BaseStateLog(pankey_Log_EndMethod, "initializeState", "println", "");
					return m_init;
				}
				
				virtual void onEnable(){
					BaseStateLog(pankey_Log_StartMethod, "onEnable", "println", "");
					m_enable = true;
					BaseStateLog(pankey_Log_EndMethod, "onEnable", "println", "");
				}
				virtual void onDisable(){
					BaseStateLog(pankey_Log_StartMethod, "onDisable", "println", "");
					m_enable = false;
					BaseStateLog(pankey_Log_EndMethod, "onDisable", "println", "");
				}
				
				virtual bool isEnable(){
					BaseStateLog(pankey_Log_StartMethod, "isEnable", "println", "");
					BaseStateLog(pankey_Log_EndMethod, "isEnable", "println", "");
					return m_enable;
				}
				
				
				virtual void update( Args... a_values){
					BaseStateLog(pankey_Log_StartMethod, "update", "println", "");
					if(!m_enable){
						BaseStateLog(pankey_Log_EndMethod, "update", "println", "!m_enable");
						return;
					}
					updateState(a_values...);
					BaseStateLog(pankey_Log_EndMethod, "update", "println", "");
				}
				
				virtual void updateState(Args... a_values){
					BaseStateLog(pankey_Log_StartMethod, "updateState", "println", "");
					BaseStateLog(pankey_Log_EndMethod, "updateState", "println", "");
				}

			protected:
				bool m_enable = false;
				bool m_init = false;
		};

	}

#endif
