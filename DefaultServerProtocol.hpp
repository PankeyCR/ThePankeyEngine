
#include "ame_Level.hpp"

#if defined(ame_untilLevel_6)

#ifndef DefaultServerProtocol_hpp
#define DefaultServerProtocol_hpp

#include "Application.hpp"
#include "ServerProtocol.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"
#include "SerialMessageState.hpp"

#ifdef DefaultServerProtocolLogApp
	#include "Logger.hpp"
	#define DefaultServerProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DefaultServerProtocolLog(name,method,type,mns) 
#endif

namespace ame{

template<class T>
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
				this->serialState->addSerialPort(port, new T());
			}
		}
		
		virtual void initialMessage(SerialPort* port){}
		
	protected:
};

}

#endif 

#endif 
