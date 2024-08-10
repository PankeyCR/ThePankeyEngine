
#ifndef BaseAppState_hpp
	#define BaseAppState_hpp

	#include "AppState.hpp"

	#ifdef BaseAppState_LogApp
		#include "higgs_Logger.hpp"
		#define BaseAppStateLog(location,method,type,mns) higgs_Log((void*)this,location,"BaseAppState",method,type,mns)
	#else
		#define BaseAppStateLog(location,method,type,mns) 
	#endif

	namespace higgs{

		template<class A, class... Args>
		class BaseAppState : public AppState<A,Args...>{
			public:
				BaseAppState(){}
				virtual ~BaseAppState(){}
				
				virtual void initialize(A& a_app){
					BaseAppStateLog(higgs_Log_StartMethod, "initialize", "println", "");
					m_init = true;
					initializeState(a_app);
					initializeState();
					BaseAppStateLog(higgs_Log_EndMethod, "initialize", "println", "");
				}
				
				virtual void initializeState(A& a_app){}
				
				virtual void initializeState(){}
				virtual bool hasInitialize(){return m_init;}
				
				virtual void onEnable(){m_enable = true;}
				virtual void onDisable(){m_enable = false;}
				
				virtual bool isEnable(){return m_enable;}
				
				
				virtual void update(A& a_app, Args... a_values){
					if(!m_enable){
						return;
					}
					updateState(a_app, a_values...);
				}
				
				virtual void updateState(A& a_app, Args... a_values){}

			protected:
				bool m_enable = false;
				bool m_init = false;
		};

	}

#endif
