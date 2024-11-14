
#ifndef DefaultSerialPort_hpp
	#define DefaultSerialPort_hpp

	#include "SerialPort.hpp"
	#include "Stream.h"

	namespace pankey{

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
				DefaultSerialPort(const DefaultSerialPort& a_port){
					port = a_port.port;
					this->m_name = a_port.m_name;
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
				virtual void operator=(const DefaultSerialPort& a_port){
					port = a_port.port;
					this->m_name = a_port.m_name;
				}
				virtual bool operator==(DefaultSerialPort b){return b.port == this->port;}
				virtual bool operator!=(DefaultSerialPort b){return b.port != this->port;}
			protected:
				Stream* port = nullptr;
		};

	}

#endif