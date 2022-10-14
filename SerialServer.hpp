
#ifndef SerialServer_hpp
#define SerialServer_hpp
#define SerialServer_AVAILABLE

#include "cppObject.hpp"

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
    #include "IPAddress.h"
#endif

#include "Note.hpp"

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

#ifdef ame_ArduinoIDE
		virtual void send(IPAddress a_port, Note a_message){}
#endif

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
