
#ifndef RadioProtocol_h
#define RadioProtocol_h

#include "PortProtocol.h"
#include "SerialPort.h"
#include "Logger.h"

#ifdef RadioProtocolLogApp
	#define RadioProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define RadioProtocolLog(name,method,type,mns) 
#endif

namespace ame{

enum class RadioType{
	SPY
};

class RadioProtocol : public PortProtocol{	
    public:
		RadioProtocol(){}
		virtual ~RadioProtocol(){}
		
		virtual void InstantBroadcastMessage(SerialPort* port, String mns){
			RadioProtocolLog("RadioProtocol", "InstantBroadcastMessage",  "println", port->getName());
			RadioProtocolLog("RadioProtocol", "InstantBroadcastMessage",  "println", mns);
			port->println(mns);
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, String mns){
			RadioProtocolLog("RadioProtocol", "InstantPrivateMessage",  "println", port->getName());
			RadioProtocolLog("RadioProtocol", "InstantPrivateMessage",  "println", mns);
			port->println(mns);
		}
		
		virtual void GlobalDisconect(SerialPort* port){
			RadioProtocolLog("RadioProtocol", "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void Disconect(SerialPort* port){
			RadioProtocolLog("RadioProtocol", "Disconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void UpdateDisconect(SerialPort* port){
			RadioProtocolLog("RadioProtocol", "UpdateDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		
		virtual void BroadcastMessage(SerialPort* port, String mns){
			RadioProtocolLog("RadioProtocol", "BroadcastMessage",  "println", port->getName());
			RadioProtocolLog("RadioProtocol", "BroadcastMessage",  "println", mns);
			port->println(mns);
		}
		virtual void PrivateMessage(SerialPort* port, String mns){
			RadioProtocolLog("RadioProtocol", "PrivateMessage",  "println", port->getName());
			RadioProtocolLog("RadioProtocol", "PrivateMessage",  "println", mns);
			port->println(mns);
		}
		
		virtual void Read(int index, SerialPort* port){
			char m = port->read();
			if(m == '\n' && messageText.length() != 0){
				RadioProtocolLog("RadioProtocol", "Read",  "println", "adding Message to serialState");
				RadioProtocolLog("RadioProtocol", "Read",  "println", String("messageText: ") + messageText);
				RadioProtocolLog("RadioProtocol", "Read",  "println", String("index: ") + String(index));
				RadioProtocolLog("RadioProtocol", "Read",  "println", "raw");
				Message* message = new Message();
				message->name(port->getName());
				message->text(messageText);
				message->id(index);
				message->type("raw");
				this->serialState->addReceivedMessage(message);
				messageText = "";
				return;
			}
			if(m != '\n'){
				RadioProtocolLog("RadioProtocol", "Read",  "println", String("adding char to messageText: ") + String(m));
				messageText.concat(m);
			}
		}
		
		virtual void setType(RadioType t){
			radioType = t;
		}
		
	protected:
		RadioType radioType = RadioType::SPY;
		String messageText = "";
};

}

#endif 
