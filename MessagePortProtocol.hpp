
#include "ame_Enviroment.hpp"

#ifndef MessagePortProtocol_hpp
#define MessagePortProtocol_hpp

#include "SerialPort.hpp"
#include "DefaultPortProtocol.hpp"
#include "SerialListenerState.hpp"
#include "MessageCommand.hpp"

#ifdef MessagePortProtocol_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MessagePortProtocolLog(location,method,type,mns) ame_Log(this,location,"MessagePortProtocol",method,type,mns)
	#define const_MessagePortProtocolLog(location,method,type,mns) 
	#define StaticMessagePortProtocolLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MessagePortProtocol",method,type,mns)
#else
	#ifdef MessagePortProtocol_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MessagePortProtocolLog(location,method,type,mns) ame_LogDebug(this,location,"MessagePortProtocol",method,type)
		#define const_MessagePortProtocolLog(location,method,type,mns) 
		#define StaticMessagePortProtocolLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MessagePortProtocol",method,type)
	#else
		#define MessagePortProtocolLog(location,method,type,mns) 
		#define const_MessagePortProtocolLog(location,method,type,mns) 
		#define StaticMessagePortProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class MessagePortProtocol : public DefaultPortProtocol{
public:
	MessagePortProtocol(){}
	virtual ~MessagePortProtocol(){}

		
	virtual void Read(int index, SerialPort* port){
		MessagePortProtocolLog(ame_Log_Statement, "Read",  "println", "");
		char m = port->read();
		MessagePortProtocolLog(ame_Log_Statement, "Read",  "println", ame_String("read char: ") + ame_String(m));
		if(m == '\n' && messageText.length() != 0){
			MessagePortProtocolLog(ame_Log_Statement, "Read",  "println", "m == '\n' && messageText.length() != 0");
			if(this->serialState == nullptr){
				MessagePortProtocolLog(ame_Log_Statement, "Read",  "println", "this->serialState == nullptr");
				return;
			}
			if(this->serialState->getApp() == nullptr){
				MessagePortProtocolLog(ame_Log_Statement, "Read",  "println", "this->serialState->getApp() == nullptr");
				return;
			}
			if(this->serialState->getApp()->getStateManager() == nullptr){
				MessagePortProtocolLog(ame_Log_Statement, "Read",  "println", "this->serialState->getApp()->getStateManager() == nullptr");
				return;
			}
			
			SerialListenerState<Message>* listenerState = this->serialState->getApp()->getStateManager()->getState<SerialListenerState<Message>>();
			
			if(listenerState == nullptr){
				return;
			}
			Message* i_message = new Message();
			i_message->id(index);
			i_message->text(messageText);
			listenerState->addMail(i_message);
			
			messageText = "";
		}
		if(m != '\r' && m != '\n'){
			messageText.concat(m);
		}
	}

protected:
	
};

}

#endif 
