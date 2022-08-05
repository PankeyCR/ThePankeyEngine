
#include "ame_Enviroment.hpp"

#if defined(DISABLE_StartEndPortProtocol) || defined(ame_upToLevel_1)
	#define StartEndPortProtocol_hpp
#endif

#ifndef StartEndPortProtocol_hpp
#define StartEndPortProtocol_hpp
#define StartEndPortProtocol_AVAILABLE

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

#ifdef StartEndPortProtocol_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define StartEndPortProtocolLog(location,method,type,mns) ame_Log(this,location,"StartEndPortProtocol",method,type,mns)
	#define const_StartEndPortProtocolLog(location,method,type,mns) 
	#define StaticStartEndPortProtocolLog(pointer,location,method,type,mns) ame_Log(pointer,location,"StartEndPortProtocol",method,type,mns)
#else
	#ifdef StartEndPortProtocol_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define StartEndPortProtocolLog(location,method,type,mns) ame_LogDebug(this,location,"StartEndPortProtocol",method,type)
		#define const_StartEndPortProtocolLog(location,method,type,mns) 
		#define StaticStartEndPortProtocolLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"StartEndPortProtocol",method,type)
	#else
		#define StartEndPortProtocolLog(location,method,type,mns) 
		#define const_StartEndPortProtocolLog(location,method,type,mns) 
		#define StaticStartEndPortProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class StartEndPortProtocol : public PortProtocol{	
    public:
		StartEndPortProtocol(){}
		StartEndPortProtocol(char s, char e){
			m_start = s;
			m_end = e;
		}
		virtual ~StartEndPortProtocol(){}
		
		virtual void InstantBroadcastMessage(SerialPort* port, Note mns){
			StartEndPortProtocolLog(ame_Log_Statement, "InstantBroadcastMessage",  "println", port->getName());
			StartEndPortProtocolLog(ame_Log_Statement, "InstantBroadcastMessage",  "println", mns);
			port->print(Note(m_start) + mns + Note(m_end));
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, Note mns){
			StartEndPortProtocolLog(ame_Log_Statement, "InstantPrivateMessage",  "println", port->getName());
			StartEndPortProtocolLog(ame_Log_Statement, "InstantPrivateMessage",  "println", mns);
			port->print(Note(m_start) + mns + Note(m_end));
		}
		
		virtual void BroadcastMessage(SerialPort* port, Note mns){
			StartEndPortProtocolLog(ame_Log_Statement, "BroadcastMessage",  "println", port->getName());
			StartEndPortProtocolLog(ame_Log_Statement, "BroadcastMessage",  "println", mns);
			port->print(Note(m_start) + mns + Note(m_end));
		}
		
		virtual void PrivateMessage(SerialPort* port, Note mns){
			StartEndPortProtocolLog(ame_Log_Statement, "PrivateMessage",  "println", port->getName());
			StartEndPortProtocolLog(ame_Log_Statement, "PrivateMessage",  "println", mns);
			port->print(Note(m_start) + mns + Note(m_end));
		}
		
		virtual void GlobalDisconect(SerialPort* port){
			StartEndPortProtocolLog(ame_Log_Statement, "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void Disconect(SerialPort* port){
			StartEndPortProtocolLog(ame_Log_Statement, "Disconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void UpdateDisconect(SerialPort* port){
			StartEndPortProtocolLog(ame_Log_Statement, "UpdateDisconect",  "println", "");
			StartEndPortProtocolLog(ame_Log_Statement, "UpdateDisconect",  "println", Note("port name: ") + Note(port->getName()));
			port->flush();
			port->stop();
		}
		
		Note StartEndRead(int index, SerialPort* port){
			StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", "");
			char m = port->read();
			StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", Note(m));
			if((m == m_end) && messageText.length() > 0){
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", Note("messageText.length(): ") + Note(messageText.length()));
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", "adding Message to serialState");
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", Note("messageText: ") + messageText);
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", Note("index: ") + Note(index));
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", "raw");
				Note r_message = messageText;
				messageText = "";
				m_read = false;
				return r_message;
			}
			if(m == m_start){
				m_read = true;
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", Note("start adding char to messageText: ") + Note(m));
				return "";
			}
			if(m_read){
				StartEndPortProtocolLog(ame_Log_Statement, "StartEndRead",  "println", Note("adding char to messageText: ") + Note(m));
				messageText.concat(m);
			}
			return "";
		}
		
	protected:
		Note messageText = "";
		char m_start = '!';
		char m_end = '!';
		bool m_read = false;
};

}

#endif