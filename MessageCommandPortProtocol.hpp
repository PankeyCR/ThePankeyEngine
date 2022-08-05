
#include "ame_Enviroment.hpp"

#ifndef MessageCommandPortProtocol_hpp
#define MessageCommandPortProtocol_hpp

#include "SerialPort.hpp"
#include "DefaultPortProtocol.hpp"
#include "SerialListenerState.hpp"
#include "MessageCommand.hpp"

#ifdef MessageCommandPortProtocol_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MessageCommandPortProtocolLog(location,method,type,mns) ame_Log(this,location,"MessageCommandPortProtocol",method,type,mns)
	#define const_MessageCommandPortProtocolLog(location,method,type,mns) 
	#define StaticMessageCommandPortProtocolLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MessageCommandPortProtocol",method,type,mns)
#else
	#ifdef MessageCommandPortProtocol_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MessageCommandPortProtocolLog(location,method,type,mns) ame_LogDebug(this,location,"MessageCommandPortProtocol",method,type)
		#define const_MessageCommandPortProtocolLog(location,method,type,mns) 
		#define StaticMessageCommandPortProtocolLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MessageCommandPortProtocol",method,type)
	#else
		#define MessageCommandPortProtocolLog(location,method,type,mns) 
		#define const_MessageCommandPortProtocolLog(location,method,type,mns) 
		#define StaticMessageCommandPortProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class MessageCommandPortProtocol : public DefaultPortProtocol{
public:
	MessageCommandPortProtocol(){}
	virtual ~MessageCommandPortProtocol(){}

		
	virtual void Read(int index, SerialPort* port){
		MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", "");
		char m = port->read();
		MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", ame_String("read char: ") + ame_String(m));
		if(m == ' ' || (m == '\n' && messageText.length() != 0) ){
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", "m == ' ' || (m == '\n' && messageText.length() != 0) ");
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", ame_String("m_size: ") + ame_String(m_size));
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("messageText: ") + messageText);
			if(m_size == 0){
				mns_1 = messageText;
			}
			if(m_size == 1){
				mns_2 = messageText;
			}
			if(m_size == 2){
				mns_3 = messageText;
			}
			if(m_size == 3){
				mns_4 = messageText;
			}
			messageText = "";
			m_size++;
		}
		if(m == '\n' && m_size != 0){
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", "m == '\n' && messageText.length() != 0");
			if(this->serialState == nullptr){
				MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", "this->serialState == nullptr");
				return;
			}
			if(this->serialState->getApp() == nullptr){
				MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", "this->serialState->getApp() == nullptr");
				return;
			}
			if(this->serialState->getApp()->getStateManager() == nullptr){
				MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", "this->serialState->getApp()->getStateManager() == nullptr");
				return;
			}
			
			SerialListenerState<MessageCommand>* listenerState = this->serialState->getApp()->getStateManager()->getState<SerialListenerState<MessageCommand>>();
			
			if(listenerState == nullptr){
				return;
			}
			if(m_size == 0){
				return;
			}
			MessageCommand* i_message = new MessageCommand();
			if(m_size >= 1){
				i_message->addMessage(mns_1);
			}
			if(m_size >= 2){
				i_message->addMessage(mns_2);
			}
			if(m_size >= 3){
				i_message->addMessage(mns_3);
			}
			if(m_size >= 4){
				i_message->addMessage(mns_4);
			}
			i_message->setId(index);
			listenerState->addMail(i_message);
			
			messageText = "";
			m_size = 0;
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", ame_String("m_size: ") + ame_String(m_size));
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("messageText: ") + messageText);
			return;
		}
		if(m != ' ' && m != '\r' && m != '\n'){
			messageText.concat(m);
			MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("concat: ") + messageText);
		}
	}

	virtual void update(SerialPort* port, float tpc){
		m_timer += tpc;
		MessageCommandPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("MessageCommandPortProtocol Timer: ") + Note(m_timer));
	}
	
	virtual float getTimer(){
		return m_timer;
	}
		
	#ifndef DISABLE_cppObject
	
	virtual cppObjectClass* getClass(){return Class<MessageCommandPortProtocol>::classType;}
	virtual Note toNote(){return "MessageCommandPortProtocol";}
	virtual bool instanceof(cppObjectClass* cls){return cls == Class<MessageCommandPortProtocol>::classType || cppObject::instanceof(cls);}
	
	#endif
	
protected:
	Note mns_1;
	Note mns_2;
	Note mns_3;
	Note mns_4;
	int m_size = 0;
	
	float m_timer = 0.0f;
};

}

#endif 
