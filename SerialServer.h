
#ifndef SerialServer_h
#define SerialServer_h

#include "cppObject.h"
#include "SerialPort.h"
class SerialMessageState;

class SerialServer : public cppObject{	
    public:
		SerialServer(){
		}
		virtual ~SerialServer(){
		}
		
		virtual SerialPort* accept(){
			return nullptr;
		}
		
		virtual SerialPort* available(){
			return nullptr;
		}
		
		virtual void attach(SerialMessageState* state){
			serialState = state;
		}
		
		virtual void setName(String name){
			m_name = name;
		}
		
		virtual String getName(){
			return m_name;
		}
		virtual void operator=(SerialServer b){}
		virtual bool operator==(SerialServer b){return this->getName()==b.getName();}
		virtual bool operator!=(SerialServer b){return this->getName()!=b.getName();}
		
		virtual String getClassName(){return "SerialServer";}
		virtual String toString(){return "SerialServer";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(String name){return name == "SerialServer" || cppObject::instanceof(name);}
		virtual cppObject *clone(){return nullptr;}
		
	protected:
	String m_name = "";
	SerialMessageState* serialState = nullptr;
};
#endif 
