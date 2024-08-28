
#ifndef DefaultPortProtocol_hpp
#define DefaultPortProtocol_hpp
#define DefaultPortProtocol_AVAILABLE

#include "pankey_Enviroment.hpp"

#ifndef pankey_Enviroment_Defined

#endif

#ifdef pankey_Windows

#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PortProtocol.hpp"
#include "SerialPort.hpp"
#include "Note.hpp"
#include "MessageDelivery.hpp"

#ifdef DefaultPortProtocol_LogApp
	#include "pankey_Logger_config.hpp"
	#include "pankey_Logger.hpp"
	
	#define DefaultPortProtocolLog(location,method,type,mns) pankey_Log(this,location,"DefaultPortProtocol",method,type,mns)
	#define const_DefaultPortProtocolLog(location,method,type,mns) 
	#define StaticDefaultPortProtocolLog(pointer,location,method,type,mns) pankey_Log(pointer,location,"DefaultPortProtocol",method,type,mns)
#else
	#ifdef DefaultApplication_LogDebugApp
		#include "pankey_Logger_config.hpp"
		#include "pankey_Logger.hpp"
		
		#define DefaultPortProtocolLog(location,method,type,mns) pankey_LogDebug(this,location,"DefaultPortProtocol",method,type)
		#define const_DefaultPortProtocolLog(location,method,type,mns) 
		#define StaticDefaultPortProtocolLog(pointer,location,method,type,mns) pankey_LogDebug(pointer,location,"DefaultPortProtocol",method,type)
	#else
		#define DefaultPortProtocolLog(location,method,type,mns) 
		#define const_DefaultPortProtocolLog(location,method,type,mns) 
		#define StaticDefaultPortProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace pankey{

class DefaultPortProtocol : public PortProtocol{	
    public:
		DefaultPortProtocol(){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "Constructor",  "println", "");
			DefaultPortProtocolLog(pankey_Log_EndMethod, "Constructor",  "println", "");
		}
		DefaultPortProtocol(bool s){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "Constructor",  "println", "");
			this->safeDelete = s;
			DefaultPortProtocolLog(pankey_Log_EndMethod, "Constructor",  "println", "");
		}
		DefaultPortProtocol(MessageDelivery* c_delivery){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "Constructor",  "println", "");
			this->m_delivery = c_delivery;
			DefaultPortProtocolLog(pankey_Log_EndMethod, "Constructor",  "println", "");
		}
		virtual ~DefaultPortProtocol(){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "Destructor",  "println", "");
			DefaultPortProtocolLog(pankey_Log_EndMethod, "Destructor",  "println", "");
		}
		
		virtual void InstantBroadcastMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "InstantBroadcastMessage",  "println", "");
			DefaultPortProtocolLog(pankey_Log_Statement, "InstantBroadcastMessage",  "println", port->getName());
			DefaultPortProtocolLog(pankey_Log_Statement, "InstantBroadcastMessage",  "println", mns);
			Note send_note = addNoteValue(mns, '\n');
			port->print(send_note);
			DefaultPortProtocolLog(pankey_Log_EndMethod, "InstantBroadcastMessage",  "println", "");
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "InstantPrivateMessage",  "println", port->getName());
			DefaultPortProtocolLog(pankey_Log_Statement, "InstantPrivateMessage",  "println", mns);
			port->print(mns+'\n');
			DefaultPortProtocolLog(pankey_Log_EndMethod, "InstantPrivateMessage",  "println", "");
		}
		
		virtual void BroadcastMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "BroadcastMessage",  "println", port->getName());
			DefaultPortProtocolLog(pankey_Log_Statement, "BroadcastMessage",  "println", mns);
			port->print(mns+'\n');
			DefaultPortProtocolLog(pankey_Log_EndMethod, "BroadcastMessage",  "println", "");
		}
		
		virtual void PrivateMessage(SerialPort* port, Note mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "PrivateMessage",  "println", port->getName());
			DefaultPortProtocolLog(pankey_Log_Statement, "PrivateMessage",  "println", mns);
			port->print(mns+'\n');
			DefaultPortProtocolLog(pankey_Log_EndMethod, "PrivateMessage",  "println", "");
		}
		
		virtual bool GlobalConect(SerialPort* port){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "GlobalConect",  "println", "");
			DefaultPortProtocolLog(pankey_Log_EndMethod, "GlobalConect",  "println", "");
			return false;
		}
		virtual bool Conect(SerialPort* port){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "Conect",  "println", "");
			DefaultPortProtocolLog(pankey_Log_EndMethod, "Conect",  "println", "");
			return true;
		}
		virtual bool UpdateConect(SerialPort* port){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "UpdateConect",  "println", "");
			DefaultPortProtocolLog(pankey_Log_EndMethod, "UpdateConect",  "println", "");
			return true;
		}
		
		virtual bool GlobalDisconect(SerialPort* port){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
			DefaultPortProtocolLog(pankey_Log_EndMethod, "GlobalDisconect",  "println", "");
			return true;
		}
		virtual bool Disconect(SerialPort* port){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "Disconect",  "println", "");
			port->flush();
			port->stop();
			DefaultPortProtocolLog(pankey_Log_EndMethod, "Disconect",  "println", "");
			return true;
		}
		virtual bool UpdateDisconect(SerialPort* port){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "UpdateDisconect",  "println", "");
			port->flush();
			port->stop();
			DefaultPortProtocolLog(pankey_Log_EndMethod, "UpdateDisconect",  "println", "");
			return true;
		}
		
		void Read(int index, SerialPort* port){
			char i_char = port->read();
			if((i_char == '\n') && messageText.length() != 0){
				DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", "adding Message to serialState");
				DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", Note("messageText: ") + messageText);
				DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", Note("index: ") + Note(index));
				DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", "raw");
				this->DeliverMessage(messageText);
				messageText = "";
			}
			if(i_char != '\r' && i_char != '\n'){
				DefaultPortProtocolLog(pankey_Log_Statement, "Read",  "println", Note("adding char to messageText: ") + Note(i_char));
				messageText = addNoteValue(messageText, i_char);
			}
		}
		
		virtual bool DeliverMessage(const Message& a_mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "DeliverMessage",  "println", "");
			// DefaultPortProtocolLog(pankey_Log_StartMethod, "DeliverMessage",  "println", "Message:");
			// DefaultPortProtocolLog(pankey_Log_StartMethod, "DeliverMessage",  "println", a_mns);
			if(m_delivery != nullptr){
				DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				return m_delivery->DeliverMessage(a_mns);
			}
			if(m_serialState == nullptr){
				DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				return false;
			}
			MessageDelivery* i_delivery = m_serialState->getDelivery();
			if(i_delivery == nullptr){
				DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				return false;
			}
			DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
			return i_delivery->DeliverMessage(a_mns);
		}
		
		virtual bool DeliverMessage(const Note& a_mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "DeliverMessage",  "println", "");
			DefaultPortProtocolLog(pankey_Log_Statement, "DeliverMessage",  "println", "Message:");
			DefaultPortProtocolLog(pankey_Log_Statement, "DeliverMessage",  "println", a_mns);
			if(m_delivery != nullptr){
				DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				return m_delivery->DeliverMessage(a_mns);
			}
			if(m_serialState == nullptr){
				DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				return false;
			}
			MessageDelivery* i_delivery = m_serialState->getDelivery();
			if(i_delivery == nullptr){
				DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
				return false;
			}
			DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
			return i_delivery->DeliverMessage(a_mns);
		}
		
		virtual bool DeliverMessage(const ByteArray& a_mns){
			DefaultPortProtocolLog(pankey_Log_StartMethod, "DeliverMessage",  "println", "");
			if(m_delivery != nullptr){
				return m_delivery->DeliverMessage(a_mns);
			}
			if(m_serialState == nullptr){
				return false;
			}
			MessageDelivery* i_delivery = m_serialState->getDelivery();
			if(i_delivery == nullptr){
				return false;
			}
			DefaultPortProtocolLog(pankey_Log_EndMethod, "DeliverMessage",  "println", "");
			return i_delivery->DeliverMessage(a_mns);
		}
		
	protected:
		Note messageText = "";
};

}

#endif