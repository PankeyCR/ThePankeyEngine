
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
		bool available(){
			return port->available();
		}
		char read(){
			return port->read();
		}
		bool connected(){
			return true;
		}
		void print(String mns){
			port->print(mns);
		}
		void println(String mns){
			port->println(mns);
		}
		bool operator==(DefaultSerialPort b){return b.port == this->port;}
		bool operator!=(DefaultSerialPort b){return b.port != this->port;}
	protected:
		Stream* port = nullptr;
};
#endif 
