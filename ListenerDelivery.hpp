
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ListenerDelivery)
	#define ListenerDelivery_hpp
#endif

#ifndef ListenerDelivery_hpp
#define ListenerDelivery_hpp
#define ListenerDelivery_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MessageDelivery.hpp"
#include "SerialPort.hpp"
#include "SerialPost.hpp"

#ifdef ListenerDelivery_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define ListenerDeliveryLog(location,method,type,mns) ame_Log(this,location,"ListenerDelivery",method,type,mns)
	#define const_ListenerDeliveryLog(location,method,type,mns) 
	#define StaticListenerDeliveryLog(pointer,location,method,type,mns) ame_Log(pointer,location,"ListenerDelivery",method,type,mns)
#else
	#ifdef ListenerDelivery_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define ListenerDeliveryLog(location,method,type,mns) ame_LogDebug(this,location,"ListenerDelivery",method,type)
		#define const_ListenerDeliveryLog(location,method,type,mns) 
		#define StaticListenerDeliveryLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"ListenerDelivery",method,type)
	#else
		#define ListenerDeliveryLog(location,method,type,mns) 
		#define const_ListenerDeliveryLog(location,method,type,mns) 
		#define StaticListenerDeliveryLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class ListenerDelivery : public MessageDelivery{	
    public:
		ListenerDelivery(){}
		
		ListenerDelivery(Note a_name){
			m_name = a_name;
		}
		virtual ~ListenerDelivery(){}
		
		virtual void initialize(SerialNetwork* a_network){
			if(a_network == nullptr){
				return;
			}
			Application* app = a_network->getApplication();
			if(app == nullptr){
				return;
			}
			if(app->getStateManager() == nullptr){
				return;
			}
			if(m_name.isEmpty()){
				serialListener_N = app->getStateManager()->getState<SerialListenerState<Note>>();
				serialListener_BA = app->getStateManager()->getState<SerialListenerState<ByteArray>>();
			}else{
				serialListener_N = app->getStateManager()->getState<SerialListenerState<Note>>(m_name);
				serialListener_BA = app->getStateManager()->getState<SerialListenerState<ByteArray>>(m_name);
			}
		}
		
		virtual bool DeliverMessage(Note* a_mns){
			ListenerDeliveryLog(ame_Log_Statement, "DeliverMessage",  "println", "");
			if(serialListener_N == nullptr){
				ListenerDeliveryLog(ame_Log_Statement, "DeliverMessage",  "println", "serialListener_N == nullptr");
				return false;
			}
			serialListener_N->addMail(a_mns);
			return true;
		}
		
		virtual bool DeliverMessage(ByteArray* a_mns){
			ListenerDeliveryLog(ame_Log_Statement, "DeliverMessage",  "println", "");
			if(serialListener_BA == nullptr){
				ListenerDeliveryLog(ame_Log_Statement, "DeliverMessage",  "println", "serialListener_BA == nullptr");
				return false;
			}
			serialListener_BA->addMail(a_mns);
			return false;
		}
	protected:
		Note m_name;
		SerialListenerState<Note>* serialListener_N = nullptr;
		SerialListenerState<ByteArray>* serialListener_BA = nullptr;
};

}

#endif