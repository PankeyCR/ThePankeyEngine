
#ifndef EthernetSerialPort_hpp
#define EthernetSerialPort_hpp
#define EthernetSerialPort_AVAILABLE

#include "pankey_Enviroment.hpp"
#include "cppObject.hpp"
#include "SerialState.hpp"

#ifdef pankey_Windows

#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
	#include "IPAddress.h"
	#include "Ethernet.h"
	#include "EthernetServer.h"
	#include "EthernetClient.h"
#endif

#ifdef EthernetSerialPort_LogApp
	#include "pankey_Logger_config.hpp"
	#define EthernetSerialPortLog(location,method,type,mns) pankey_Log((void*)this,location,"EthernetSerialPort",method,type,mns)
#else
	#define EthernetSerialPortLog(location,method,type,mns)
#endif

namespace pankey{

class EthernetSerialPort : public SerialPort{	
    public:
	EthernetSerialPort(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "");
	}
	EthernetSerialPort(EthernetClient c){
		client = c;
		this->m_name = "eclient";
		EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", "eclient");
	}
	EthernetSerialPort(Note name){
		this->m_name = name;
		EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", name);
	}
	EthernetSerialPort(EthernetClient c,Note name){
		client = c;
		this->m_name = name;
		EthernetSerialPortLog(pankey_Log_StartMethod, "Contructor",  "println", name);
	}

	virtual ~EthernetSerialPort(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "Destructor",  "println", "");
	}
	uint8_t status(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "status",  "println", "");
		return client.status();
	}
	int available(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "available",  "println", "");
		return client.available();
	}
	int read(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "read",  "println", "");
		return client.read();
	}
	virtual int peek(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "peek",  "println", "");
		return client.peek();
	}
	virtual size_t write(uint8_t chr){
		EthernetSerialPortLog(pankey_Log_StartMethod, "write",  "println", Note(chr));
		return client.write(chr);
	}
	virtual bool connected(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "connected",  "println", "");
		return client.connected();
	}
	
	virtual bool connect(const Note& a_address, int port){
		EthernetSerialPortLog(pankey_Log_StartMethod, "connect",  "println", "");
		
		IPAddress ip = toIPAddress(a_address);
		
		return client.connect(ip, port);
	}
	
	virtual bool connect(const Note& a_address){
		return connect(a_address,-1);
	}
	
	virtual bool connect(const char* a_address, int port){
		EthernetSerialPortLog(pankey_Log_StartMethod, "connect",  "println", "");
		
		Note note = a_address;
		IPAddress ip = toIPAddress(note);
		
		return client.connect(ip, port);
	}
	
	virtual bool connect(const char* a_address){
		return connect(a_address,-1);
	}
	
	virtual bool connect(IPAddress ip, int port){
		EthernetSerialPortLog(pankey_Log_StartMethod, "connected",  "println", "");
		return client.connect(ip, port);
	}
	virtual void stop(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "stop",  "println", "");
		client.stop();
	}

	virtual void flush(){
		EthernetSerialPortLog(pankey_Log_StartMethod, "flush",  "println", "");
		client.flush();
	}
	virtual size_t println(Note s){
		EthernetSerialPortLog(pankey_Log_StartMethod, "println",  "println", "");
		return client.print(s);
	}

	virtual void operator=(EthernetClient c){client = c;}
	virtual bool operator==(EthernetSerialPort c){return client == c.client;}
	virtual bool operator!=(EthernetSerialPort c){return client != c.client;}
	virtual operator bool(){return client;}

	#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
	virtual bool equal(cppObject *b){
		EthernetSerialPortLog(pankey_Log_StartMethod, "equal",  "println", "");
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

	virtual cppObjectClass* getClass(){return Class<EthernetSerialPort>::getClass();}
	virtual bool instanceof(cppObjectClass* cls){
		EthernetSerialPortLog(pankey_Log_StartMethod, "instanceof",  "println", name);
		return cls == Class<EthernetSerialPort>::classType || SerialPort::instanceof(cls);
	}
	#endif

	protected:
		#ifdef pankey_Windows

		#endif

		#ifdef pankey_ArduinoIDE
			EthernetClient client;
		#endif
};

}

#endif