
#ifndef DefaultSerialPort_h
#define DefaultSerialPort_h

#include "SerialPort.h"
#include "Stream.h"

class DefaultSerialPort : public SerialPort{	
    public:
		DefaultSerialPort(Stream* serial){
			port = serial;
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
	protected:
		Stream* port = nullptr;
};
#endif 
