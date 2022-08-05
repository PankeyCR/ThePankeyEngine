
#include "ame_Enviroment.hpp"

#if defined(DISABLE_WebSerialServer)
	#define WebSerialServer_hpp
#endif

#ifndef WebSerialServer_hpp
#define WebSerialServer_hpp
#define WebSerialServer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

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

 namespace ame{

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
    WebSerialServer(Note ip, Note gateway, Note subnet, int port):server(port){
		WebSerialServerLog("WebSerialServer", "Contructor",  "println", "server(80)");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		if (!WiFi.config(ip.toIPAddress(), gateway.toIPAddress(), subnet.toIPAddress())) {
			WebSerialServerLog("WebSerialServer", "Contructor",  "println", "STA Failed to configure");
		}
		#elif defined(ARDUINO_ARCH_ESP8266)
		
		#endif 
		server.begin();
    }
    WebSerialServer(Note ip, Note gateway, Note subnet, int port, byte* mac):server(port){
		WebSerialServerLog("WebSerialServer", "Contructor",  "println", "server(80)");
		#if defined(ARDUINO_ESP32_DEV) || defined(LILYGO_WATCH_2020_V1) || defined(LILYGO_WATCH_2020_V2) || defined(LILYGO_WATCH_2020_V3)
		if (!WiFi.config(ip.toIPAddress(), gateway.toIPAddress(), subnet.toIPAddress())) {
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
		
	virtual void on(Note txt, Method method){
		server.on(txt, method);
	}
	
	virtual void send(int t, Note txt, Note webpage){
		server.on(t, txt, webpage);
	}
		
	virtual void handleClient(){
		server.handleClient();
	}
	
	virtual cppObjectClass* getClass(){return Class<WebSerialServer>::classType;}
	virtual Note toNote(){return "WebSerialServer";}
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

}

#endif 

#endif 
