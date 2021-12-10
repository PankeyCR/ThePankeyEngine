
#include "ame_Level.hpp"

#if defined(ame_untilLevel_6)

#ifndef StartEndPortProtocol_hpp
#define StartEndPortProtocol_hpp

#include "PortProtocol.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"

#ifdef StartEndPortProtocolLogApp
	#include "Logger.hpp"
	#define StartEndPortProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define StartEndPortProtocolLog(name,method,type,mns) 
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
		
		virtual void InstantBroadcastMessage(SerialPort* port, String mns){
			StartEndPortProtocolLog("StartEndPortProtocol", "InstantBroadcastMessage",  "println", port->getName());
			StartEndPortProtocolLog("StartEndPortProtocol", "InstantBroadcastMessage",  "println", mns);
			port->print(String(m_start) + mns + String(m_end));
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, String mns){
			StartEndPortProtocolLog("StartEndPortProtocol", "InstantPrivateMessage",  "println", port->getName());
			StartEndPortProtocolLog("StartEndPortProtocol", "InstantPrivateMessage",  "println", mns);
			port->print(String(m_start) + mns + String(m_end));
		}
		
		virtual void BroadcastMessage(SerialPort* port, String mns){
			StartEndPortProtocolLog("StartEndPortProtocol", "BroadcastMessage",  "println", port->getName());
			StartEndPortProtocolLog("StartEndPortProtocol", "BroadcastMessage",  "println", mns);
			port->print(String(m_start) + mns + String(m_end));
		}
		
		virtual void PrivateMessage(SerialPort* port, String mns){
			StartEndPortProtocolLog("StartEndPortProtocol", "PrivateMessage",  "println", port->getName());
			StartEndPortProtocolLog("StartEndPortProtocol", "PrivateMessage",  "println", mns);
			port->print(String(m_start) + mns + String(m_end));
		}
		
		virtual void GlobalDisconect(SerialPort* port){
			StartEndPortProtocolLog("StartEndPortProtocol", "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void Disconect(SerialPort* port){
			StartEndPortProtocolLog("StartEndPortProtocol", "Disconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void UpdateDisconect(SerialPort* port){
			StartEndPortProtocolLog("StartEndPortProtocol", "UpdateDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		
		virtual void Read(int index, SerialPort* port){
			char m = port->read();
			if((m == m_end) && messageText.length() != 0){
				StartEndPortProtocolLog("StartEndPortProtocol", "Read",  "println", "adding Message to serialState");
				StartEndPortProtocolLog("StartEndPortProtocol", "Read",  "println", String("messageText: ") + messageText);
				StartEndPortProtocolLog("StartEndPortProtocol", "Read",  "println", String("index: ") + String(index));
				StartEndPortProtocolLog("StartEndPortProtocol", "Read",  "println", "raw");
				Message* message = new Message();
				message->name(port->getName());
				message->text(messageText);
				message->id(index);
				message->type("raw");
				this->serialState->addReceivedMessage(message);
				messageText = "";
				m_read = false;
				return;
			}
			if(m == m_start){
				m_read = true;
				StartEndPortProtocolLog("StartEndPortProtocol", "Read",  "println", String("start adding char to messageText: ") + String(m));
				return;
			}
			if(m_read){
				StartEndPortProtocolLog("StartEndPortProtocol", "Read",  "println", String("adding char to messageText: ") + String(m));
				messageText.concat(m);
			}
		}
		
	protected:
		String messageText = "";
		char m_start = '!';
		char m_end = '!';
		bool m_read = false;
};

}

#endif 

#endif 
