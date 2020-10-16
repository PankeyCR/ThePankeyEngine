
#ifndef SerialPort_h
#define SerialPort_h

#include "Stream.h"

class SerialPort : public Stream{	
    public:
		SerialPort(){
		}
		virtual ~SerialPort(){
		}
		
		virtual int available(){
			return 0;
		}
		virtual int read(){
			return -1;
		}
		virtual int peek(){
			return -1;
		}
		virtual size_t write(uint8_t chr){
			return 0;
		}
		virtual bool connected(){
			return false;
		}
		virtual void stop(){
		}
		virtual void flush(){}
		virtual operator bool(){return false;}
		virtual void operator=(SerialPort b){}
		virtual bool operator==(SerialPort b){return true;}
		virtual bool operator!=(SerialPort b){return false;}
		
		
	protected:
};
#endif 
