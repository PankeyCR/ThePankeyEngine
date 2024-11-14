
#ifndef InputEventAppState_hpp
	#define InputEventAppState_hpp

	#include "InvokeRawList.hpp"
	#include "InvokeRawMap.hpp"
	#include "Application.hpp"
	#include "BaseAppState.hpp"

	#ifdef InputEventAppState_LogApp
		#include "ame_Logger.hpp"
		#define InputEventAppStateLog(location,method,type,mns) ame_Log((void*)this,location,"InputEventAppState",method,type,mns)
	#else
		#define InputEventAppStateLog(location,method,type,mns) 
	#endif

	namespace pankey{

		template<class I>
		class InputEventAppState : public BaseAppState<Application,long> {
			public:
				InputEventAppState(){
					InputEventAppStateLog(ame_Log_StartMethod, "Constructor", "println", "");
					InputEventAppStateLog(ame_Log_EndMethod, "Constructor", "println", "");
				}
				InputEventAppState(const InputEventAppState& a_inputevent){
					InputEventAppStateLog(ame_Log_StartMethod, "Constructor", "println", "");
					m_inputs = a_inputevent.m_inputs;
					m_action.addCopy(a_inputevent.m_action);
					m_events.addCopy(a_inputevent.m_events);
					m_app_events.addCopy(a_inputevent.m_app_events);
					InputEventAppStateLog(ame_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~InputEventAppState(){}
				
				virtual void add(int a_interrupt, I a_input, InvokeMethodReturn<bool,I&,long> a_action, InvokeMethod<int,I&> a_event){
					InputEventAppStateLog(ame_Log_StartMethod, "add", "println", "");
					m_inputs.put(a_interrupt, a_input);
					m_action.put(a_interrupt, a_action);
					if(!m_events.contain(a_interrupt)){
						m_events.addPointer(a_interrupt, new MethodList<int,I&>());
					}
					MethodList<int,I&>* i_event_list = m_events.getValueByLValue(a_interrupt);
					i_event_list->add(a_event);
					if(hasInitialize()){
						a_input.initialize();
					}
					InputEventAppStateLog(ame_Log_EndMethod, "add", "println", "");
				}
				
				virtual void add(int a_interrupt, I a_input, InvokeMethodReturn<bool,I&,long> a_action, InvokeMethod<Application&,int,I&> a_event){
					InputEventAppStateLog(ame_Log_StartMethod, "add", "println", "");
					m_inputs.put(a_interrupt, a_input);
					m_action.put(a_interrupt, a_action);
					if(!m_app_events.contain(a_interrupt)){
						m_app_events.addPointer(a_interrupt, new MethodList<Application&,int,I&>());
					}
					MethodList<Application&,int,I&>* i_event_list = m_app_events.getValueByLValue(a_interrupt);
					i_event_list->add(a_event);
					if(hasInitialize()){
						a_input.initialize();
					}
					InputEventAppStateLog(ame_Log_EndMethod, "add", "println", "");
				}
				
				virtual val<I> getInput(int a_interrupt){
					InputEventAppStateLog(ame_Log_StartMethod, "getInput", "println", "");
					InputEventAppStateLog(ame_Log_EndMethod, "getInput", "println", "");
					return m_inputs.getValueByValue(val<int>(a_interrupt));
				}
				
				virtual void initializeState(){
					InputEventAppStateLog(ame_Log_StartMethod, "initializeState", "println", "");
					InputEventAppStateLog(ame_Log_Statement, "initializeState", "println", "input position:");
					InputEventAppStateLog(ame_Log_Statement, "initializeState", "println", m_inputs.getPosition());
					for(int x = 0; x < m_inputs.length(); x++){
						pointer<I> f_input = m_inputs.getValue(x);
						if(f_input.isNull()){
							InputEventAppStateLog(ame_Log_Statement, "initializeState", "println", "f_input == nullptr");
							continue;
						}
						f_input->initialize();
					}
					InputEventAppStateLog(ame_Log_EndMethod, "initializeState", "println", "");
				}
				
				virtual void updateState(Application& a_pp, long a_tpc){
					InputEventAppStateLog(ame_Log_StartMethod, "updateState", "println", "");
					InputEventAppStateLog(ame_Log_Statement, "updateState", "println", "input position:");
					InputEventAppStateLog(ame_Log_Statement, "updateState", "println", m_inputs.getPosition());
					for(int x = 0; x < m_inputs.length(); x++){
						pointer<int> f_interrupt_p = m_inputs.getKey(x);
						pointer<I> f_input_p = m_inputs.getValue(x);
						if(f_interrupt_p.isNull() || f_input_p.isNull()){
							InputEventAppStateLog(ame_Log_Statement, "initializeState", "println", "f_input == nullptr");
							continue;
						}
						int f_interrupt = *((int*)f_interrupt_p.getRawPointer());
						I* f_input = (I*)f_input_p.getRawPointer();
						
						bool i_action = invoke<int,bool,I&,long>(m_action, f_interrupt, *f_input, a_tpc);
						InputEventAppStateLog(ame_Log_Statement, "updateState", "println", "Action State:");
						InputEventAppStateLog(ame_Log_Statement, "updateState", "println", i_action);
						
						if(i_action){
							MethodList<int,I&>* i_event_list = m_events.getValueByLValue(f_interrupt);
							if(i_event_list != nullptr){
								InputEventAppStateLog(ame_Log_Statement, "updateState", "println", "invoking i_event_list");
								invokeAll<int,I&>(*i_event_list, f_interrupt, *f_input);
							}

							MethodList<Application&,int,I&>* i_app_event_list = m_app_events.getValueByLValue(f_interrupt);
							if(i_app_event_list != nullptr){
								InputEventAppStateLog(ame_Log_Statement, "updateState", "println", "invoking i_app_event_list");
								invokeAll<Application&,int,I&>(*i_app_event_list, a_pp, f_interrupt, *f_input);
							}
							InputEventAppStateLog(ame_Log_Statement, "updateState", "println", "just invoke");
						}
					}
					InputEventAppStateLog(ame_Log_EndMethod, "updateState", "println", "");
				}

				virtual void operator=(const InputEventAppState& a_inputevent){
					InputEventAppStateLog(ame_Log_StartMethod, "Constructor", "println", "");
					m_inputs = a_inputevent.m_inputs;
					m_action.addCopy(a_inputevent.m_action);
					m_events.addCopy(a_inputevent.m_events);
					m_app_events.addCopy(a_inputevent.m_app_events);
					InputEventAppStateLog(ame_Log_EndMethod, "Constructor", "println", "");
				}

			protected:
				TMap<int,I> m_inputs;
				MethodReturnMap<int,bool,I&,long> m_action;
				PrimitiveRawMap<int,MethodList<int,I&>> m_events;
				PrimitiveRawMap<int,MethodList<Application&,int,I&>> m_app_events;
		};

	}

#endif