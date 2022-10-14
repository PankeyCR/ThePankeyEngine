
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultPortProtocol)
	#define DefaultPortProtocol_hpp
#endif

#ifndef DefaultPortProtocol_hpp
#define DefaultPortProtocol_hpp
#define DefaultPortProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PortProtocol.hpp"
#include "SerialPort.hpp"
#include "Note.hpp"
#include "MessageDelivery.hpp"

#ifdef DefaultPortProtocol_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define DefaultPortProtocolLog(location,method,type,mns) ame_Log(this,location,"DefaultPortProtocol",method,type,mns)
	#define const_DefaultPortProtocolLog(location,method,type,mns) 
	#define StaticDefaultPortProtocolLog(pointer,location,method,type,mns) ame_Log(pointer,location,"DefaultPortProtocol",method,type,mns)
#else
	#ifdef DefaultApplication_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define DefaultPortProtocolLog(location,method,type,mns) ame_LogDebug(this,location,"DefaultPortProtocol",method,type)
		#define const_DefaultPortProtocolLog(location,method,type,mns) 
		#define StaticDefaultPortProtocolLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"DefaultPortProtocol",method,type)
	#else
		#define DefaultPortProtocolLog(location,method,type,mns) 
		#define const_DefaultPortProtocolLog(location,method,type,mns) 
		#define StaticDefaultPortProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class DefaultPortProtocol : public PortProtocol{	
    public:
		DefaultPortProtocol(){}
		DefaultPortProtocol(bool s){
			this->safeDelete = s;
		}
		DefaultPortProtocol(MessageDelivery* c_delivery){
			this->m_delivery = c_delivery;
		}
		virtual ~DefaultPortProtocol(){}
		
		virtual void InstantBroadcastMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(ame_Log_Statement, "InstantBroadcastMessage",  "println", port->getName());
			DefaultPortProtocolLog(ame_Log_Statement, "InstantBroadcastMessage",  "println", mns);
			port->print(mns+'\n');
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(ame_Log_Statement, "InstantPrivateMessage",  "println", port->getName());
			DefaultPortProtocolLog(ame_Log_Statement, "InstantPrivateMessage",  "println", mns);
			port->print(mns+'\n');
		}
		
		virtual void BroadcastMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(ame_Log_Statement, "BroadcastMessage",  "println", port->getName());
			DefaultPortProtocolLog(ame_Log_Statement, "BroadcastMessage",  "println", mns);
			port->print(mns+'\n');
		}
		
		virtual void PrivateMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(ame_Log_Statement, "PrivateMessage",  "println", port->getName());
			DefaultPortProtocolLog(ame_Log_Statement, "PrivateMessage",  "println", mns);
			port->print(mns+'\n');
		}
		
		virtual void GlobalConect(SerialPort* port){
			DefaultPortProtocolLog(ame_Log_Statement, "GlobalConect",  "println", "");
		}
		virtual void Conect(SerialPort* port){
			DefaultPortProtocolLog(ame_Log_Statement, "Conect",  "println", "");
		}
		virtual void UpdateConect(SerialPort* port){
			DefaultPortProtocolLog(ame_Log_Statement, "UpdateConect",  "println", "");
		}
		
		virtual void GlobalDisconect(SerialPort* port){
			DefaultPortProtocolLog(ame_Log_Statement, "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void Disconect(SerialPort* port){
			DefaultPortProtocolLog(ame_Log_Statement, "Disconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void UpdateDisconect(SerialPort* port){
			DefaultPortProtocolLog(ame_Log_Statement, "UpdateDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		
		void Read(int index, SerialPort* port){
			char m = port->read();
			if((m == '\n') && messageText.length() != 0){
				DefaultPortProtocolLog(ame_Log_Statement, "Read",  "println", "adding Message to serialState");
				DefaultPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("messageText: ") + messageText);
				DefaultPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("index: ") + Note(index));
				DefaultPortProtocolLog(ame_Log_Statement, "Read",  "println", "raw");
				Note* i_delivery = new Note(messageText);
				this->DeliverMessage(i_delivery);
				messageText = "";
			}
			if(m != '\r' && m != '\n'){
				DefaultPortProtocolLog(ame_Log_Statement, "Read",  "println", Note("adding char to messageText: ") + Note(m));
				messageText.concat(m);
			}
		}
		
		virtual bool DeliverMessage(Note* a_mns){
			DefaultPortProtocolLog(ame_Log_Statement, "DeliverMessage",  "println", "");
			if(serialState != nullptr){
				MessageDelivery* i_delivery = serialState->getDelivery();
				if(i_delivery != nullptr){
					return i_delivery->DeliverMessage(a_mns);
				}
			}
			if(m_delivery == nullptr){
				return false;
			}
			return m_delivery->DeliverMessage(a_mns);
		}
		
		virtual bool DeliverMessage(ByteArray* a_mns){
			DefaultPortProtocolLog(ame_Log_Statement, "DeliverMessage",  "println", "");
			if(serialState != nullptr){
				MessageDelivery* i_delivery = serialState->getDelivery();
				if(i_delivery != nullptr){
					return i_delivery->DeliverMessage(a_mns);
				}
			}
			if(m_delivery == nullptr){
				return false;
			}
			return m_delivery->DeliverMessage(a_mns);
		}
		
	protected:
		Note messageText = "";
};

}

#endif