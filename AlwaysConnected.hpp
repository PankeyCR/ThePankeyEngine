
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AlwaysConnected)
	#define AlwaysConnected_hpp
#endif

#ifndef AlwaysConnected_hpp
#define AlwaysConnected_hpp
#define AlwaysConnected_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "SerialState.hpp"
#include "PrimitiveList.hpp"

#ifdef AlwaysConnected_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define AlwaysConnectedLog(location,method,type,mns) ame_Log(this,location,"AlwaysConnected",method,type,mns)
	#define const_AlwaysConnectedLog(location,method,type,mns) 
	#define StaticAlwaysConnectedLog(pointer,location,method,type,mns) ame_Log(pointer,location,"AlwaysConnected",method,type,mns)
#else
	#ifdef AlwaysConnected_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define AlwaysConnectedLog(location,method,type,mns) ame_LogDebug(this,location,"AlwaysConnected",method,type)
		#define const_AlwaysConnectedLog(location,method,type,mns) 
		#define StaticAlwaysConnectedLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"AlwaysConnected",method,type)
	#else
		#define AlwaysConnectedLog(location,method,type,mns) 
		#define const_AlwaysConnectedLog(location,method,type,mns) 
		#define StaticAlwaysConnectedLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class AlwaysConnected : public AppState{
    public:
		AlwaysConnected(){
		}
		AlwaysConnected(Note s){
			myName = s;
		}
		virtual ~AlwaysConnected(){
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<AlwaysConnected>::classType || AppState::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<AlwaysConnected>::classType;}
		
		void initialize(Application *a){
			AlwaysConnectedLog(ame_Log_Statement, "initialize",  "println", "");
			app = a;
			serialState = (SerialState*)app->getStateManager()->get(Class<SerialState>::classType);
		}
		
		virtual void update(float tpc){
			if(serialState == nullptr){
				serialState = (SerialState*)app->getStateManager()->get(Class<SerialState>::classType);
				return;
			}
			time += tpc;
			if(time < time_limite){
				return;
			}
			time = 0.0f;
			for(int x = 0; x < serialports.getPosition(); x++){
				SerialPort* serialport = serialports.getByPosition(x);
				if(serialport == nullptr){
					continue;
				}
				Note name = serialport->getName();
				IPAddress ip = *ips.getByPosition(x);
				int port = *ports.getByPosition(x);
				PortProtocol* portprotocol = portprotocols.getByPosition(x);
				if(serialport->connected()){
					continue;
				}
				// if(!serialState->ping(ip)){
					// continue;
				// }
				AlwaysConnectedLog(ame_Log_Statement, "update",  "println", "");
				AlwaysConnectedLog(ame_Log_Statement, "update",  "println", Note("iteration ")+Note(x));
				if(serialport->connect(ip,port)){
					serialState->addSerialPort(serialport,portprotocol);
					serialState->send(serialport, Note("MyNameIs ") + myName);
				}
			}
		}
		virtual void add(Note n, IPAddress i, int pt, SerialPort* s, PortProtocol* p){
			s->setName(n);
			ips.addLValue(i);
			ports.addLValue(pt);
			serialports.addPointer(s);
			portprotocols.addPointer(p);
			p->setSafeDelete(false);
		}
		virtual void remove(Note n){
			int x=-1;
			for(int t = 0; t < serialports.getPosition(); t++){
				if(serialports.getByPosition(t)->getName() == n){
					x = t;
					break;
				}
			}
			if(x == -1){
				return;
			}
			ips.removeDeleteByPosition(x);
			ports.removeDeleteByPosition(x);
			serialports.removeDeleteByPosition(x);
			portprotocols.removeDeleteByPosition(x);
		}
	protected:
		Application* app = nullptr;
		SerialState* serialState = nullptr;
		PrimitiveList<IPAddress> ips;
		PrimitiveList<int> ports;
		PrimitiveList<SerialPort> serialports;
		PrimitiveList<PortProtocol> portprotocols;
		float time = 0;
		float time_limite = 5.5f;
		Note myName = "micro";
};

}

#endif
