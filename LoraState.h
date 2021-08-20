

#ifndef LoraState_h
#define LoraState_h

#include "AppState.h"
#include "Arduino.h"
#include "BaseInvoke.h"
#include "SerialMessageState.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Annotation.h"
#include "SerialMessageControlledState.h"
#include "LoRaPort.h"
#include "LoRaPortProtocol.h"
#include "NRF24L01PortProtocol.h"
#include "RadioProtocol.h"
#include "DefaultPortProtocol.h"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef LoraStateLogApp
	#include "Logger.h"
	#define LoraStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define LoraStateLog(name,method,type,mns)
#endif

namespace ame{

class LoraState : public SerialMessageControlledState{
    public:
		LoraState(){
			requests = new PrimitiveList<String>();
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
		
		virtual bool invoke(String method){
			LoraStateLog("LoraState", "invoke",  "println", "invoke method without parameters");
			return annotation1.invoke(this,method);
		}
		virtual bool invoke(String method, String parameter1){
			LoraStateLog("LoraState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation2.invoke(this,method,parameter1);
		}
		virtual bool invoke(String method, String parameter1, String parameter2){
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
					String method = *requests->getByPosition(x);
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
		
		bool LoraSend(String mns){
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
		Annotation<String,bool,LoraState> events;
		List<String>* requests = nullptr;
		Annotation<String,bool,LoraState> annotation1;
		Annotation<String,bool,LoraState,String> annotation2;
		Annotation<String,bool,LoraState,String,String> annotation3;
};

#endif 
