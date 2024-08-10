
#ifndef WIFISerialPort_hpp
#define WIFISerialPort_hpp
#define WIFISerialPort_AVAILABLE 

#include "cppObject.hpp"

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
	#include "IPAddress.h"
#endif

#include "SerialPort.hpp"
#include "cppObject.hpp"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef WIFISerialPort_LogApp
	#include "higgs_Logger_config.hpp"
	#include "higgs_Logger.hpp"
	
	#define WIFISerialPortLog(location,method,type,mns) higgs_Log(this,location,"WIFISerialPort",method,type,mns)
#else
	#ifdef WIFISerialPort_LogDebugApp
		#include "higgs_Logger_config.hpp"
		#include "higgs_Logger.hpp"
		
		#define WIFISerialPortLog(location,method,type,mns) higgs_LogDebug(this,location,"WIFISerialPort",method,type)
	#else
		#define WIFISerialPortLog(location,method,type,mns) 
	#endif
#endif

namespace higgs{

class WIFISerialPort : public SerialPort{	
    public:
	WIFISerialPort(){
		WIFISerialPortLog(higgs_Log_StartMethod, "Contructor",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "Contructor",  "println", "");
	}
	WIFISerialPort(WiFiClient c){
		WIFISerialPortLog(higgs_Log_StartMethod, "Contructor",  "println", "");
		client = c;
		this->m_name = "eclient";
		WIFISerialPortLog(higgs_Log_EndMethod, "Contructor",  "println", "eclient");
	}
	WIFISerialPort(String name){
		WIFISerialPortLog(higgs_Log_StartMethod, "Contructor",  "println", "");
		this->m_name = name;
		WIFISerialPortLog(higgs_Log_Statement, "Contructor",  "println", "");
		WIFISerialPortLog(higgs_Log_Statement, "Contructor",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "Contructor",  "println", name);
	}
	WIFISerialPort(WiFiClient c,String name){
		WIFISerialPortLog(higgs_Log_StartMethod, "Contructor",  "println", "");
		client = c;
		this->m_name = name;
		WIFISerialPortLog(higgs_Log_EndMethod, "Contructor",  "println", name);
	}

	virtual ~WIFISerialPort(){
		WIFISerialPortLog(higgs_Log_StartMethod, "Destructor",  "println", "");
		if(connected()){
			stop();
		}
		WIFISerialPortLog(higgs_Log_EndMethod, "Destructor",  "println", "");
	}
	uint8_t status(){
		WIFISerialPortLog(higgs_Log_StartMethod, "status",  "println", "");
		// return client.status();
		WIFISerialPortLog(higgs_Log_EndMethod, "status",  "println", "");
		return 0;
	}
	int available(){
		WIFISerialPortLog(higgs_Log_StartMethod, "available",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "available",  "println", "");
		return client.available();
	}
	int read(){
		WIFISerialPortLog(higgs_Log_StartMethod, "read",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "read",  "println", "");
		return client.read();
	}
	virtual int peek(){
		WIFISerialPortLog(higgs_Log_StartMethod, "peek",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "peek",  "println", "");
		return client.peek();
	}
	virtual size_t write(uint8_t chr){
		WIFISerialPortLog(higgs_Log_StartMethod, "write",  "println", String(chr));
		WIFISerialPortLog(higgs_Log_EndMethod, "write",  "println", "");
		return client.write(chr);
	}
	virtual bool connected(){
		WIFISerialPortLog(higgs_Log_StartMethod, "connected",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "connected",  "println", "");
		return client.connected();
	}
	
	virtual bool connect(const Note& a_address, int port){
		WIFISerialPortLog(higgs_Log_StartMethod, "connect",  "println", "");
		
		IPAddress ip = toIPAddress(a_address);
		
		WIFISerialPortLog(higgs_Log_EndMethod, "connect",  "println", "");
		return client.connect(ip, port);
	}
	
	virtual bool connect(const Note& a_address){
		WIFISerialPortLog(higgs_Log_StartMethod, "connect",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "connect",  "println", "");
		return connect(a_address,-1);
	}
	
	virtual bool connect(const char* a_address, int port){
		WIFISerialPortLog(higgs_Log_StartMethod, "connect",  "println", "");
		
		Note note = a_address;
		
		IPAddress ip = toIPAddress(note);
		
		WIFISerialPortLog(higgs_Log_EndMethod, "connect",  "println", "");
		return client.connect(ip, port);
	}
	
	virtual bool connect(const char* a_address){
		WIFISerialPortLog(higgs_Log_StartMethod, "connect",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "connect",  "println", "");
		return connect(a_address,-1);
	}
	virtual bool connect(IPAddress ip, int port){
		WIFISerialPortLog(higgs_Log_StartMethod, "connect",  "println", "");
		WIFISerialPortLog(higgs_Log_EndMethod, "connected",  "println", "");
		return client.connect(ip, port);
	}
	virtual void stop(){
		WIFISerialPortLog(higgs_Log_StartMethod, "stop",  "println", "");
		client.stop();
		WIFISerialPortLog(higgs_Log_EndMethod, "stop",  "println", "");
	}

	virtual void flush(){
		WIFISerialPortLog(higgs_Log_StartMethod, "flush",  "println", "");
		client.flush();
		WIFISerialPortLog(higgs_Log_EndMethod, "flush",  "println", "");
	}

	virtual void operator=(WiFiClient c){client = c;}
	virtual bool operator==(WIFISerialPort c){return client == c.client;}
	virtual bool operator!=(WIFISerialPort c){return client != c.client;}
	virtual operator bool(){return client;}

	#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
	virtual cppObjectClass* getClass(){
		WIFISerialPortLog(higgs_Log_StartMethod, "getClassName",  "println", "");
		return Class<WIFISerialPort>::getClass();
	}
	virtual String toString(){return "WIFISerialPort";}
	virtual bool equal(cppObject *b){
		WIFISerialPortLog(higgs_Log_StartMethod, "equal",  "println", "");
		if(b == this){
			return true;
		}
		if(b->instanceof(Class<WIFISerialPort>::getClass())){
			WIFISerialPort* c = (WIFISerialPort*)b;
			if(c->client == this->client){
				return true;
			}
		}
		return false;
	}

	virtual bool instanceof(cppObjectClass* cls){
		WIFISerialPortLog(higgs_Log_StartMethod, "instanceof",  "println", name);
		return cls == Class<WIFISerialPort>::getClass() || SerialPort::instanceof(cls);
	}
	#endif

	protected:
		WiFiClient client;
};

}

#endif