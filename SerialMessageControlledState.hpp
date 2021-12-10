
#ifndef SerialMessageControlledState_hpp
#define SerialMessageControlledState_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


#include "AppState.hpp"
#include "SerialMessageState.hpp"

#ifdef SerialMessageControlledStateLogApp
	#include "Logger.hpp"
	#define SerialMessageControlledStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialMessageControlledStateLog(name,method,type,mns)
#endif

namespace ame{

class SerialMessageControlledState : public AppState{
    public:
		SerialMessageControlledState(){}
		virtual ~SerialMessageControlledState(){}
		bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialMessageControlledState>::classType || AppState::instanceof(cls);
		}
		cppObjectClass* getClass(){return Class<SerialMessageControlledState>::classType;}
		
		void initialize(Application *a){
			app = a;
			serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
		}
		
		Application* getApplication(){return app;}
		
		SerialMessageState* getSerialMessageState(){
			if(app == nullptr){
				return nullptr;
			}
			if(serialState == nullptr){
				serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
			}
			return serialState;
		}
		
		virtual void send(String mns){
			if(app == nullptr){
				return;
			}
			if(serialState == nullptr){
				serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
				if(serialState == nullptr){
					return;
				}
			}
			serialState->send(mns);
		}
		
		virtual void send(String name, String mns){
			if(app == nullptr){
				return;
			}
			if(serialState == nullptr){
				serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
				if(serialState == nullptr){
					return;
				}
			}
			serialState->send(name, mns);
		}
	protected:		
		Application* app = nullptr;
		SerialMessageState* serialState = nullptr;
};

}

#endif 
