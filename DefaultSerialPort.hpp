
#ifndef DefaultSerialPort_hpp
#define DefaultSerialPort_hpp
#define DefaultSerialPort_AVAILABLE

#include "cppObject.hpp"

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialPort.hpp"
#include "Stream.h"

namespace ame{

class DefaultSerialPort : public SerialPort{	
    public:
		DefaultSerialPort(){}
		
		DefaultSerialPort(Stream* serial){
			port = serial;
		}
		DefaultSerialPort(Stream* serial, Note n){
			port = serial;
			this->m_name = n;
		}
		virtual ~DefaultSerialPort(){
		}
		virtual int available(){
			return port->available();
		}
		virtual int read(){
			return port->read();
		}
		virtual int peek(){
			return port->peek();
		}
		virtual size_t write(uint8_t chr){
			return port->write(chr);
		}
		virtual bool connected(){
			return true;
		}
		virtual operator bool(){return true;}
		virtual void operator=(DefaultSerialPort b){this->port = b.port;}
		virtual bool operator==(DefaultSerialPort b){return b.port == this->port;}
		virtual bool operator!=(DefaultSerialPort b){return b.port != this->port;}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<DefaultSerialPort>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultSerialPort>::getClass() || SerialPort::instanceof(cls);
		}
		#endif
	protected:
		Stream* port = nullptr;
};

}

#endif