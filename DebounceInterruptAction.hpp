
#ifndef DebounceInterruptAction_hpp
#define DebounceInterruptAction_hpp
#define DebounceInterruptAction_AVAILABLE

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "InterruptState.hpp"
#include "PrimitiveList.hpp"

#ifdef DebounceInterruptAction_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define DebounceInterruptActionLog(location,method,type,mns) ame_Log(this,location,"DebounceInterruptAction",method,type,mns)
	#define const_DebounceInterruptActionLog(location,method,type,mns) 
	#define StaticDebounceInterruptActionLog(pointer,location,method,type,mns) ame_Log(pointer,location,"DebounceInterruptAction",method,type,mns)
#else
	#ifdef DebounceInterruptAction_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define DebounceInterruptActionLog(location,method,type,mns) ame_LogDebug(this,location,"DebounceInterruptAction",method,type)
		#define const_DebounceInterruptActionLog(location,method,type,mns) 
		#define StaticDebounceInterruptActionLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"DebounceInterruptAction",method,type)
	#else
		#define DebounceInterruptActionLog(location,method,type,mns) 
		#define const_DebounceInterruptActionLog(location,method,type,mns) 
		#define StaticDebounceInterruptActionLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

	class DebounceInterruptAction : public InterruptAction{
		protected:
			long m_millis = 0;
			bool m_action = false;
			bool m_once = true;
			// PrimitiveList<int> m_interrupts;
		public:
			DebounceInterruptAction(){}

			template<class... Args>
			DebounceInterruptAction(Args... c_args){
				//m_interrupts.addPack(c_args...);
			}

			virtual ~DebounceInterruptAction(){}

			virtual void update(float tpc){
				// bool u_state = false;
				// for(int f_interrupts : m_interrupts){
				// 	bool f_state = digitalRead(f_interrupts);
				// 	if(f_state){
				// 		u_state = true;
				// 	}
				// }
				// if(u_state == this->getState()){
				// 	return;
				// }
				// if(!m_once){
				// 	return;
				// }
				// m_once = false;
				// m_action = !m_action;
				// this->setState(u_state);
				// this->setRunningEvents(m_action);
			}
	};

}

#endif