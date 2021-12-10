
#ifndef EthernetSerialServer_hpp
#define EthernetSerialServer_hpp

#include "Ethernet.h"
#include "SerialPort.hpp"
#include "SerialServer.hpp"
#include "EthernetServer.h"
#include "IPAddress.h"
#include "EthernetClient.h"
#include "EthernetSerialPort.hpp"
#include "cppObject.hpp"
#include "cppObjectClass.hpp"

#ifdef EthernetSerialServerLogApp
	#include "Logger.hpp"
	#define EthernetSerialServerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define EthernetSerialServerLog(name,method,type,mns)
#endif

namespace ame{

class EthernetSerialServer : public SerialServer{	
    public:
    EthernetSerialServer():server(80){
		EthernetSerialServerLog("EthernetSerialServer", "Contructor",  "println", "server(80)");
    }
    EthernetSerialServer(IPAddress ip, IPAddress gateway, IPAddress subnet, int port):server(port){
		EthernetSerialServerLog("EthernetSerialServer", "Contructor",  "println", "server(80)");
		Ethernet.init(10);
		byte mac[] = {0xDE, 0xAD, 0xBE, 0xEF, 0xFE, 0xED};
		Ethernet.begin(mac, ip, gateway, subnet);
		server.begin();
    }
    EthernetSerialServer(IPAddress ip, IPAddress gateway, IPAddress subnet, int port, byte* mac):server(port){
		EthernetSerialServerLog("EthernetSerialServer", "Contructor",  "println", "server(80)");
		Ethernet.init(10);
		Ethernet.begin(mac, ip, gateway, subnet);
		server.begin();
    }
    EthernetSerialServer(int port):server(port){
		EthernetSerialServerLog("EthernetSerialServer", "Contructor",  "println", String("server: ") + String(port));
	}
	
	virtual ~EthernetSerialServer(){
		EthernetSerialServerLog("EthernetSerialServer", "Destructor",  "println", "");
	}
	
	SerialPort* accept(){
		EthernetSerialServerLog("EthernetSerialServer", "accept",  "println", "");
		EthernetClient client = server.accept();   // Listen for incoming clients
		if(client){
			EthernetSerialServerLog("EthernetSerialServer", "accept",  "println", "if(client)");
			return new EthernetSerialPort(client,"ethernet");
		}
		return nullptr;
	} 
	
	SerialPort* available(){
		EthernetSerialServerLog("EthernetSerialServer", "available",  "println", "");
		EthernetClient client = server.available();   // Listen for incoming clients
		if(client){
			EthernetSerialServerLog("EthernetSerialServer", "available",  "println", "if(client)");
			return new EthernetSerialPort(client,"ethernet");
		}
		return nullptr;
	}
	
	virtual cppObjectClass* getClass(){
		return Class<EthernetSerialServer>::classType;
	}
	virtual String toString(){return "EthernetSerialServer";}
	virtual bool equal(cppObject *b){
		EthernetSerialServerLog("EthernetSerialServer", "available",  "println", "equal");
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
		EthernetSerialServerLog("EthernetSerialServer", "instanceof",  "println", "");
		return cls == Class<EthernetSerialServer>::classType || SerialServer::instanceof(cls);
	}

protected:
	EthernetServer server;
};

}

#endif 
