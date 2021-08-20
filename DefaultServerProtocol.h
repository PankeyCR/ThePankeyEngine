
#ifndef DefaultServerProtocol_h
#define DefaultServerProtocol_h

#include "Application.h"
#include "ServerProtocol.h"
#include "SerialPort.h"
#include "Message.h"
#include "SerialMessageState.h"
#include "DefaultPortProtocol.h"
#include "Logger.h"

#ifdef DefaultServerProtocolLogApp
	#define DefaultServerProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DefaultServerProtocolLog(name,method,type,mns) 
#endif

namespace ame{

class DefaultServerProtocol : public ServerProtocol{	
    public:
		DefaultServerProtocol(){}
		virtual ~DefaultServerProtocol(){}
		
		virtual SerialPort* getUpdateSerialPort(SerialServer* server){
			if(this->serialState == nullptr){
				DefaultServerProtocolLog("DefaultServerProtocol", "getUpdateSerialPort",  "println", "this->serialState == nullptr");
				return nullptr;
			}
			SerialPort* port = nullptr;
			port = server->accept();
			if(port == nullptr){
				return nullptr;
			}
			DefaultServerProtocolLog("DefaultServerProtocol", "getUpdateSerialPort",  "println", port->getName());
			initialMessage(port);
			return port;
		}
		
		virtual void UpdateSerialPort(SerialPort* port){
			if(this->serialState == nullptr){
				DefaultServerProtocolLog("DefaultServerProtocol", "UpdateSerialPort",  "println", "this->serialState == nullptr");
				return;
			}
			if(!this->serialState->containSerialPort(port)){
				DefaultServerProtocolLog("DefaultServerProtocol", "UpdateSerialPort",  "println", "!this->serialState->containSerialPort(port)");
				this->serialState->addSerialPort(port, new DefaultPortProtocol());
			}
		}
		
		virtual void initialMessage(SerialPort* port){}
		
	protected:
};

}

#endif 
