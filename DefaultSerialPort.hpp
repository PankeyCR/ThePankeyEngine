
#include "ame_Enviroment.hpp"

#if defined(DISABLE_DefaultSerialPort)
	#define DefaultSerialPort_hpp
#endif

#ifndef DefaultSerialPort_hpp
#define DefaultSerialPort_hpp
#define DefaultSerialPort_AVAILABLE

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
		
		virtual cppObjectClass* getClass(){return Class<DefaultSerialPort>::classType;}
		virtual Note toNote(){return Note("DefaultSerialPort");}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(b->instanceof(Class<DefaultSerialPort>::classType)){
				if(this->port == ((DefaultSerialPort*)b)->port){
					return true;
				}
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultSerialPort>::classType || SerialPort::instanceof(cls);
		}
		virtual cppObject *clone(){return nullptr;}
	protected:
		Stream* port = nullptr;
};

}

#endif