

#ifndef AlwaysConnected_h
#define AlwaysConnected_h

#include "AppState.h"
#include "Arduino.h"
#include "BaseInvoke.h"
#include "SerialMessageState.h"
#include "List.h"
#include "PrimitiveList.h"
#include "Annotation.h"
#include "SerialMessageControlledState.h"

#ifdef AlwaysConnectedLogApp
	#include "Logger.h"
	#define AlwaysConnectedLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define AlwaysConnectedLog(name,method,type,mns)
#endif


class AlwaysConnected : public AppState{
    public:
		AlwaysConnected(){
		}
		virtual ~AlwaysConnected(){
		}
		virtual bool instanceof(cppObjectClass* cls){return cls == Class<AlwaysConnected>::classType || AppState::instanceof(cls);}
		virtual cppObjectClass* getClassName(){return Class<AlwaysConnected>::classType;}
		
		void initialize(Application *a){
			AlwaysConnectedLog("AlwaysConnected", "initialize",  "println", "");
			app = a;
			serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
		}
		
		virtual void update(float tpc){
			if(serialState == nullptr){
				serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
				return;
			}
			time += tpc;
			if(time < time_limite){
				return;
			}
			time = 0.0f;
			for(int x = 0; x < serialports.getPosition(); x++){
				SerialPort* serialport = serialports.getByPosition(x);
				String name = serialport->getName();
				IPAddress ip = *ips.getByPosition(x);
				int port = *ports.getByPosition(x);
				PortProtocol* portprotocol = portprotocols.getByPosition(x);
				if(serialport == nullptr){
					continue;
				}
				if(serialport->connected()){
					continue;
				}
				AlwaysConnectedLog("AlwaysConnected", "update",  "println", "");
				AlwaysConnectedLog("AlwaysConnected", "update",  "println", String("iteration ")+String(x));
				if(serialport->conect(ip,port)){
					serialState->addSerialPort(serialport,portprotocol);
					serialState->send(String("io ioName ")+serialport->getName());
				}
			}
		}
		virtual void add(String n, IPAddress i, int pt, SerialPort* s, PortProtocol* p){
			s->setName(n);
			ips.addLValue(i);
			ports.addLValue(pt);
			serialports.addPointer(s);
			portprotocols.addPointer(p);
			p->setSafeDelete(false);
		}
		virtual void remove(String n){
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
		SerialMessageState* serialState = nullptr;
		PrimitiveList<IPAddress> ips;
		PrimitiveList<int> ports;
		PrimitiveList<SerialPort> serialports;
		PrimitiveList<PortProtocol> portprotocols;
		float time = 0;
		float time_limite = 5.5f;
};

#endif 
