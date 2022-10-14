
#ifndef SerialPort_hpp
#define SerialPort_hpp
#define SerialPort_AVAILABLE

#include "cppObject.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Stream.h"
	#include "IPAddress.h"
#endif

namespace ame{

class SerialPort : public cppObject{

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
		virtual Note readNote(){
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
		virtual bool connect(const Note& a_address){
			return connect(a_address,-1);
		}
		virtual bool connect(const Note& a_address, int port){
			return false;
		}
		virtual bool connect(const char* a_address){
			return connect(a_address,-1);
		}
		virtual bool connect(const char* a_address, int port){
			return false;
		}
		#ifdef ame_Windows
		
		#endif
		#ifdef ame_ArduinoIDE
		virtual bool connect(IPAddress ip, int port){
			return false;
		}
		#endif
		virtual void stop(){
		}
		virtual void send(Note s){
		}
		virtual void send(ByteArray array){
		}
		
		virtual void setName(Note name){
			m_name = name;
		}
		
		virtual Note getName(){
			return m_name;
		}
		virtual void flush(){}
		virtual operator bool(){return false;}
		virtual void operator=(SerialPort b){}
		virtual bool operator==(SerialPort b){return this->getClass()==b.getClass();}
		virtual bool operator!=(SerialPort b){return this->getClass()!=b.getClass();}
		
		virtual cppObjectClass* getClass(){return Class<SerialPort>::classType;}
		virtual Note toNote(){return "SerialPort";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialPort>::classType || cppObject::instanceof(cls);
		}
		
		virtual cppObject *clone(){return nullptr;}
	protected:
		Note m_name;
};

}

#endif