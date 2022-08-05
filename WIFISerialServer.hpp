
#include "ame_Enviroment.hpp"

#if defined(DISABLE_WIFISerialServer)
	#define WIFISerialServer_hpp
#endif

#ifndef WIFISerialServer_hpp
#define WIFISerialServer_hpp
#define WIFISerialServer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "IPAddress.h"
#endif

#include "SerialPort.hpp"
#include "SerialServer.hpp"
#include "WIFISerialPort.hpp"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef WIFISerialServer_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define WIFISerialServerLog(location,method,type,mns) ame_Log(this,location,"WIFISerialServer",method,type,mns)
	#define const_WIFISerialServerLog(location,method,type,mns) 
	#define StaticWIFISerialServerLog(pointer,location,method,type,mns) ame_Log(pointer,location,"WIFISerialServer",method,type,mns)
#else
	#ifdef WIFISerialServer_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define WIFISerialServerLog(location,method,type,mns) ame_LogDebug(this,location,"WIFISerialServer",method,type)
		#define const_WIFISerialServerLog(location,method,type,mns) 
		#define StaticWIFISerialServerLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"WIFISerialServer",method,type)
	#else
		#define WIFISerialServerLog(location,method,type,mns) 
		#define const_WIFISerialServerLog(location,method,type,mns) 
		#define StaticWIFISerialServerLog(pointer,location,method,type,mns) 
	#endif
#endif
namespace ame{

class WIFISerialServer : public SerialServer{	
    public:
    WIFISerialServer():server(80){
		WIFISerialServerLog(ame_Log_Statement, "Contructor",  "println", "server(80)");
		server.begin();
    }
    WIFISerialServer(int port):server(port){
		WIFISerialServerLog(ame_Log_Statement, "Contructor",  "println", "server(port)");
		server.begin();
    }
	
	virtual ~WIFISerialServer(){
		WIFISerialServerLog(ame_Log_Statement, "Destructor",  "println", "");
	}
	
	SerialPort* accept(){
		// WIFISerialServerLog(ame_Log_Statement, "accept",  "println", "");
		#if defined(ame_GENERIC_ESP32)
		WiFiClient client = server.accept();   // Listen for incoming clients
		#elif defined(ame_GENERIC_ESP8266)
		WiFiClient client = server.available();
		#endif 
		if(client){
			WIFISerialServerLog(ame_Log_Statement, "accept",  "println", "if(client)");
			return new WIFISerialPort(client,"ethernet");
		}
		return nullptr;
	} 
	
	SerialPort* available(){
		// WIFISerialServerLog(ame_Log_Statement, "available",  "println", "");
		WiFiClient client = server.available();   // Listen for incoming clients
		if(client){
			WIFISerialServerLog(ame_Log_Statement, "available",  "println", "if(client)");
			return new WIFISerialPort(client,"ethernet");
		}
		return nullptr;
	}
	
	virtual WiFiServer getServer(){
		return server;
	}
	
	virtual cppObjectClass* getClass(){return Class<WIFISerialServer>::classType;}
	virtual String toString(){return "WIFISerialServer";}
	virtual bool equal(cppObject *b){
		WIFISerialServerLog(ame_Log_Statement, "available",  "println", "equal");
		if(b == this){
			return true;
		}
		if(b->instanceof(Class<WIFISerialServer>::classType)){
			WIFISerialServer* c = (WIFISerialServer*)b;
			#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
			if(c->server == this->server){
				return true;
			}
			#elif defined(ARDUINO_ARCH_ESP8266)
			
			#endif
		}
		return false;
	}

	virtual bool instanceof(cppObjectClass* cls){
		return cls == Class<WIFISerialServer>::classType || SerialServer::instanceof(cls);
	}

protected:
	WiFiServer server;
};

}

#endif