

#ifndef MessageStaticMethodInvokeListener_h
#define MessageStaticMethodInvokeListener_h

#include "Arduino.h"
#include "Command.h"
#include "Message.h"
#include "Note.h"
#include "Map.h"
#include "Method.h"
#include "StaticMethods.h"
#include "Logger.h"

#ifdef MessageStaticMethodInvokeListenerLogApp
	#define MessageStaticMethodInvokeListenerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MessageStaticMethodInvokeListenerLog(name,method,type,mns) 
#endif

class MessageStaticMethodInvokeListener : public Command<Message>{
    public:
		StaticMethods<String,Message>* methods = nullptr;
		
		MessageStaticMethodInvokeListener(){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "Constructor",  "println", "");
			methods = new StaticMethods<String,Message>();
		}
		~MessageStaticMethodInvokeListener(){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "Destructor",  "println", "");
			delete methods;
		}

		void execute(Message* mns){
			MessageStaticMethodInvokeListenerLog("MessageStaticMethodInvokeListener", "execute",  "println", "");
			methods->invoke(*mns);
		}

protected:
};

#endif 
