
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialListenerState)
	#define SerialListenerState_hpp
#endif

#ifndef SerialListenerState_hpp
#define SerialListenerState_hpp
#define SerialListenerState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "Application.hpp"
#include "PrimitiveMap.hpp"
#include "PrimitiveList.hpp"
#include "SerialListener.hpp"

#ifdef SerialListenerState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	#include "MemoryRam.h"
	
	#define SerialListenerStateLog(location,method,type,mns) ame_Log(this,location,"SerialListenerState",method,type,mns)
	#define const_SerialListenerStateLog(location,method,type,mns) 
	#define StaticSerialListenerStateLog(pointer,location,method,type,mns) ame_Log(pointer,location,"SerialListenerState",method,type,mns)
#else
	#ifdef SerialListenerState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		#include "MemoryRam.h"
		
		#define SerialListenerStateLog(location,method,type,mns) ame_LogDebug(this,location,"SerialListenerState",method,type)
		#define const_SerialListenerStateLog(location,method,type,mns) 
		#define StaticSerialListenerStateLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"SerialListenerState",method,type)
	#else
		#define SerialListenerStateLog(location,method,type,mns) 
		#define const_SerialListenerStateLog(location,method,type,mns) 
		#define StaticSerialListenerStateLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

template<class T>
class SerialListenerState : public AppState{	
    public:
		using ListenerMethod = void (*)(T*);
		
		Application* app;
		
		SerialListenerState(){
			SerialListenerStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			
			receivedMessage = new PrimitiveList<T>();
			listener = new PrimitiveList<SerialListener<T>>();
			methodListener = new PrimitiveList<ListenerMethod>();
			
			SerialListenerStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		
		SerialListenerState(Note c_name){
			SerialListenerStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			
			receivedMessage = new PrimitiveList<T>();
			listener = new PrimitiveList<SerialListener<T>>();
			methodListener = new PrimitiveList<ListenerMethod>();
			
			this->setId(c_name);
			
			SerialListenerStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~SerialListenerState(){
			SerialListenerStateLog(ame_Log_StartMethod, "Destructor", "println", "");
			
			delete receivedMessage;
			delete listener;
			delete methodListener;
			
			SerialListenerStateLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void initialize(Application *app){
			SerialListenerStateLog(ame_Log_StartMethod, "initialize", "println", "");
			
			serialState = app->getStateManager()->getState<SerialState>();
			for(int x = 0; x < listener->getPosition(); x++){
				SerialListener<T>* mnsCmd = listener->getByPosition(x);
				mnsCmd->setSerialState(serialState);
			}
			init = true;
			
			SerialListenerStateLog(ame_Log_EndMethod, "initialize", "println", "");
		}
		
		SerialListener<T>* addListener(SerialListener<T>* mnsCmd){
			SerialListenerStateLog(ame_Log_Statement, "addListener",  "println", "");
			listener->addPointer(mnsCmd);
			if(init){
				mnsCmd->setSerialState(serialState);
			}
			return mnsCmd;
		}
		
		void addListener(ListenerMethod method){
			SerialListenerStateLog(ame_Log_Statement, "addListener",  "println", "");
			methodListener->add(method);
		}
		
		SerialListener<T>* getSerialListener(cppObjectClass* cls){
			SerialListenerStateLog(ame_Log_Statement, "getSerialListener",  "println", "");
			for(int x = 0; x < listener->getPosition(); x++){
				SerialListener<T>* serialListener = listener->getByPosition(x);
				if(serialListener->getClass() == cls){
					return serialListener;
				}
			}
			return nullptr;
		}

		void removeDeleteSerialListener(int index) {
			SerialListenerStateLog(ame_Log_Statement, "removeDeleteSerialListener",  "println", "");
			SerialListenerStateLog(ame_Log_Statement, "removeDeleteSerialListener",  "println", ame_String("index: ") + ame_String(index));
			listener->removeDeleteByPosition(index);
		}

		void removeAllListener() {
			SerialListenerStateLog(ame_Log_Statement, "removeAllListener",  "println", "");
			listener->resetDelete();
		}

		void removeAllSerialListener() {
			SerialListenerStateLog(ame_Log_Statement, "removeAllSerialListener",  "println", "");
			listener->resetDelete();
		}
		
		void addMail(T* m){
			receivedMessage->addPointer(m);
		}
		
		List<T>* getMail(){
			return receivedMessage;
		}
		
		virtual cppObjectClass* getClass(){
			return Class<SerialListenerState>::classType;
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialListenerState>::classType || AppState::instanceof(cls);
		}
		
		virtual void update(float tpc){
			if(receivedMessage->isEmpty()){
				return;
			}
			SerialListenerStateLog(ame_Log_StartMethod, "update",  "println", "");
			for(int x = 0; x < receivedMessage->getPosition(); x++){
				SerialListenerStateLog(ame_Log_Statement, "update",  "println", ame_String("receivedMessage index: ") + ame_String(x));
				for(int y = 0; y < methodListener->getPosition(); y++){
					SerialListenerStateLog(ame_Log_Statement, "update",  "println", ame_String("methodListener index: ") + ame_String(y));
					ListenerMethod  event = *methodListener->getByPosition(y);
					event(receivedMessage->getByPosition(x));
				}
				for(int y = 0; y < listener->getPosition(); y++){
					SerialListenerStateLog(ame_Log_Statement, "update",  "println", ame_String("listener index: ") + ame_String(y));
					listener->getByPosition(y)->execute(receivedMessage->getByPosition(x));
				}
			}
			SerialListenerStateLog(ame_Log_Statement, "update",  "println", ame_String("ram before deleting: ") + ame_String(getRamSize()));
			receivedMessage->resetDelete();
			SerialListenerStateLog(ame_Log_Statement, "update",  "println", ame_String("ram after deleting: ") + ame_String(getRamSize()));
			SerialListenerStateLog(ame_Log_EndMethod, "update",  "println", "");
		}
		
	protected:
		bool init = false;
		SerialState* serialState = nullptr;
		
		List<T>* receivedMessage = nullptr;
		
		List<SerialListener<T>>* listener = nullptr;
		
		List<ListenerMethod>* methodListener = nullptr;
};

}

#endif