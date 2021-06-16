
#ifndef SerialPort_h
#define SerialPort_h

#include "Stream.h"
#include "cppObject.h"
#include "ByteArray.h"
#include "IPAddress.h"

class SerialPort : public Stream , public cppObject{	
    public:
		SerialPort(){
		}
		virtual ~SerialPort(){
		}
		
		virtual uint8_t status(){
			return 0;
		}
		virtual int available(){
			return 0;
		}
		virtual int read(){
			return -1;
		}
		virtual byte readByte(){
			return 255;
		}
		virtual String readString(){
			return "";
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
		virtual bool conect(IPAddress ip, int port){
			return false;
		}
		virtual void stop(){
		}
		virtual void send(String s){
		}
		virtual void send(ByteArray array){
		}
		
		virtual void setName(String name){
			m_name = name;
		}
		
		virtual String getName(){
			return m_name;
		}
		virtual void flush(){}
		virtual operator bool(){return false;}
		virtual void operator=(SerialPort b){}
		virtual bool operator==(SerialPort b){return this->getClass()==b.getClass();}
		virtual bool operator!=(SerialPort b){return this->getClass()!=b.getClass();}
		
		virtual cppObjectClass* getClass(){return Class<SerialPort>::classType;}
		virtual String toString(){return "SerialPort";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			//Serial.println("SerialPort instanceof");
			return cls == Class<SerialPort>::classType || cppObject::instanceof(cls);
		}
		
		virtual cppObject *clone(){return nullptr;}
		
	protected:
	String m_name = "";
};
#endif 
