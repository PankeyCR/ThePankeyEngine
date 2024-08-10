
#include "higgs_Enviroment.hpp"

#if defined(DISABLE_BluetoothState)
	#define BluetoothState_hpp
#endif

#ifndef BluetoothState_hpp
#define BluetoothState_hpp
#define BluetoothState_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"

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

namespace higgs{

class BluetoothState : public AppState{
    public:
		BluetoothState(){}
		virtual ~BluetoothState(){}
		
		bool instanceof(cppObjectClass* cls){
			return name == Class<BluetoothState>::classType || AppState::instanceof(cls);
		}
		cppObjectClass* getClass(){return Class<BluetoothState>classType;}
		
		void update(float tpc){
			time += tpc;
			if(time > timeLimit){
				time = 0.0f;
				
			}
		}
		
	protected:
		
		float time = 0.0f;
		float timeLimit = 0.10f;
};

#endif