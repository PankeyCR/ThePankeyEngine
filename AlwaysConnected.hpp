
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef AlwaysConnected_hpp
#define AlwaysConnected_hpp

#include "AppState.hpp"
#include "Arduino.hpp"
#include "SerialMessageState.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"
#include "TextExporter.hpp"
#include "Annotation.hpp"
#include "SerialMessageControlledState.hpp"

#ifdef AlwaysConnectedLogApp
	#include "Logger.hpp"
	#define AlwaysConnectedLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define AlwaysConnectedLog(name,method,type,mns)
#endif

namespace ame{

class AlwaysConnected : public AppState{
    public:
		AlwaysConnected(){
		}
		AlwaysConnected(String s){
			myName = s;
		}
		virtual ~AlwaysConnected(){
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<AlwaysConnected>::classType || AppState::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){return Class<AlwaysConnected>::classType;}
		
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
				if(serialport == nullptr){
					continue;
				}
				String name = serialport->getName();
				IPAddress ip = *ips.getByPosition(x);
				int port = *ports.getByPosition(x);
				PortProtocol* portprotocol = portprotocols.getByPosition(x);
				if(serialport->connected()){
					continue;
				}
				AlwaysConnectedLog("AlwaysConnected", "update",  "println", "");
				AlwaysConnectedLog("AlwaysConnected", "update",  "println", String("iteration ")+String(x));
				if(serialport->conect(ip,port)){
					serialState->addSerialPort(serialport,portprotocol);
					TextExporter exporter;
					exporter.write("MyNameIs", myName);
					serialState->send(serialport, exporter.getText());
				}
			}
		}
		virtual void add(String n, IPAddress i, int pt, SerialPort* s, ame::PortProtocol* p){
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
		String myName = "micro";
};

}

#endif

#endif 
