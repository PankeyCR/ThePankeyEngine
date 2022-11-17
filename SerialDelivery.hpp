
#ifndef CONFIGURATION_RadioNetwork_hpp
#define CONFIGURATION_RadioNetwork_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_RadioNetwork)
		#define RadioNetwork_hpp

		#define IMPLEMENTATION_RadioNetwork
		#define IMPLEMENTING_RadioNetwork
	#else
		#if defined(DISABLE_IMPLEMENTATION_RadioNetwork)
			#define IMPLEMENTATION_RadioNetwork
			#define IMPLEMENTING_RadioNetwork
		#endif
	#endif
#endif

#ifndef SerialDelivery_hpp
#define SerialDelivery_hpp
#define SerialDelivery_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_RadioNetwork
	#define IMPLEMENTATION_RadioNetwork IMPLEMENTATION(public RadioNetwork)
	#define IMPLEMENTING_RadioNetwork IMPLEMENTING(public RadioNetwork)
#endif

#include "MessageDelivery.hpp"
#include "SerialListenerState.hpp"
#include "Class.hpp"

#ifdef SerialDelivery_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define SerialDeliveryLog(location,method,type,mns) ame_Log(this,location,"SerialDelivery",method,type,mns)
#else
	#ifdef SerialDelivery_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define SerialDeliveryLog(location,method,type,mns) ame_LogDebug(this,location,"SerialDelivery",method,type)
	#else
		#define SerialDeliveryLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

class SerialDelivery : public MessageDelivery{	
    public:	
		SerialDelivery(){
			SerialDeliveryLog(ame_Log_StartMethod, "Constructor", "println", "Default Constructor");
			SerialDeliveryLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		SerialDelivery(SerialListenerState<Note>* c_note_listener_state){
			SerialDeliveryLog(ame_Log_StartMethod, "Constructor", "println", "");
			this->m_listener_note_state = c_note_listener_state;
			SerialDeliveryLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~SerialDelivery(){
			SerialDeliveryLog(ame_Log_StartMethod, "Destructor", "println", "Default Constructor");
			SerialDeliveryLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE) && defined(SerialNetwork_AVAILABLE)
		virtual void initialize(SerialNetwork* state){
			SerialDeliveryLog(ame_Log_StartMethod, "initialize", "println", "Default Constructor");
			if(this->serialState == nullptr){
				SerialDeliveryLog(ame_Log_EndMethod, "initialize", "println", "");
				return;
			}
			this->serialState = state;
			if(this->m_listener_note_state == nullptr){
				this->m_listener_note_state = this->serialState->getApplication()->getStateManager()->getState<SerialListenerState<Note>>();
			}
			if(this->m_listener_byte_state == nullptr){
				this->m_listener_byte_state = this->serialState->getApplication()->getStateManager()->getState<SerialListenerState<ByteArray>>();
			}
			SerialDeliveryLog(ame_Log_EndMethod, "initialize", "println", "");
		}
		#endif
		
		virtual bool DeliverMessage(Note* a_mns){
			SerialDeliveryLog(ame_Log_StartMethod, "DeliverMessage", "println", "");
			#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
			if(this->m_listener_note_state == nullptr && this->serialState != nullptr){
				SerialDeliveryLog(ame_Log_Statement, "DeliverMessage", "println", "this->m_listener_note_state == nullptr && this->serialState != nullptr");
				this->m_listener_note_state = this->serialState->getApplication()->getStateManager()->getState<SerialListenerState<Note>>();
			}
			#endif
			if(this->m_listener_note_state == nullptr){
				SerialDeliveryLog(ame_Log_Statement, "DeliverMessage", "println", "this->m_listener_note_state == nullptr");
				if(a_mns != nullptr){
					delete a_mns;
				}
				SerialDeliveryLog(ame_Log_EndMethod, "DeliverMessage", "println", "return false");
				return false;
			}
			this->m_listener_note_state->addMail(a_mns);
			SerialDeliveryLog(ame_Log_EndMethod, "DeliverMessage", "println", "return true");
			return true;
		}
		virtual bool DeliverMessage(ByteArray* a_mns){
			SerialDeliveryLog(ame_Log_StartMethod, "DeliverMessage", "println", "Default Constructor");
			SerialDeliveryLog(ame_Log_EndMethod, "DeliverMessage", "println", "");
			return false;
		}
		
		virtual bool StreamDeliverMessage(char a_mns){
			SerialDeliveryLog(ame_Log_StartMethod, "StreamDeliverMessage", "println", "Default Constructor");
			SerialDeliveryLog(ame_Log_EndMethod, "StreamDeliverMessage", "println", "");
			return false;
		}
		virtual bool StreamDeliverMessage(ame_Byte a_mns){
			SerialDeliveryLog(ame_Log_StartMethod, "StreamDeliverMessage", "println", "Default Constructor");
			SerialDeliveryLog(ame_Log_EndMethod, "StreamDeliverMessage", "println", "");
			return false;
		}
			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<SerialDelivery>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialDelivery>::getClass() || MessageDelivery::instanceof(cls);
		}
		#endif
		
	protected:
		SerialListenerState<Note>* m_listener_note_state = nullptr;
		SerialListenerState<ByteArray>* m_listener_byte_state = nullptr;
};

}

#endif