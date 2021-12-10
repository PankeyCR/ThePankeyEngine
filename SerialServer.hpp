
#ifndef SerialServer_hpp
#define SerialServer_hpp

#include "cppObject.hpp"
#include "SerialPort.hpp"

namespace ame{

class SerialServer : public cppObject{	
    public:
		using Method = void(*)();
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
		
		virtual void setName(String name){
			m_name = name;
		}
		
		virtual String getName(){
			return m_name;
		}
		
		virtual void setTimeOut(float t){
			m_timeout = t;
		}
		
		virtual float getTimeOut(){
			return m_timeout;
		}
		
		virtual void on(String txt, Method method){}
		
		virtual void send(int t, String txt, String webpage){}
		
		virtual void handleClient(){}
		
		virtual void operator=(SerialServer b){}
		virtual bool operator==(SerialServer b){return this->getName()==b.getName();}
		virtual bool operator!=(SerialServer b){return this->getName()!=b.getName();}
		
		virtual cppObjectClass* getClass(){return Class<SerialServer>::classType;}
		virtual String toString(){return "SerialServer";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialServer>::classType || cppObject::instanceof(cls);
		}
		virtual cppObject *clone(){return nullptr;}
		
	protected:
	float m_timeout = -1.0;
	String m_name = "";
};

}

#endif 
