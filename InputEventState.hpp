
#ifndef InputEventState_hpp
	#define InputEventState_hpp

	#include "InvokeRawList.hpp"
	#include "InvokeRawMap.hpp"
	#include "BaseState.hpp"

	#ifdef InputEventState_LogApp
		#include "higgs_Logger.hpp"
		#define InputEventStateLog(location,method,type,mns) higgs_Log((void*)this,location,"InputEventState",method,type,mns)
	#else
		#define InputEventStateLog(location,method,type,mns) 
	#endif

	namespace higgs{

		template<class I>
		class InputEventState : public BaseState<float> {
			public:
				InputEventState(){
					InputEventStateLog(higgs_Log_StartMethod, "Constructor", "println", "");
					InputEventStateLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				InputEventState(const InputEventState& a_inputevent){
					InputEventStateLog(higgs_Log_StartMethod, "Constructor", "println", "");
					m_inputs.addCopy(a_inputevent.m_inputs);
					m_action.addCopy(a_inputevent.m_action);
					m_events.addCopy(a_inputevent.m_events);
					InputEventStateLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}
				virtual ~InputEventState(){}
				
				virtual void add(int a_interrupt, I a_input, InvokeMethodReturn<bool,I&,float> a_action, InvokeMethod<int,I&> a_event){
					InputEventStateLog(higgs_Log_StartMethod, "add", "println", "");
					m_inputs.add(a_interrupt, a_input);
					m_action.add(a_interrupt, a_action);
					if(!m_events.contain(a_interrupt)){
						m_events.addPointer(a_interrupt, new MethodList<int,I&>());
					}
					MethodList<int,I&>* i_event_list = m_events.getValueByLValue(a_interrupt);
					i_event_list->add(a_event);
					if(hasInitialize()){
						a_input.initialize();
					}
					InputEventStateLog(higgs_Log_EndMethod, "add", "println", "");
				}
				
				virtual void initializeState(){
					InputEventStateLog(higgs_Log_StartMethod, "initializeState", "println", "");
					InputEventStateLog(higgs_Log_Statement, "initializeState", "println", "input position:");
					InputEventStateLog(higgs_Log_Statement, "initializeState", "println", m_inputs.getPosition());
					for(int x = 0; x < m_inputs.getPosition(); x++){
						I* f_input = m_inputs.getValueByPosition(x);
						if(f_input == nullptr){
							InputEventStateLog(higgs_Log_Statement, "initializeState", "println", "f_input == nullptr");
							continue;
						}
						f_input->initialize();
					}
					InputEventStateLog(higgs_Log_EndMethod, "initializeState", "println", "");
				}
				
				virtual void updateState(float a_tpc){
					InputEventStateLog(higgs_Log_StartMethod, "updateState", "println", "");
					InputEventStateLog(higgs_Log_Statement, "updateState", "println", "input position:");
					InputEventStateLog(higgs_Log_Statement, "updateState", "println", m_inputs.getPosition());
					for(int x = 0; x < m_inputs.getPosition(); x++){
						int f_interrupt = m_inputs.getKey(x);
						I* f_input = m_inputs.getValueByPosition(x);
						if(f_input == nullptr){
							InputEventStateLog(higgs_Log_Statement, "initializeState", "println", "f_input == nullptr");
							continue;
						}
						
						bool i_action = invoke<int,bool,I&,float>(m_action, f_interrupt, *f_input, a_tpc);
						InputEventStateLog(higgs_Log_Statement, "updateState", "println", "Action State:");
						InputEventStateLog(higgs_Log_Statement, "updateState", "println", i_action);
						
						if(i_action){
							MethodList<int,I&>* i_event_list = m_events.getValueByLValue(f_interrupt);
							if(i_event_list != nullptr){
								invokeAll<int,I&>(*i_event_list, f_interrupt, *f_input);
							}
							InputEventStateLog(higgs_Log_Statement, "updateState", "println", "just invoke");
						}
					}
					InputEventStateLog(higgs_Log_EndMethod, "updateState", "println", "");
				}

				virtual void operator=(const InputEventState& a_inputevent){
					InputEventStateLog(higgs_Log_StartMethod, "Constructor", "println", "");
					m_inputs.addCopy(a_inputevent.m_inputs);
					m_action.addCopy(a_inputevent.m_action);
					m_events.addCopy(a_inputevent.m_events);
					InputEventStateLog(higgs_Log_EndMethod, "Constructor", "println", "");
				}

			protected:
				PrimitiveRawMap<int,I> m_inputs;
				MethodReturnMap<int,bool,I&,float> m_action;
				PrimitiveRawMap<int,MethodList<int,I&>> m_events;
		};

	}

#endif