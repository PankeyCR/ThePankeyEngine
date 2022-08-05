
#include "ame_Enviroment.hpp"

#if defined(DISABLE_EthernetSerialPort)
	#define EthernetSerialPort_hpp
#endif

#ifndef EthernetSerialPort_hpp
#define EthernetSerialPort_hpp
#define EthernetSerialPort_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Ethernet.h"
#include "SerialPort.hpp"
#include "EthernetServer.h"
#include "IPAddress.h"
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
	EthernetSerialPort(Note name){
		this->m_name = name;
		EthernetSerialPortLog("EthernetSerialPort", "Contructor",  "println", name);
	}
	EthernetSerialPort(EthernetClient c,Note name){
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
		EthernetSerialPortLog("EthernetSerialPort", "write",  "println", Note(chr));
		return client.write(chr);
	}
	virtual bool connected(){
		EthernetSerialPortLog("EthernetSerialPort", "connected",  "println", "");
		return client.connected();
	}
	
	virtual bool connect(const Note& a_address, int port){
		EthernetSerialPortLog("EthernetSerialPort", "connect",  "println", "");
		
		IPAddress ip = toIPAddress(a_address);
		
		return client.connect(ip, port);
	}
	
	virtual bool connect(const Note& a_address){
		return connect(a_address,-1);
	}
	
	virtual bool connect(const char* a_address, int port){
		EthernetSerialPortLog("EthernetSerialPort", "connect",  "println", "");
		
		Note note = a_address;
		IPAddress ip = toIPAddress(note);
		
		return client.connect(ip, port);
	}
	
	virtual bool connect(const char* a_address){
		return connect(a_address,-1);
	}
	
	virtual bool connect(IPAddress ip, int port){
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
	virtual size_t println(Note s){
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
	virtual Note toNote(){return "EthernetSerialPort";}
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