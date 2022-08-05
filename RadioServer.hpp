
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RadioServer)
	#define RadioServer_hpp
#endif

#ifndef RadioServer_hpp
#define RadioServer_hpp
#define RadioServer_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialServer.hpp"
#include "SerialPort.hpp"
#include "RadioType.hpp"
#include "RadioReliability.hpp"

namespace ame{

class RadioServer : public SerialServer{	
    public:
		using Method = void(*)();
		RadioServer(){
		}
		RadioServer(Note c_note){
		}
		virtual ~RadioServer(){
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
		
		virtual void handleClient(){}
		
		virtual void operator=(RadioServer b){}
		virtual bool operator==(RadioServer b){
			return this->getName()==b.getName();
		}
		virtual bool operator!=(RadioServer b){
			return this->getName()!=b.getName();
		}
		
		virtual cppObjectClass* getClass(){return Class<RadioServer>::classType;}
		virtual bool equal(SerialServer *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<RadioServer>::classType || SerialServer::instanceof(cls);
		}
		
	protected:
		
};

}

#endif