
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialPost)
	#define SerialPost_hpp
#endif

#ifndef SerialPost_hpp
#define SerialPost_hpp
#define SerialPost_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveList.hpp"
#include "Application.hpp"
#include "PortMail.hpp"
#include "AppState.hpp"
#include "SerialListenerState.hpp"

#ifdef SerialPostLogApp
	#include "Logger.hpp"
	#define SerialPostLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialPostLog(name,method,type,mns)
#endif

namespace ame{
	
template<class T>
using PostMethod = void (*)(T*);

class SerialPost : public AppState{
    public:
		SerialPost(){
			SerialPostLog("SerialPost", "Constructor",  "println", "");
		}
		virtual ~SerialPost(){
			SerialPostLog("SerialPost", "Destructor",  "println", "");
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialPost>::classType || AppState::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<SerialPost>::classType;}
		
		virtual Application* getApplication(){return this->application;}
		
		virtual void initialize(Application *app){
			this->application = app;
		}
		
		virtual void update(float tpc){}
		
		virtual bool gotPortMail(Note a_name){
			bool* hasMail = m_portMail.getByLValue(a_name);
			if(hasMail == nullptr){
				return false;
			}
			return *hasMail;
		}
		
		template<class T>
		void addPortMail(Note a_port_name, T a_mns){
			PortMail<T>::add(a_port_name, a_mns);
			m_portMail.put(a_port_name,true);
		}
		
		template<class T>
		T retrievePortMessage(Note a_port_name){
			m_portMail.put(a_port_name,false);
			return PortMail<T>::retrieveMessage(a_port_name);
		}
		
		template<class T>
		LinkedList<T> retrievePortMail(Note a_port_name){
			m_portMail.put(a_port_name,false);
			return PortMail<T>::retrieveMail(a_port_name);
		}
		
		template<class T>
		void addDelivery(Note a_server_name, PostMethod<T> a_method){
			if(this->application == nullptr){
				return;
			}
			AppState* i_appstate = this->application->getStateManager()->get(a_server_name, Class<SerialListenerState<T>>::classType);
			SerialListenerState<T>* listenerState = nullptr;
			if(i_appstate == nullptr){
				listenerState = new SerialListenerState<T>(a_server_name);
				this->application->getStateManager()->add(listenerState);
			}else{
				listenerState = (SerialListenerState<T>*)i_appstate;
			}
			listenerState->addListener(a_method);
		}
	protected:
		Application* application = nullptr;
		PrimitiveMap<Note,bool> m_portMail;
};

}

#endif