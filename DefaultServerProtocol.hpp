
#ifndef DefaultServerProtocol_hpp
#define DefaultServerProtocol_hpp

#include "Application.hpp"
#include "ServerProtocol.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"
#include "SerialState.hpp"

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#ifdef DefaultServerProtocol_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"
	
	#define DefaultServerProtocolLog(location,method,type,mns) higgs_Log(this,location,"DefaultServerProtocol",method,type,mns)
	#define const_DefaultServerProtocolLog(location,method,type,mns) 
	#define StaticDefaultServerProtocolLog(pointer,location,method,type,mns) higgs_Log(pointer,location,"DefaultServerProtocol",method,type,mns)
#else
	#ifdef DefaultServerProtocol_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"
		
		#define DefaultServerProtocolLog(location,method,type,mns) higgs_LogDebug(this,location,"DefaultServerProtocol",method,type)
		#define const_DefaultServerProtocolLog(location,method,type,mns) 
		#define StaticDefaultServerProtocolLog(pointer,location,method,type,mns) higgs_LogDebug(pointer,location,"DefaultServerProtocol",method,type)
	#else
		#define DefaultServerProtocolLog(location,method,type,mns) 
		#define const_DefaultServerProtocolLog(location,method,type,mns) 
		#define StaticDefaultServerProtocolLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace higgs{

template<class T>
class DefaultServerProtocol : public ServerProtocol{	
    public:
		DefaultServerProtocol(){
			DefaultServerProtocolLog(higgs_Log_StartMethod, "Constructor",  "println", "");
			DefaultServerProtocolLog(higgs_Log_EndMethod, "Constructor",  "println", "");
		}
		virtual ~DefaultServerProtocol(){
			DefaultServerProtocolLog(higgs_Log_StartMethod, "Destructor",  "println", "");
			DefaultServerProtocolLog(higgs_Log_EndMethod, "Destructor",  "println", "");
		}
		
		virtual SerialPort* getUpdateSerialPort(SerialServer* server){
			DefaultServerProtocolLog(higgs_Log_StartMethod, "getUpdateSerialPort",  "println", "");
			if(this->serialState == nullptr){
				DefaultServerProtocolLog(higgs_Log_EndMethod, "getUpdateSerialPort",  "println", "this->serialState == nullptr");
				return nullptr;
			}
			SerialPort* port = nullptr;
			port = server->accept();
			if(port == nullptr){
				DefaultServerProtocolLog(higgs_Log_EndMethod, "getUpdateSerialPort",  "println", "port == nullptr");
				return nullptr;
			}
			DefaultServerProtocolLog(higgs_Log_EndMethod, "getUpdateSerialPort",  "println", port->getName());
			return port;
		}
		
		virtual void UpdateSerialPort(SerialPort* port){
			DefaultServerProtocolLog(higgs_Log_StartMethod, "UpdateSerialPort",  "println", "");
			if(this->serialState == nullptr){
				DefaultServerProtocolLog(higgs_Log_EndMethod, "UpdateSerialPort",  "println", "this->serialState == nullptr");
				return;
			}
			if(!this->serialState->containSerialPort(port)){
				DefaultServerProtocolLog(higgs_Log_Statement, "UpdateSerialPort",  "println", "!this->serialState->containSerialPort(port)");
				T* t_protocol = new T();
				initialMessage(port, t_protocol);
				this->serialState->addSerialPort(port, t_protocol);
				t_protocol->initialize(this->serialState);
			}
			DefaultServerProtocolLog(higgs_Log_EndMethod, "UpdateSerialPort",  "println", "this->serialState == nullptr");
		}
		
		virtual void initialMessage(SerialPort* port, T* t){}
		
	protected:
};

}

#endif