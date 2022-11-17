
#ifndef EthernetSerialServer_hpp
#define EthernetSerialServer_hpp
#define EthernetSerialServer_AVAILABLE

#include "ame_Enviroment.hpp"
#include "cppObject.hpp"
#include "SerialState.hpp"

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "IPAddress.h"
	#include "Ethernet.h"
	#include "EthernetServer.h"
	#include "EthernetClient.h"
#endif

#include "EthernetSerialPort.hpp"

#ifdef EthernetSerialServer_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define EthernetSerialServerLog(location,method,type,mns) ame_Log(this,location,"EthernetSerialServer",method,type,mns)
	#define const_EthernetSerialServerLog(location,method,type,mns) 
#else
	#ifdef EthernetSerialServer_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define EthernetSerialServerLog(location,method,type,mns) ame_LogDebug(this,location,"EthernetSerialServer",method,type)
		#define const_EthernetSerialServerLog(location,method,type,mns) 
	#else
		#define EthernetSerialServerLog(location,method,type,mns) 
		#define const_EthernetSerialServerLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

class EthernetSerialServer : public SerialServer{	
    public:
		EthernetSerialServer():server(80){
			EthernetSerialServerLog(ame_Log_Statement, "Contructor",  "println", "server(80)");
		}
		
		EthernetSerialServer(int port):server(port){
			EthernetSerialServerLog(ame_Log_Statement, "Contructor",  "println", Note("server: ") + Note(port));
		}
		
		virtual ~EthernetSerialServer(){
			EthernetSerialServerLog(ame_Log_Statement, "Destructor",  "println", "");
		}
		
		SerialPort* accept(){
			EthernetSerialServerLog(ame_Log_Statement, "accept",  "println", "");
			EthernetClient client = server.accept();   // Listen for incoming clients
			if(client){
				EthernetSerialServerLog(ame_Log_Statement, "accept",  "println", "if(client)");
				return new EthernetSerialPort(client,"ethernet");
			}
			return nullptr;
		} 
		
		SerialPort* available(){
			EthernetSerialServerLog(ame_Log_Statement, "available",  "println", "");
			EthernetClient client = server.available();   // Listen for incoming clients
			if(client){
				EthernetSerialServerLog(ame_Log_Statement, "available",  "println", "if(client)");
				return new EthernetSerialPort(client,"ethernet");
			}
			return nullptr;
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual bool equal(cppObject *b){
			EthernetSerialServerLog(ame_Log_Statement, "available",  "println", "equal");
			if(b == this){
				return true;
			}
			if(b->instanceof(Class<EthernetSerialServer>::classType)){
				EthernetSerialServer* c = (EthernetSerialServer*)b;
				if(c->server == this->server){
					return true;
				}
			}
			return false;
		}

		virtual cppObjectClass* getClass(){return Class<EthernetSerialServer>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			EthernetSerialServerLog(ame_Log_Statement, "instanceof",  "println", "");
			return cls == Class<EthernetSerialServer>::classType || SerialServer::instanceof(cls);
		}
		#endif

	protected:
		#ifdef ame_Windows

		#endif

		#ifdef ame_ArduinoIDE
			EthernetServer server;
		#endif
};

}

#endif