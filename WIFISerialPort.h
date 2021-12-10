
#ifndef WIFISerialPort_h
#define WIFISerialPort_h

#include "SerialPort.h"
#include "cppObject.h"
#include "IPAddress.h"
#include "SerialMessageState.h"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef WIFISerialPortLogApp
	#include "Logger.h"
	#define WIFISerialPortLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define WIFISerialPortLog(name,method,type,mns)
#endif

using namespace ame;

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

	virtual String getClassName(){
		WIFISerialPortLog("WIFISerialPort", "getClassName",  "println", "");
		return "WIFISerialPort";
	}
	virtual String toString(){return "WIFISerialPort";}
	virtual bool equal(cppObject *b){
		WIFISerialPortLog("WIFISerialPort", "equal",  "println", "");
		if(b == this){
			return true;
		}
		if(b->instanceof<WIFISerialPort>()){
			WIFISerialPort* c = (WIFISerialPort*)b;
			if(c->client == this->client){
				return true;
			}
		}
		return false;
	}

	virtual bool instanceof(String name){
		WIFISerialPortLog("WIFISerialPort", "instanceof",  "println", name);
		return name == "WIFISerialPort";
	}

	protected:
		WiFiClient client;
};
#endif 
