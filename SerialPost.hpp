
#ifndef CONFIGURATION_SerialPost_hpp
#define CONFIGURATION_SerialPost_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_SerialPost)
		#define SerialPost_hpp

		#define IMPLEMENTATION_SerialPost
		#define IMPLEMENTING_SerialPost
	#else
		#if defined(DISABLE_IMPLEMENTATION_SerialPost)
			#define IMPLEMENTATION_SerialPost
			#define IMPLEMENTING_SerialPost
		#endif
	#endif
#endif

#ifndef SerialPost_hpp
#define SerialPost_hpp
#define SerialPost_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_SerialPost
	#define IMPLEMENTATION_SerialPost IMPLEMENTATION(public SerialPost)
	#define IMPLEMENTING_SerialPost IMPLEMENTING(public SerialPost)
#endif

#include "Application.hpp"
#include "PrimitiveList.hpp"
#include "SerialListenerState.hpp"
#include "SerialNetwork.hpp"
#include "BaseAppState.hpp"
#include "PortMail.hpp"
#include "Cast.hpp"
#include "Note.hpp"

#ifdef SerialPost_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define SerialPostLog(location,method,type,mns) ame_Log(this,location,"SerialPost",method,type,mns)
	#define const_SerialPostLog(location,method,type,mns) 
	#define StaticSerialPostLog(pointer,location,method,type,mns) ame_Log(pointer,location,"SerialPost",method,type,mns)
#else
	#ifdef SerialPost_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define SerialPostLog(location,method,type,mns) ame_LogDebug(this,location,"SerialPost",method,type)
		#define const_SerialPostLog(location,method,type,mns) 
		#define StaticSerialPostLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"SerialPost",method,type)
	#else
		#define SerialPostLog(location,method,type,mns) 
		#define const_SerialPostLog(location,method,type,mns) 
		#define StaticSerialPostLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTATION_BaseAppState
*/
class SerialPost IMPLEMENTATION_BaseAppState {
    public:
	
	template<class PT>
	using PostMethod = void (*)(PT*);
	
		SerialPost(){
			SerialPostLog(ame_Log_StartMethod, "Constructor", "println", "Default Constructor");
			SerialPostLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		virtual ~SerialPost(){
			SerialPostLog(ame_Log_StartMethod, "Destructor", "println", "");
			SerialPostLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<SerialPost>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialPost>::getClass() || AppState::instanceof(cls);
		}
		#endif
		
		virtual void initializeState(Application *app){
			SerialPostLog(ame_Log_StartMethod, "initializeState", "println", "");
			for(int x = 0; x < m_networks.getPosition(); x++){
				Note* f_name = m_networks.getKeyByPosition(x);
				SerialNetwork* f_network = m_networks.getValueByPosition(x);
				app->getStateManager()->add(*f_name, f_network);
			}
			for(int x = 0; x < m_delivery.getPosition(); x++){
				AppState* i_state = m_delivery.getByPosition(x);
				app->getStateManager()->add(i_state);
			}
			m_delivery.reset();
			SerialPostLog(ame_Log_EndMethod, "initializeState", "println", "");
		}
		
		virtual void updateState(float tpc){}
		
		template<class SN>
		SN* addNetwork(Note a_name, SN* a_network){
			SerialPostLog(ame_Log_StartMethod, "addNetwork", "println", "");
			m_networks.addPointer(a_name, a_network);
			if(hasInitialize()){
				SerialPostLog(ame_Log_Statement, "addNetwork", "println", "");
				this->getApplication()->getStateManager()->add(a_name, a_network);
			}
			SerialPostLog(ame_Log_EndMethod, "addNetwork", "println", "");
			return a_network;
		}
		
		virtual bool gotPortMail(Note a_name){
			bool* hasMail = m_portMail.getValueByLValue(a_name);
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
		void addDelivery(Note a_name, PostMethod<T> a_method){
			if(!hasInitialize()){
				m_delivery.addPointer(new SerialListenerState<T>(a_name, a_method));
				return;
			}
			if(this->getApplication() == nullptr){
				return;
			}
			cppObjectClass* i_class = Class<SerialListenerState<T>>::getClass();
			AppState* i_appstate = this->getApplication()->getStateManager()->get(a_name, i_class);
			SerialListenerState<T>* listenerState = nullptr;
			if(i_appstate == nullptr){
				listenerState = new SerialListenerState<T>(a_name);
				this->getApplication()->getStateManager()->add(listenerState);
			}else{
				listenerState = (SerialListenerState<T>*)i_appstate;
			}
			listenerState->addListener(a_method);
		}
		
		virtual void sendNetwork(Note a_network, Note a_message){
			SerialNetwork* i_network = m_networks.getValueByLValue(a_network);
			if(i_network == nullptr){
				return;
			}
			i_network->send(a_message);
		}
		
		virtual void send(Note a_message){
			for(auto map : m_networks){
				SerialNetwork* i_network = map.getValuePointer();
				i_network->send(a_message);
			}
		}
	protected:
		PrimitiveMap<Note,bool> m_portMail;
		
		PrimitiveMap<Note,SerialNetwork> m_networks = false;
		PrimitiveList<AppState> m_delivery = false;
};

}

#endif