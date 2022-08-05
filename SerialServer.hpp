
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialServer)
	#define SerialServer_hpp
#endif

#ifndef SerialServer_hpp
#define SerialServer_hpp
#define SerialServer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "SerialPort.hpp"
#include "IPAddress.h"

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
		
		virtual void setName(Note name){
			m_name = name;
		}
		
		virtual Note getName(){
			return m_name;
		}
		
		virtual void setTimeOut(float t){
			m_timeout = t;
		}
		
		virtual float getTimeOut(){
			return m_timeout;
		}
		
		virtual void on(Note txt, Method method){}
		
		virtual void send(int t, Note txt, Note webpage){}
		
		virtual void send(Note a_message){}
		
		virtual void send(Note a_port, Note a_message){}
		
		virtual void send(IPAddress a_port, Note a_message){}
		
		virtual void handleClient(){}
		
		virtual void operator=(SerialServer b){}
		virtual bool operator==(SerialServer b){return this->getName()==b.getName();}
		virtual bool operator!=(SerialServer b){return this->getName()!=b.getName();}
		
		virtual cppObjectClass* getClass(){return Class<SerialServer>::classType;}
		virtual Note toNote(){return "SerialServer";}
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
	Note m_name = "";
};

}

#endif