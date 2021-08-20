
#ifndef WIFISerialServer_h
#define WIFISerialServer_h

#include "SerialPort.h"
#include "SerialServer.h"
#include "IPAddress.h"
#include "WIFISerialPort.h"

#ifdef WIFISerialServerLogApp
	#include "Logger.h"
	#define WIFISerialServerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define WIFISerialServerLog(name,method,type,mns)
#endif

using namespace ame;

class WIFISerialServer : public SerialServer{	
    public:
    WIFISerialServer():server(80){
		WIFISerialServerLog("WIFISerialServer", "Contructor",  "println", "server(80)");
		server.begin();
    }
    WIFISerialServer(int port):server(port){
		WIFISerialServerLog("WIFISerialServer", "Contructor",  "println", "server(port)");
		server.begin();
    }
    WIFISerialServer(IPAddress ip, IPAddress gateway, IPAddress subnet, int port):server(port){
		WIFISerialServerLog("WIFISerialServer", "Contructor",  "println", "server(80)");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		if (!WiFi.config(ip, gateway, subnet)) {
			WIFISerialServerLog("WIFISerialServer", "Contructor",  "println", "STA Failed to configure");
		}
		#elif defined(ARDUINO_ARCH_ESP8266)
		
		#endif 
		server.begin();
    }
    WIFISerialServer(IPAddress ip, IPAddress gateway, IPAddress subnet, int port, byte* mac):server(port){
		WIFISerialServerLog("WIFISerialServer", "Contructor",  "println", "server(80)");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		if (!WiFi.config(ip, gateway, subnet)) {
			WIFISerialServerLog("WIFISerialServer", "Contructor",  "println", "STA Failed to configure");
		}
		#elif defined(ARDUINO_ARCH_ESP8266)
		
		#endif 
		server.begin();
    }
	
	virtual ~WIFISerialServer(){
		WIFISerialServerLog("WIFISerialServer", "Destructor",  "println", "");
	}
	
	SerialPort* accept(){
		// WIFISerialServerLog("WIFISerialServer", "accept",  "println", "");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		WiFiClient client = server.accept();   // Listen for incoming clients
		#elif defined(ARDUINO_ARCH_ESP8266)
		WiFiClient client = server.available();
		#endif 
		if(client){
			WIFISerialServerLog("WIFISerialServer", "accept",  "println", "if(client)");
			return new WIFISerialPort(client,"ethernet");
		}
		return nullptr;
	} 
	
	SerialPort* available(){
		// WIFISerialServerLog("WIFISerialServer", "available",  "println", "");
		WiFiClient client = server.available();   // Listen for incoming clients
		if(client){
			WIFISerialServerLog("WIFISerialServer", "available",  "println", "if(client)");
			return new WIFISerialPort(client,"ethernet");
		}
		return nullptr;
	}
	
	virtual cppObjectClass* getClass(){return Class<WIFISerialServer>::classType;}
	virtual String toString(){return "WIFISerialServer";}
	virtual bool equal(cppObject *b){
		WIFISerialServerLog("WIFISerialServer", "available",  "println", "equal");
		if(b == this){
			return true;
		}
		if(b->instanceof<WIFISerialServer>()){
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
#endif 
