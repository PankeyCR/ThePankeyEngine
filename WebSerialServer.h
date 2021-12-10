
#ifndef WebSerialServer_h
#define WebSerialServer_h

#include "SerialPort.h"
#include "SerialServer.h"
#include "WebServer.h"
#include "IPAddress.h"
#include "WIFISerialPort.h"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef WebSerialServerLogApp
	#include "Logger.h"
	#define WebSerialServerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define WebSerialServerLog(name,method,type,mns)
#endif

using namespace ame;

class WebSerialServer : public SerialServer{	
    public:
    WebSerialServer():server(80){
		WebSerialServerLog("WebSerialServer", "Contructor",  "println", "server(80)");
		server.begin();
    }
    WebSerialServer(int port):server(port){
		WebSerialServerLog("WebSerialServer", "Contructor",  "println", "server(port)");
		server.begin();
    }
    WebSerialServer(IPAddress ip, IPAddress gateway, IPAddress subnet, int port):server(port){
		WebSerialServerLog("WebSerialServer", "Contructor",  "println", "server(80)");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		if (!WiFi.config(ip, gateway, subnet)) {
			WebSerialServerLog("WebSerialServer", "Contructor",  "println", "STA Failed to configure");
		}
		#elif defined(ARDUINO_ARCH_ESP8266)
		
		#endif 
		server.begin();
    }
    WebSerialServer(IPAddress ip, IPAddress gateway, IPAddress subnet, int port, byte* mac):server(port){
		WebSerialServerLog("WebSerialServer", "Contructor",  "println", "server(80)");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		if (!WiFi.config(ip, gateway, subnet)) {
			WebSerialServerLog("WebSerialServer", "Contructor",  "println", "STA Failed to configure");
		}
		#elif defined(ARDUINO_ARCH_ESP8266)
		
		#endif 
		server.begin();
    }
	
	virtual ~WebSerialServer(){
		WebSerialServerLog("WebSerialServer", "Destructor",  "println", "");
	}
	
	SerialPort* accept(){
		return nullptr;
	} 
	
	SerialPort* available(){
		return nullptr;
	}
		
	virtual void on(String txt, Method method){
		server.on(txt, method);
	}
	
	virtual void send(int t, String txt, String webpage){
		server.on(t, txt, webpage);
	}
		
	virtual void handleClient(){
		server.handleClient();
	}
	
	virtual cppObjectClass* getClass(){return Class<WebSerialServer>::classType;}
	virtual String toString(){return "WebSerialServer";}
	virtual bool equal(cppObject *b){
		WebSerialServerLog("WebSerialServer", "available",  "println", "equal");
		if(b == this){
			return true;
		}
		return false;
	}

	virtual bool instanceof(cppObjectClass* cls){
		return cls == Class<WebSerialServer>::classType || SerialServer::instanceof(cls);
	}

protected:
	WebServer server;
};
#endif 
