
#ifndef AppStateListManager_hpp
	#define AppStateListManager_hpp

	#include "pankey_Enviroment.hpp"
	#include "pankey_Enviroment_config.hpp"

	#include "AppState.hpp"
	#include "UpdateManager.hpp"

	#ifdef AppStateListManager_LogApp
		#include "pankey_Logger.hpp"
		#define AppStateListManagerLog(location,method,type,mns) pankey_Log(this,location,"AppStateListManager",method,type,mns)
	#else
		#define AppStateListManagerLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class A, class... Args>
		class AppStateListManager : virtual public UpdateManager<A&,Args...>{
			public:
				AppStateListManager(){
					AppStateListManagerLog(pankey_Log_StartMethod, "Constructor", "println", "");
					AppStateListManagerLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~AppStateListManager(){
					AppStateListManagerLog(pankey_Log_StartMethod, "Destructor", "println", "");
					AppStateListManagerLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				virtual app_state<A,Args...> add(app_state<A,Args...> a_state){
					AppStateListManagerLog(pankey_Log_StartMethod, "add",  "println", "");
					m_initialize.add(a_state);
					AppStateListManagerLog(pankey_Log_EndMethod, "add", "println", "");
					return a_state;
				}
				
				virtual app_state<A,Args...> getInitializedAppStateList(int a_index){
					return m_appstates.get(a_index);
				}
				
				virtual app_state<A,Args...> getUnInitializedAppStateList(int a_index){
					return m_initialize.get(a_index);
				}
				
				virtual app_state<A,Args...> getAppStateList(int a_index){
					return m_appstates.get(a_index);
				}
				
				virtual int getInitializedAppStateListSize(){
					return m_appstates.length();
				}

				virtual int getUnInitializedAppStateListSize(){
					return m_initialize.length();
				}

				virtual int getAppStateListSize(){
					return m_appstates.length();
				}
				
				virtual app_state<A,Args...> removeInitializedAppStateList(int a_index){
					app_state<A,Args...> i_state = m_appstates.remove(a_index);
					if(i_state.isNull()){
						return i_state;
					}
					i_state->onDisable();
					return i_state;
				}
				
				virtual app_state<A,Args...> removeUnInitializedAppStateList(int a_index){
					return m_initialize.remove(a_index);
				}
				
				virtual app_state<A,Args...> removeAppStateList(int a_index){
					app_state<A,Args...> i_state = m_appstates.remove(a_index);
					if(i_state.isNull()){
						return i_state;
					}
					i_state->onDisable();
					return i_state;
				}
				
				virtual void removeAllAppStateList(){
					AppStateListManagerLog(pankey_Log_StartMethod, "removeAllAppStateList",  "println", "");
					for(int x = 0; x < m_appstates.length(); x++){
						app_state<A,Args...> f_state = m_appstates.get(x);
						if(f_state.isNull()){
							continue;
						}
						f_state->onDisable();
					}
					for(int x = 0; x < m_initialize.length(); x++){
						app_state<A,Args...> f_state = m_initialize.get(x);
						if(f_state.isNull()){
							continue;
						}
						f_state->onDisable();
					}
					m_appstates.clear();
					m_initialize.clear();
					AppStateListManagerLog(pankey_Log_EndMethod, "removeAllAppStateList", "println", "");
				}
				
				virtual void removeAll(){
					AppStateListManagerLog(pankey_Log_StartMethod, "removeAll",  "println", "");
					this->removeAllAppStateList();
					AppStateListManagerLog(pankey_Log_EndMethod, "removeAll", "println", "");
				}

				virtual void initialize(A& a_app){
					AppStateListManagerLog(pankey_Log_StartMethod, "initialize",  "println", "");
					if(!this->m_initialize.isEmpty()){
						for(int x = 0; x < this->m_initialize.length();x++){
							AppStateListManagerLog(pankey_Log_StartMethod, "initialize",  "println", "iterating through initializing states");
							AppStateListManagerLog(pankey_Log_StartMethod, "initialize",  "println", "iteration: ");
							AppStateListManagerLog(pankey_Log_StartMethod, "initialize",  "println", x);
							app_state<A,Args...> f_state = this->m_initialize.get(x);
							if(f_state.isNull()){
								AppStateListManagerLog(pankey_Log_StartMethod, "initialize",  "println", "initializing state is null");
								continue;
							}
							f_state->initialize(a_app);
							f_state->onEnable();
							this->m_appstates.add(f_state);
						}
						AppStateListManagerLog(pankey_Log_StartMethod, "initialize",  "println", "m_initialize");
						this->m_initialize.clear();
					}
					AppStateListManagerLog(pankey_Log_EndMethod, "initialize", "println", "");
				}

				virtual void update(A& a_app, Args... a_values){
					AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "");
					
					if(!this->m_initialize.isEmpty()){
						for(int x = 0; x < this->m_initialize.length();x++){
							AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "iterating through initializing states");
							AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "iteration: ");
							AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", x);
							app_state<A,Args...> f_state = this->m_initialize.get(x);
							if(f_state.isNull()){
								AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "initializing state is null");
								continue;
							}
							f_state->initialize(a_app);
							f_state->onEnable();
							this->m_appstates.add(f_state);
						}
						AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "m_initialize");
						this->m_initialize.clear();
					}
					for(int x = 0; x < this->m_appstates.length(); x++){
						AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "iterating through all states");
						AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", "iteration: ");
						AppStateListManagerLog(pankey_Log_StartMethod, "update",  "println", x);
						app_state<A,Args...> f_state = this->m_appstates.get(x);
						if(f_state.isNull()){
							continue;
						}
						f_state->update(a_app, a_values...);
					}

					AppStateListManagerLog(pankey_Log_EndMethod, "update", "println", "");
				}

			protected:
				OList<AppState<A,Args...>> m_appstates;
				OList<AppState<A,Args...>> m_initialize;
				
		};

	}

#endif
