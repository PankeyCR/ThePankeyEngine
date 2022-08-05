
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MessageInvoker)
	#define MessageInvoker_hpp
#endif

#ifndef MessageInvoker_hpp
#define MessageInvoker_hpp
#define MessageInvoker_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"
#include "Command.hpp"
#include "Message.hpp"
#include "PrimitiveList.hpp"

#ifdef MessageInvokerLogApp
	#include "Logger.hpp"
	#define MessageInvokerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define MessageInvokerLog(name,method,type,mns) 
#endif

namespace ame{

class MessageInvoker : public Command<Message>{
	using InvokerMethod = void (*)(Message*);
    public:
		MessageInvoker(){
			MessageInvokerLog("MessageInvoker", "Constructor",  "println", "");
			list = new PrimitiveList<InvokerMethod>();
		}
		
		MessageInvoker(bool own){
			MessageInvokerLog("MessageInvoker", "Constructor",  "println", Note("Map ownership: ") + Note(own));
			list = new PrimitiveList<InvokerMethod>(own);
		}
		
		virtual ~MessageInvoker(){
			MessageInvokerLog("MessageInvoker", "Destructor",  "println", "");
			delete list;
		}
		

		void execute(Message* mns){
			MessageInvokerLog("MessageInvoker", "execute",  "println", "");
			for(int x = 0; x < list->getPosition(); x++){
				InvokerMethod method = *list->getByPosition(x);
				method(mns);
			}
		}
		
		void add(InvokerMethod m){
			list->addLValue(m);
		}

	protected:
		PrimitiveList<void (*)(Message*)>* list = nullptr;
};

}

#endif