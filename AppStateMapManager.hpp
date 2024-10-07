
#ifndef AppStateMapManager_hpp
	#define AppStateMapManager_hpp

	#include "pankey.hpp"

	#include "AppState.hpp"
	#include "UpdateManager.hpp"

	#ifdef AppStateMapManager_LogApp
		#include "pankey_Logger.hpp"
		#define AppStateMapManagerLog(location,method,type,mns) pankey_Log(this,location,"AppStateMapManager",method,type,mns)
	#else
		#define AppStateMapManagerLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class A, class... Args>
		class AppStateMapManager : public UpdateManager<A&,Args...>{
			public:
				AppStateMapManager(){
					AppStateMapManagerLog(pankey_Log_StartMethod, "Constructor", "println", "");
					AppStateMapManagerLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~AppStateMapManager(){
					AppStateMapManagerLog(pankey_Log_StartMethod, "Destructor", "println", "");
					AppStateMapManagerLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual app_state<A,Args...> add(Note a_id, app_state<A,Args...> a_state){
					AppStateMapManagerLog(pankey_Log_StartMethod, "add",  "println", "");
					m_initialize.add(a_state);
					AppStateMapManagerLog(pankey_Log_EndMethod, "add", "println", "");
					return a_state;
				}
				
				virtual app_state<A,Args...> getInitializedAppState(int a_index)=0;
				virtual app_state<A,Args...> getInitializedAppStateById(Note a_state_id)=0;
				
				virtual app_state<A,Args...> getUnInitializedAppState(int a_index)=0;
				virtual app_state<A,Args...> getUnInitializedAppStateById(Note a_state_id)=0;
				
				virtual app_state<A,Args...> getAppState(int a_index)=0;
				virtual app_state<A,Args...> getAppStateById(Note a_state_id)=0;
				
				virtual int getInitializedAppStatesSize()=0;
				virtual int getUnInitializedAppStatesSize()=0;
				virtual int getAppStatesSize()=0;
				
				virtual app_state<A,Args...> removeInitializedAppState(int a_index)=0;
				virtual app_state<A,Args...> removeInitializedAppStateById(Note a_state_id)=0;
				
				virtual app_state<A,Args...> removeUnInitializedAppState(int a_index)=0;
				virtual app_state<A,Args...> removeUnInitializedAppStateById(Note a_state_id)=0;
				
				virtual app_state<A,Args...> removeAppStateById(Note a_state_id)=0;
				
				virtual void removeAllAppStates()=0;

			protected:
				Map m_appstates;
				Map m_initialize;
				
		};

	}

#endif
