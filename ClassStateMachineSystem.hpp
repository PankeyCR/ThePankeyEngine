
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassStateMachineSystem)
	#define ClassStateMachineSystem_hpp
#endif

#ifndef ClassStateMachineSystem_hpp
#define ClassStateMachineSystem_hpp
#define ClassStateMachineSystem_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveMap.hpp"
#include "MachineState.hpp"

#ifdef CSMS_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define CSMSLog(location,method,type,mns) ame_Log(nullptr,location,"ClassStateMachineSystem",method,type,mns)
#else
	#ifdef CSMS_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define CSMSLog(location,method,type,mns) ame_LogDebug(nullptr,location,"ClassStateMachineSystem",method,type)
	#else
		#define CSMSLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

template<class T>
class ClassStateMachineSystem{	
    public:
		ClassStateMachineSystem(){}
		virtual ~ClassStateMachineSystem(){}
		
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
			CSMSLog(ame_Log_Statement, "nextState",  "println", Note(statePosition));
			CSMSLog(ame_Log_Statement, "nextState",  "println", Note(actualState == nullptr));
		}
		
		MachineState<T>* getState(){
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
			actualState->update(this, system, tpc);
		}
		
		void addState(Note a_name, MachineState<T>* a_state){
			states.addPointer(a_name, a_state);
		}
	protected:
		int statePosition = 0;
		T* system = nullptr;
		bool owner = false;
		MachineState<T>* actualState = nullptr;
		PrimitiveMap<Note,MachineState<T>> states;
};

}

#endif