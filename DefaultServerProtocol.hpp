
#ifndef DefaultServerProtocol_hpp
	#define DefaultServerProtocol_hpp

	#include "Application.hpp"
	#include "ServerProtocol.hpp"
	#include "SerialPort.hpp"
	#include "Message.hpp"
	#include "SerialState.hpp"

	#ifndef pankey_Enviroment_Defined

	#endif

	#ifdef pankey_Windows

	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
	#endif

	#ifdef DefaultServerProtocol_LogApp
		#include "pankey_Logger_config.hpp"
		#define DefaultServerProtocolLog(location,method,type,mns) pankey_Log((void*)this,location,"DefaultServerProtocol",method,type,mns)
	#else
		#define DefaultServerProtocolLog(location,method,type,mns)
	#endif

	namespace pankey{

		template<class T>
		class DefaultServerProtocol : public ServerProtocol{	
			public:
				DefaultServerProtocol(){
					DefaultServerProtocolLog(pankey_Log_StartMethod, "Constructor",  "println", "");
					DefaultServerProtocolLog(pankey_Log_EndMethod, "Constructor",  "println", "");
				}
				virtual ~DefaultServerProtocol(){
					DefaultServerProtocolLog(pankey_Log_StartMethod, "Destructor",  "println", "");
					DefaultServerProtocolLog(pankey_Log_EndMethod, "Destructor",  "println", "");
				}
				
				virtual obj<SerialPort> accept(obj<SerialServer> a_server){
					DefaultServerProtocolLog(pankey_Log_StartMethod, "getUpdateSerialPort",  "println", "");
					if(a_server.isNull()){
						DefaultServerProtocolLog(pankey_Log_EndMethod, "getUpdateSerialPort",  "println", "a_server.isNull()");
  						pankey_Log_Stop("DefaultServerProtocol accept");
						return nullptr;
					}
					obj<SerialPort> i_port = a_server->accept();
					DefaultServerProtocolLog(pankey_Log_EndMethod, "getUpdateSerialPort",  "println", (!i_port.isNull()) ? i_port->getName() : "port is null");
					return i_port;
				}
				
				virtual bool isPortManaged(){
					DefaultServerProtocolLog(pankey_Log_StartMethod, "isPortManaged",  "println", "");
					DefaultServerProtocolLog(pankey_Log_EndMethod, "isPortManaged",  "println", "");
					return false;
				}
				
				virtual obj<PortProtocol> createPortProtocol(){
					DefaultServerProtocolLog(pankey_Log_StartMethod, "createPortProtocol",  "println", "");
					obj<PortProtocol> i_protocol = T();
					SerialStateLog(pankey_Log_Statement, "addSerialPort",  "println", "is protocol null:");
					SerialStateLog(pankey_Log_Statement, "addSerialPort",  "println", i_protocol.isNull());
					DefaultServerProtocolLog(pankey_Log_EndMethod, "createPortProtocol",  "println", "");
					return i_protocol;
				}
				
			protected:
		};

	}

#endif