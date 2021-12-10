
#ifndef EthernetSerialPort_hpp
#define EthernetSerialPort_hpp

#include "Ethernet.h"
#include "SerialPort.hpp"
#include "EthernetServer.hpp"
#include "IPAddress.h"
#include "SerialMessageState.hpp"
#include "EthernetClient.h"
#include "cppObject.hpp"
#include "cppObjectClass.hpp"

#ifdef EthernetSerialPortLogApp
	#include "Logger.hpp"
	#define EthernetSerialPortLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define EthernetSerialPortLog(name,method,type,mns)
#endif

namespace ame{

class EthernetSerialPort : public SerialPort{	
    public:
	EthernetSerialPort(){
		EthernetSerialPortLog("EthernetSerialPort", "Contructor",  "println", "");
	}
	EthernetSerialPort(EthernetClient c){
		client = c;
		this->m_name = "eclient";
		EthernetSerialPortLog("EthernetSerialPort", "Contructor",  "println", "eclient");
	}
	EthernetSerialPort(String name){
		this->m_name = name;
		EthernetSerialPortLog("EthernetSerialPort", "Contructor",  "println", name);
	}
	EthernetSerialPort(EthernetClient c,String name){
		client = c;
		this->m_name = name;
		EthernetSerialPortLog("EthernetSerialPort", "Contructor",  "println", name);
	}

	virtual ~EthernetSerialPort(){
		EthernetSerialPortLog("EthernetSerialPort", "Destructor",  "println", "");
	}
	uint8_t status(){
		EthernetSerialPortLog("EthernetSerialPort", "status",  "println", "");
		return client.status();
	}
	int available(){
		EthernetSerialPortLog("EthernetSerialPort", "available",  "println", "");
		return client.available();
	}
	int read(){
		EthernetSerialPortLog("EthernetSerialPort", "read",  "println", "");
		return client.read();
	}
	virtual int peek(){
		EthernetSerialPortLog("EthernetSerialPort", "peek",  "println", "");
		return client.peek();
	}
	virtual size_t write(uint8_t chr){
		EthernetSerialPortLog("EthernetSerialPort", "write",  "println", String(chr));
		return client.write(chr);
	}
	virtual bool connected(){
		EthernetSerialPortLog("EthernetSerialPort", "connected",  "println", "");
		return client.connected();
	}
	virtual bool conect(IPAddress ip, int port){
		EthernetSerialPortLog("EthernetSerialPort", "connected",  "println", "");
		return client.connect(ip, port);
	}
	virtual void stop(){
		EthernetSerialPortLog("EthernetSerialPort", "stop",  "println", "");
		client.stop();
	}

	virtual void flush(){
		EthernetSerialPortLog("EthernetSerialPort", "flush",  "println", "");
		client.flush();
	}
	virtual size_t println(String s){
		EthernetSerialPortLog("EthernetSerialPort", "println",  "println", "");
		return client.print(s);
	}

	virtual void operator=(EthernetClient c){client = c;}
	virtual bool operator==(EthernetSerialPort c){return client == c.client;}
	virtual bool operator!=(EthernetSerialPort c){return client != c.client;}
	virtual operator bool(){return client;}

	virtual cppObjectClass* getClass(){
		EthernetSerialPortLog("EthernetSerialPort", "getClass",  "println", "");
		return Class<EthernetSerialPort>::classType;
	}
	virtual String toString(){return "EthernetSerialPort";}
	virtual bool equal(cppObject *b){
		EthernetSerialPortLog("EthernetSerialPort", "equal",  "println", "");
		if(b == this){
			return true;
		}
		if(b->instanceof(Class<EthernetSerialPort>::classType)){
			EthernetSerialPort* c = (EthernetSerialPort*)b;
			if(c->client == this->client){
				return true;
			}
		}
		return false;
	}

	virtual bool instanceof(cppObjectClass* cls){
		EthernetSerialPortLog("EthernetSerialPort", "instanceof",  "println", name);
		return cls == Class<EthernetSerialPort>::classType || SerialPort::instanceof(cls);
	}

	protected:
		EthernetClient client;
};

}

#endif 
