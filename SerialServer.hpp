
#ifndef SerialServer_hpp
#define SerialServer_hpp

#include "cppObject.hpp"
#include "SerialPort.hpp"

#include "Note.hpp"

namespace higgs{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTATION_cppObject
*/
class SerialServer IMPLEMENTATION_cppObject{
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

		virtual void setName(Note name){m_name = name;}
		virtual Note getName(){return m_name;}

		virtual void setPort(Note a_port){m_port = a_port;}
		virtual Note getPort(){return m_port;}

		virtual void setTimeOut(float t){
			m_timeout = t;
		}

		virtual float getTimeOut(){
			return m_timeout;
		}

		virtual void on(Note txt, Method method){}

		virtual void send(int t, Note txt, Note a_message){}

		virtual void send(Note a_message){}

		virtual void send(Note a_port, Note a_message){}

#ifdef higgs_ArduinoIDE
		virtual void send(IPAddress a_port, Note a_message){}
#endif

		virtual void handleClient(){}

		virtual void operator=(SerialServer b){}
		virtual bool operator==(SerialServer b){return this->getName()==b.getName();}
		virtual bool operator!=(SerialServer b){return this->getName()!=b.getName();}

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<SerialServer>::getClass();}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialServer>::getClass();
		}
		virtual cppObject *clone(){return nullptr;}
		#endif

	protected:
		float m_timeout = -1.0;
		Note m_name = "";
		Note m_port = "";
};

}

#endif
