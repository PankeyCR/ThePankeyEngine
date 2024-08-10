

#ifndef StateMachineSystem_hpp
#define StateMachineSystem_hpp

#include "StaticMethodMap.hpp"

#ifdef SMS_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"
	
	#define SMSLog(location,method,type,mns) higgs_Log(nullptr,location,"StateMachineSystem",method,type,mns)
#else
	#ifdef SMS_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"
		
		#define SMSLog(location,method,type,mns) higgs_LogDebug(nullptr,location,"StateMachineSystem",method,type)
	#else
		#define SMSLog(location,method,type,mns) 
	#endif
#endif

namespace higgs{

template<class T>
class StateMachineSystem{	
    public:
		using StateMethod = void (*)(StateMachineSystem*,T*,float);
		StateMachineSystem(){}
		virtual ~StateMachineSystem(){}
		
		void setSystem(T* t){
			if(t == nullptr){
				return;
			}
			if(system != nullptr && system != t){
				if(owner){
					delete system;
				}
			}
			system = t;
		}
		
		void setState(Note state){
			statePosition = states.getKeyIndexByLValue(state);
			actualState = states.getByPosition(statePosition);
		}
		
		void setState(int state){
			statePosition = state;
			actualState = states.getByPosition(statePosition);
		}
		
		void lastState(){
			statePosition--;
			actualState = states.getByPosition(statePosition);
		}
		
		void nextState(){
			statePosition++;
			actualState = states.getByPosition(statePosition);
			SMSLog(higgs_Log_Statement, "nextState",  "println", Note(statePosition));
			SMSLog(higgs_Log_Statement, "nextState",  "println", Note(actualState == nullptr));
		}
		
		StateMethod* getState(){
			return actualState;
		}
		
		int getStatePosition(){
			return statePosition;
		}
		
		int getStateSize(){
			return states.getPosition();
		}
		
		virtual void update(float tpc){
			if(actualState == nullptr || system == nullptr){
				return;
			}
			states.invoke(actualState, this, system, tpc);
		}
		
		void addState(Note a_name, StateMethod a_state){
			states.addLValues(a_name, a_state);
		}
	protected:
		int statePosition = 0;
		T* system = nullptr;
		bool owner = false;
		StateMethod* actualState = nullptr;
		StaticMethodMap<Note,StateMachineSystem*,T*,float> states;
};

}

#endif