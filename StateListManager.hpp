
#ifndef StateListManager_hpp
	#define StateListManager_hpp

	#include "higgs_Enviroment.hpp"
	#include "higgs_Enviroment_config.hpp"

	#include "State.hpp"
	#include "UpdateManager.hpp"

	#ifdef StateListManager_LogApp
		#include "higgs_Logger.hpp"
		#define StateListManagerLog(location,method,type,mns) higgs_Log(this,location,"StateListManager",method,type,mns)
	#else
		#define StateListManagerLog(location,method,type,mns)
	#endif

	namespace higgs{

		template<class... Args>
		class StateListManager : virtual public UpdateManager<Args...>{
			public:
				StateListManager(){
					StateListManagerLog(higgs_Log_StartMethod, "Constructor", "println", "");
					StateListManagerLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~StateListManager(){
					StateListManagerLog(higgs_Log_StartMethod, "Destructor", "println", "");
					StateListManagerLog(higgs_Log_EndMethod, "Destructor", "println", "");
				}

				virtual state<Args...> add(state<Args...> a_state){
					StateListManagerLog(higgs_Log_StartMethod, "add",  "println", "");
					m_initialize.add(a_state);
					StateListManagerLog(higgs_Log_EndMethod, "add", "println", "");
					return a_state;
				}
				
				virtual state<Args...> getInitializedStateList(int a_index){
					return m_states.get(a_index);
				}
				
				virtual state<Args...> getUnInitializedStateList(int a_index){
					return m_initialize.get(a_index);
				}
				
				virtual state<Args...> getStateList(int a_index){
					return m_states.get(a_index);
				}
				
				virtual int getInitializedStateListSize(){
					return m_states.length();
				}

				virtual int getUnInitializedStateListSize(){
					return m_initialize.length();
				}

				virtual int getStateListSize(){
					return m_states.length();
				}
				
				virtual state<Args...> removeInitializedStateList(int a_index){
					state<Args...> i_state = m_states.remove(a_index);
					if(i_state.isNull()){
						return i_state;
					}
					i_state->onDisable();
					return i_state;
				}
				
				virtual state<Args...> removeUnInitializedStateList(int a_index){
					return m_initialize.remove(a_index);
				}
				
				virtual state<Args...> removeStateList(int a_index){
					state<Args...> i_state = m_states.remove(a_index);
					if(i_state.isNull()){
						return i_state;
					}
					i_state->onDisable();
					return i_state;
				}
				
				virtual void removeAllStateList(){
					StateListManagerLog(higgs_Log_StartMethod, "removeAllStateList",  "println", "");
					for(int x = 0; x < m_states.length(); x++){
						state<Args...> f_state = m_states.get(x);
						if(f_state.isNull()){
							continue;
						}
						f_state->onDisable();
					}
					for(int x = 0; x < m_initialize.length(); x++){
						state<Args...> f_state = m_initialize.get(x);
						if(f_state.isNull()){
							continue;
						}
						f_state->onDisable();
					}
					m_states.clear();
					m_initialize.clear();
					StateListManagerLog(higgs_Log_EndMethod, "removeAllStateList", "println", "");
				}
				
				virtual void removeAll(){
					StateListManagerLog(higgs_Log_StartMethod, "removeAll",  "println", "");
					this->removeAllStateList();
					StateListManagerLog(higgs_Log_EndMethod, "removeAll", "println", "");
				}
				virtual void initialize(){
					StateListManagerLog(higgs_Log_StartMethod, "initialize",  "println", "");
					if(!this->m_initialize.isEmpty()){
						for(int x = 0; x < this->m_initialize.length();x++){
							state<Args...> f_state = this->m_initialize.get(x);
							if(f_state.isNull()){
								continue;
							}
							f_state->initialize();
							f_state->onEnable();
							this->m_states.add(f_state);
						}
						StateListManagerLog(higgs_Log_StartMethod, "initialize",  "println", "m_initialize");
						this->m_initialize.clear();
					}
					StateListManagerLog(higgs_Log_EndMethod, "initialize", "println", "");
				}

				virtual void update(Args... a_values){
					StateListManagerLog(higgs_Log_StartMethod, "update",  "println", "");
					
					if(!this->m_initialize.isEmpty()){
						for(int x = 0; x < this->m_initialize.length();x++){
							state<Args...> f_state = this->m_initialize.get(x);
							if(f_state.isNull()){
								continue;
							}
							f_state->initialize();
							f_state->onEnable();
							this->m_states.add(f_state);
						}
						StateListManagerLog(higgs_Log_StartMethod, "update",  "println", "m_initialize");
						this->m_initialize.clear();
					}
					for(int x = 0; x < this->m_states.length(); x++){
						StateListManagerLog(higgs_Log_StartMethod, "update",  "println", "iterating through all states");
						StateListManagerLog(higgs_Log_StartMethod, "update",  "println", "iteration: ");
						StateListManagerLog(higgs_Log_StartMethod, "update",  "println", x);
						state<Args...> f_state = this->m_states.get(x);
						if(f_state.isNull()){
							StateListManagerLog(higgs_Log_StartMethod, "update",  "println", "f_state.isNull()");
							continue;
						}
						f_state->update(a_values...);
					}

					StateListManagerLog(higgs_Log_EndMethod, "update", "println", "");
				}

			protected:
				OList<State<Args...>> m_states;
				OList<State<Args...>> m_initialize;
				
		};

	}

#endif
