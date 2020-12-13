
#ifndef DefaultSerialPort_h
#define DefaultSerialPort_h

#include "SerialPort.h"
#include "Stream.h"

class DefaultSerialPort : public SerialPort{	
    public:
		DefaultSerialPort(){
		}
		DefaultSerialPort(Stream* serial){
			port = serial;
		}
		DefaultSerialPort(Stream* serial, String n){
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
		
		virtual String getClassName(){return "DefaultSerialPort";}
		virtual String toString(){return "DefaultSerialPort";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			if(b->instanceof<DefaultSerialPort>()){
				if(this->port == ((DefaultSerialPort*)b)->port){
					return true;
				}
			}
			return false;
		}
		virtual bool instanceof(String name){return name == "DefaultSerialPort" || SerialPort::instanceof(name);}
		virtual cppObject *clone(){return nullptr;}
	protected:
		Stream* port = nullptr;
};
#endif 
