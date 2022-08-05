
#include "ame_Enviroment.hpp"

#if defined(DISABLE_LoraState)
	#define LoraState_hpp
#endif

#ifndef LoraState_hpp
#define LoraState_hpp
#define LoraState_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "BaseInvoke.hpp"
#include "SerialMessageState.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"
#include "Annotation.hpp"
#include "SerialMessageControlledState.hpp"
#include "LoRaPort.hpp"
#include "LoRaPortProtocol.hpp"
#include "NRF24L01PortProtocol.hpp"
#include "RadioProtocol.hpp"
#include "DefaultPortProtocol.hpp"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef LoraStateLogApp
	#include "Logger.hpp"
	#define LoraStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define LoraStateLog(name,method,type,mns)
#endif

namespace ame{

class LoraState : public SerialMessageControlledState{
    public:
		LoraState(){
			requests = new PrimitiveList<Note>();
			events = false;
			annotation1 = false;
			annotation2 = false;
			annotation3 = false;
			
			events.addLValues("Start",&LoraState::Start);
			events.addLValues("StartSending",&LoraState::StartSending);
			events.addLValues("Disconnect",&LoraState::Disconnect);
			
			annotation2.addLValues("send",&LoraState::LoraSend);
			annotation1.addLValues("requestStart",&LoraState::requestStart);
			annotation1.addLValues("requestStartSending",&LoraState::requestStartSending);
			annotation1.addLValues("requestDisconnect",&LoraState::requestDisconnect);
		}
		virtual ~LoraState(){
			delete requests;
		}
		bool instanceof(cppObjectClass* cls){return cls == Class<LoraState>::classType || SerialMessageControlledState::instanceof(cls);}
		cppObjectClass* getClass(){return Class<LoraState>::classType;}
		
		virtual bool invoke(Note method){
			LoraStateLog("LoraState", "invoke",  "println", "invoke method without parameters");
			return annotation1.invoke(this,method);
		}
		virtual bool invoke(Note method, Note parameter1){
			LoraStateLog("LoraState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation2.invoke(this,method,parameter1);
		}
		virtual bool invoke(Note method, Note parameter1, Note parameter2){
			LoraStateLog("LoraState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation3.invoke(this,method,parameter1,parameter2);
		}
		
		void update(float tpc){
			time += tpc;
			if(time > timeLimit){
				time = 0.0f;
				if(requests->isEmpty()){
					// LoraStateLog("LoraState", "update",  "println", "requests->isEmpty()");
					return;
				}
				int x = 0;
				LoraStateLog("LoraState", "update",  "println", "start for");
				for(; x < requests->getPosition(); x++){
					Note method = *requests->getByPosition(x);
					LoraStateLog("LoraState", "update",  "println", method);
					if(events.invoke(this, method)){
						LoraStateLog("LoraState", "update",  "println", "break");
						break;
					}
				}
				for(int s = 0; s < x+1; s++){
					LoraStateLog("LoraState", "update",  "println", "requests->removeDeleteByPosition(0)");
					requests->removeDeleteByPosition(0);
				}
			}
		}
		
		RadioProtocol* getProtocol(){
			return protocol;
		}
		
		bool LoraSend(Note mns){
			if(port == nullptr){
				return false;
			}
			SerialMessageState* serialState = this->getSerialMessageState();
			if(serialState == nullptr){
				return false;
			}
			serialState->send(port->getName(), mns);
			return true;
		}
		
		bool requestStart(){
			requests->addLValue("Start");
			LoraStateLog("LoraState", "requestStart",  "println", "adding Start request");
			return true;
		}
		bool requestDisconnect(){
			requests->addLValue("Disconnect");
			LoraStateLog("LoraState", "requestDisconnect",  "println", "adding Disconnect request");
			return true;
		}
		bool requestStartSending(){
			requests->addLValue("StartSending");
			LoraStateLog("LoraState", "requestStartSending",  "println", "adding StartSending request");
			return true;
		}
	protected:
	
		bool Start(){
			LoraStateLog("LoraState", "Start",  "println", "");
			SerialMessageState* serialState = this->getSerialMessageState();
			if(port == nullptr){
				port = new LoRaPort();
				protocol = new RadioProtocol();
			}else{
				serialState->removeDeleteSerialPort(port);
				port = new LoRaPort();
				protocol = new RadioProtocol();
			}
			serialState->addSerialPort(port, protocol);
			return true;
		}
		bool Disconnect(){
			LoraStateLog("LoraState", "Disconnect",  "println", "");
			SerialMessageState* serialState = this->getSerialMessageState();
			if(port == nullptr){
				return false;
			}
			serialState->removeDeleteSerialPort(port);
			port = nullptr;
			return true;
		}
		bool StartSending(){
			LoraStateLog("LoraState", "StartSending",  "println", "");
			SerialMessageState* serialState = this->getSerialMessageState();
			if(port == nullptr){
				port = new LoRaPort();
			}else{
				serialState->removeDeleteSerialPort(port);
				port = new LoRaPort();
			}
			serialState->addSerialPort(port, new LoRaPortProtocol(true));// LoRaPortProtocol DefaultPortProtocol
			return true;
		}
		
		LoRaPort* port = nullptr;
		RadioProtocol* protocol = nullptr;
		float time = 0.0f;
		float timeLimit = 0.10f;
		Annotation<Note,bool,LoraState> events;
		List<Note>* requests = nullptr;
		Annotation<Note,bool,LoraState> annotation1;
		Annotation<Note,bool,LoraState,Note> annotation2;
		Annotation<Note,bool,LoraState,Note,Note> annotation3;
};

}

#endif