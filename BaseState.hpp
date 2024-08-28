
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
				BaseState(){}
				virtual ~BaseState(){}
				
				virtual void initialize(){
					BaseStateLog(pankey_Log_StartMethod, "initialize", "println", "");
					m_init = true;
					initializeState();
					BaseStateLog(pankey_Log_EndMethod, "initialize", "println", "");
				}
				
				virtual void initializeState(){}
				virtual bool hasInitialize(){return m_init;}
				
				virtual void onEnable(){m_enable = true;}
				virtual void onDisable(){m_enable = false;}
				
				virtual bool isEnable(){return m_enable;}
				
				
				virtual void update( Args... a_values){
					if(!m_enable){
						return;
					}
					updateState(a_values...);
				}
				
				virtual void updateState(Args... a_values){}

			protected:
				bool m_enable = false;
				bool m_init = false;
		};

	}

#endif
