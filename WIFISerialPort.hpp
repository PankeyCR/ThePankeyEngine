
#include "ame_Enviroment.hpp"

#if defined(DISABLE_WIFISerialPort)
	#define WIFISerialPort_hpp
#endif

#ifndef WIFISerialPort_hpp
#define WIFISerialPort_hpp
#define WIFISerialPort_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
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

#ifdef WIFISerialPortLogApp
	#include "Logger.hpp"
	#define WIFISerialPortLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define WIFISerialPortLog(name,method,type,mns)
#endif

namespace ame{

class WIFISerialPort : public SerialPort{	
    public:
	WIFISerialPort(){
		WIFISerialPortLog("WIFISerialPort", "Contructor",  "println", "");
	}
	WIFISerialPort(WiFiClient c){
		client = c;
		this->m_name = "eclient";
		WIFISerialPortLog("WIFISerialPort", "Contructor",  "println", "eclient");
	}
	WIFISerialPort(String name){
		this->m_name = name;
		WIFISerialPortLog("WIFISerialPort", "Contructor",  "println", name);
	}
	WIFISerialPort(WiFiClient c,String name){
		client = c;
		this->m_name = name;
		WIFISerialPortLog("WIFISerialPort", "Contructor",  "println", name);
	}

	virtual ~WIFISerialPort(){
		WIFISerialPortLog("WIFISerialPort", "Destructor",  "println", "");
		if(connected()){
			stop();
		}
	}
	uint8_t status(){
		WIFISerialPortLog("WIFISerialPort", "status",  "println", "");
		// return client.status();
		return 0;
	}
	int available(){
		WIFISerialPortLog("WIFISerialPort", "available",  "println", "");
		return client.available();
	}
	int read(){
		WIFISerialPortLog("WIFISerialPort", "read",  "println", "");
		return client.read();
	}
	virtual int peek(){
		WIFISerialPortLog("WIFISerialPort", "peek",  "println", "");
		return client.peek();
	}
	virtual size_t write(uint8_t chr){
		WIFISerialPortLog("WIFISerialPort", "write",  "println", String(chr));
		return client.write(chr);
	}
	virtual bool connected(){
		WIFISerialPortLog("WIFISerialPort", "connected",  "println", "");
		return client.connected();
	}
	
	virtual bool connect(const Note& a_address, int port){
		WIFISerialPortLog("WIFISerialPort", "connect",  "println", "");
		
		int n_1 = split(a_address, 0, '.').toInt();
		int n_2 = split(a_address, 1, '.').toInt();
		int n_3 = split(a_address, 2, '.').toInt();
		int n_4 = split(a_address, 3, '.').toInt();
		
		IPAddress ip = IPAddress(n_1, n_2, n_3, n_4);
		
		return client.connect(ip, port);
	}
	
	virtual bool connect(const Note& a_address){
		return connect(a_address,-1);
	}
	
	virtual bool connect(const char* a_address, int port){
		WIFISerialPortLog("WIFISerialPort", "connect",  "println", "");
		
		Note note = a_address;
		
		int n_1 = split(a_address, 0, '.').toInt();
		int n_2 = split(a_address, 1, '.').toInt();
		int n_3 = split(a_address, 2, '.').toInt();
		int n_4 = split(a_address, 3, '.').toInt();
		
		IPAddress ip = IPAddress(n_1, n_2, n_3, n_4);
		
		return client.connect(ip, port);
	}
	
	virtual bool connect(const char* a_address){
		return connect(a_address,-1);
	}
	virtual bool conect(IPAddress ip, int port){
		WIFISerialPortLog("WIFISerialPort", "connected",  "println", "");
		return client.connect(ip, port);
	}
	virtual void stop(){
		WIFISerialPortLog("WIFISerialPort", "stop",  "println", "");
		client.stop();
	}

	virtual void flush(){
		WIFISerialPortLog("WIFISerialPort", "flush",  "println", "");
		client.flush();
	}
	virtual size_t println(String s){
		WIFISerialPortLog("WIFISerialPort", "println",  "println", "");
		return client.print(s);
	}

	virtual void operator=(WiFiClient c){client = c;}
	virtual bool operator==(WIFISerialPort c){return client == c.client;}
	virtual bool operator!=(WIFISerialPort c){return client != c.client;}
	virtual operator bool(){return client;}

	virtual cppObjectClass* getClass(){
		WIFISerialPortLog("WIFISerialPort", "getClassName",  "println", "");
		return Class<WIFISerialPort>::classType;
	}
	virtual String toString(){return "WIFISerialPort";}
	virtual bool equal(cppObject *b){
		WIFISerialPortLog("WIFISerialPort", "equal",  "println", "");
		if(b == this){
			return true;
		}
		if(b->instanceof(Class<WIFISerialPort>::classType)){
			WIFISerialPort* c = (WIFISerialPort*)b;
			if(c->client == this->client){
				return true;
			}
		}
		return false;
	}

	virtual bool instanceof(cppObjectClass* cls){
		WIFISerialPortLog("WIFISerialPort", "instanceof",  "println", name);
		return cls == Class<WIFISerialPort>::classType || SerialPort::instanceof(cls);
	}

	protected:
		WiFiClient client;
};

}

#endif