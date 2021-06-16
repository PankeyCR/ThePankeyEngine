

#ifndef SerialMessageControlledState_h
#define SerialMessageControlledState_h

#include "AppState.h"
#include "Arduino.h"
#include "BaseInvoke.h"
#include "SerialMessageState.h"

#ifdef SerialMessageControlledStateLogApp
	#include "Logger.h"
	#define SerialMessageControlledStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialMessageControlledStateLog(name,method,type,mns)
#endif

class SerialMessageControlledState : public AppState , public BaseInvoke{
    public:
		SerialMessageControlledState(){}
		virtual ~SerialMessageControlledState(){}
		bool instanceof(cppObjectClass* cls){return cls == Class<SerialMessageControlledState>::classType || AppState::instanceof(cls);}
		cppObjectClass* getClass(){return Class<SerialMessageControlledState>::classType;}
		
		void initialize(Application *a){
			app = a;
		}
		
		Application* getApplication(){return app;}
		
		SerialMessageState* getSerialMessageState(){
			if(app == nullptr){
				return nullptr;
			}
			return (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
		}
		
		virtual void send(String mns){
			if(app == nullptr){
				return;
			}
			if(app->getStateManager()->get(Class<SerialMessageState>::classType) == nullptr){
				return;
			}
			SerialMessageState* serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
			serialState->send(mns);
		}
		
		virtual void send(String name, String mns){
			if(app == nullptr){
				return;
			}
			if(app->getStateManager()->get(Class<SerialMessageState>::classType) == nullptr){
				return;
			}
			SerialMessageState* serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
			serialState->send(name, mns);
		}
	protected:		
		Application* app = nullptr;
};

#endif 
