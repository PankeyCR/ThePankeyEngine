
#include "ame_Enviroment.hpp"

#if defined(DISABLE_EthernetSerialServer)
	#define EthernetSerialServer_hpp
#endif

#ifndef EthernetSerialServer_hpp
#define EthernetSerialServer_hpp
#define EthernetSerialServer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Ethernet.h"
#include "SerialPort.hpp"
#include "SerialServer.hpp"
#include "EthernetServer.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "EthernetSerialPort.hpp"
#include "cppObject.hpp"
#include "cppObjectClass.hpp"

#ifdef EthernetSerialServer_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define EthernetSerialServerLog(location,method,type,mns) ame_Log(this,location,"EthernetSerialServer",method,type,mns)
	#define const_EthernetSerialServerLog(location,method,type,mns) 
	#define StaticEthernetSerialServerLog(pointer,location,method,type,mns) ame_Log(pointer,location,"EthernetSerialServer",method,type,mns)
#else
	#ifdef EthernetSerialServer_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define EthernetSerialServerLog(location,method,type,mns) ame_LogDebug(this,location,"EthernetSerialServer",method,type)
		#define const_EthernetSerialServerLog(location,method,type,mns) 
		#define StaticEthernetSerialServerLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"EthernetSerialServer",method,type)
	#else
		#define EthernetSerialServerLog(location,method,type,mns) 
		#define const_EthernetSerialServerLog(location,method,type,mns) 
		#define StaticEthernetSerialServerLog(pointer,location,method,type,mns) 
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
	
	virtual cppObjectClass* getClass(){
		return Class<EthernetSerialServer>::classType;
	}
	virtual Note toNote(){return "EthernetSerialServer";}
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

	virtual bool instanceof(cppObjectClass* cls){
		EthernetSerialServerLog(ame_Log_Statement, "instanceof",  "println", "");
		return cls == Class<EthernetSerialServer>::classType || SerialServer::instanceof(cls);
	}

protected:
	EthernetServer server;
};

}

#endif