
#ifndef DefaultPortProtocol_h
#define DefaultPortProtocol_h

#include "PortProtocol.h"
#include "SerialPort.h"
#include "Logger.h"

#ifdef DefaultPortProtocolLogApp
	#define DefaultPortProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DefaultPortProtocolLog(name,method,type,mns) 
#endif

class DefaultPortProtocol : public PortProtocol{	
    public:
		DefaultPortProtocol(){}
		virtual ~DefaultPortProtocol(){}
		
		virtual void InstantBroadcastMessage(SerialPort* port, String mns){
			DefaultPortProtocolLog("DefaultPortProtocol", "InstantBroadcastMessage",  "println", port->getName());
			DefaultPortProtocolLog("DefaultPortProtocol", "InstantBroadcastMessage",  "println", mns);
			port->println(mns);
		}
		
		virtual void InstantPrivateMessage(SerialPort* port, String mns){
			DefaultPortProtocolLog("DefaultPortProtocol", "InstantPrivateMessage",  "println", port->getName());
			DefaultPortProtocolLog("DefaultPortProtocol", "InstantPrivateMessage",  "println", mns);
			port->println(mns);
		}
		
		virtual void GlobalDisconect(SerialPort* port){
			if(!this->serialState->containSerialPort(port)){
				DefaultPortProtocolLog("DefaultPortProtocol", "GlobalDisconect",  "println", "!this->serialState->containSerialPort(port)");
				return;
			}
			DefaultPortProtocolLog("DefaultPortProtocol", "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
			this->serialState->removeDeleteSerialPort(port);
		}
		virtual void Disconect(SerialPort* port){
			if(!this->serialState->containSerialPort(port)){
				DefaultPortProtocolLog("DefaultPortProtocol", "Disconect",  "println", "!this->serialState->containSerialPort(port)");
				return;
			}
			DefaultPortProtocolLog("DefaultPortProtocol", "Disconect",  "println", "");
			port->flush();
			port->stop();
			this->serialState->removeDeleteSerialPort(port);
		}
		virtual void UpdateDisconect(SerialPort* port){
			if(!this->serialState->containSerialPort(port)){
				DefaultPortProtocolLog("DefaultPortProtocol", "UpdateDisconect",  "println", "!this->serialState->containSerialPort(port)");
				return;
			}
			DefaultPortProtocolLog("DefaultPortProtocol", "UpdateDisconect",  "println", "");
			port->flush();
			port->stop();
			this->serialState->removeDeleteSerialPort(port);
		}
		
		virtual void BroadcastMessage(SerialPort* port, String mns){
			DefaultPortProtocolLog("DefaultPortProtocol", "BroadcastMessage",  "println", port->getName());
			DefaultPortProtocolLog("DefaultPortProtocol", "BroadcastMessage",  "println", mns);
			port->println(mns);
		}
		virtual void PrivateMessage(SerialPort* port, String mns){
			DefaultPortProtocolLog("DefaultPortProtocol", "PrivateMessage",  "println", port->getName());
			DefaultPortProtocolLog("DefaultPortProtocol", "PrivateMessage",  "println", mns);
			port->println(mns);
		}
		
		virtual void Read(int index, SerialPort* port){
			char m = port->read();
			if(m == '\n' && messageText.length() != 0){
				DefaultPortProtocolLog("DefaultPortProtocol", "Read",  "println", "adding Message to serialState");
				DefaultPortProtocolLog("DefaultPortProtocol", "Read",  "println", String("messageText: ") + messageText);
				DefaultPortProtocolLog("DefaultPortProtocol", "Read",  "println", String("index: ") + String(index));
				DefaultPortProtocolLog("DefaultPortProtocol", "Read",  "println", "raw");
				Message* message = new Message();
				message->text(messageText);
				message->id(index);
				message->type("raw");
				this->serialState->addReceivedMessage(message);
				messageText = "";
				return;
			}
			if(m != '\n'){
				DefaultPortProtocolLog("DefaultPortProtocol", "Read",  "println", String("adding char to messageText: ") + String(m));
				messageText.concat(m);
			}
		}
		
	protected:
		String messageText = "";
};
#endif 
