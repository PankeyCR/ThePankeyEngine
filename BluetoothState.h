

#ifndef BluetoothState_h
#define BluetoothState_h

#include "AppState.h"
#include "Arduino.h"
#include "BaseInvoke.h"
#include "SerialMessageState.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Annotation.h"
#include "SerialMessageControlledState.h"

#if defined(ARDUINO_ARCH_ESP8266)
	#include "WiFi.h"
#elif defined(ARDUINO_ARCH_ESP32)
	#include "WiFi.h"
#endif

#ifdef BluetoothStateLogApp
	#include "Logger.h"
	#define BluetoothStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define BluetoothStateLog(name,method,type,mns)
#endif


class BluetoothState : public SerialMessageControlledState{
    public:
		BluetoothState(){
			requests = new PrimitiveList<String>();
			events = false;
			annotation1 = false;
			annotation2 = false;
			annotation3 = false;
			
			events.addLValues("Start",&BluetoothState::Start);
			
			annotation1.addLValues("requestStart",&BluetoothState::requestStart);
		}
		virtual ~BluetoothState(){
			delete requests;
		}
		bool instanceof(String name){return name == "BluetoothState" || SerialMessageControlledState::instanceof(name);}
		String getClassName(){return "BluetoothState";}
		
		virtual bool invoke(String method){
			BluetoothStateLog("BluetoothState", "invoke",  "println", "invoke method without parameters");
			return annotation1.invoke(this,method);
		}
		virtual bool invoke(String method, String parameter1){
			BluetoothStateLog("BluetoothState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation2.invoke(this,method,parameter1);
		}
		virtual bool invoke(String method, String parameter1, String parameter2){
			BluetoothStateLog("BluetoothState", "invoke",  "println", "invoke method with 1 parameter");
			return annotation3.invoke(this,method,parameter1,parameter2);
		}
		
		void update(float tpc){
			time += tpc;
			if(time > timeLimit){
				time = 0.0f;
				if(requests->isEmpty()){
					BluetoothStateLog("BluetoothState", "update",  "println", "requests->isEmpty()");
					return;
				}
				int x = 0;
				BluetoothStateLog("BluetoothState", "update",  "println", "start for");
				for(; x < requests->getPosition(); x++){
					String method = *requests->getByPosition(x);
					BluetoothStateLog("BluetoothState", "update",  "println", method);
					if(events.invoke(this, method)){
						BluetoothStateLog("BluetoothState", "update",  "println", "break");
						break;
					}
				}
				for(int s = 0; s < x+1; s++){
					BluetoothStateLog("BluetoothState", "update",  "println", "requests->removeDeleteByPosition(0)");
					requests->removeDeleteByPosition(0);
				}
			}
		}
		
		bool requestStart(){
			requests->addLValue("Start");
			return true;
		}
	protected:
	
		bool Start(){
			
			return true;
		}
		
		float time = 0.0f;
		float timeLimit = 0.10f;
		Annotation<String,bool,BluetoothState> events;
		List<String>* requests = nullptr;
		Annotation<String,bool,BluetoothState> annotation1;
		Annotation<String,bool,BluetoothState,String> annotation2;
		Annotation<String,bool,BluetoothState,String,String> annotation3;
};

#endif 
