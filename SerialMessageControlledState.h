

#ifndef SerialMessageControlledState_h
#define SerialMessageControlledState_h

#include "AppState.h"
#include "Arduino.h"
#include "SerialMessageState.h"

#ifdef SerialMessageControlledStateLogApp
	#include "Logger.h"
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
