
#ifndef SerialMessageState_hpp
#define SerialMessageState_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


#include "ServerProtocol.hpp"
#include "PortProtocol.hpp"
#include "SerialServer.hpp"
#include "SerialPort.hpp"
#include "Application.hpp"
#include "AppState.hpp"
#include "Command.hpp"
#include "List.hpp"
#include "PrimitiveList.hpp"
#include "Map.hpp"
#include "PrimitiveMap.hpp"
#include "SerialConnectionStateChanger.hpp"
#include "Message.hpp"
#include "SerialListener.hpp"

#ifdef SerialMessageStateLogApp
	#define SerialMessageStateLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialMessageStateLog(name,method,type,mns) 
#endif

namespace ame{

class SerialMessageState : public AppState{	
    public:
		using ListenerMethod = void (*)(Message*);
		Application* app;
		SerialMessageState(){
			SerialMessageStateLog("SerialMessageState", "Contructor",  "println", "");
			broadMessages = new PrimitiveList<String>();
			clientMessages = new PrimitiveMap<int,String>();
			servers = new PrimitiveList<SerialServer>();
			serverProtocols = new PrimitiveList<ServerProtocol>();
			ports = new PrimitiveList<SerialPort>();
			portProtocols = new PrimitiveList<PortProtocol>();
			receivedMessage = new PrimitiveList<Message>();
			listener = new PrimitiveList<SerialListener>();
			methodListener = new PrimitiveList<ListenerMethod>();
			stateChanger = new PrimitiveList<SerialConnectionStateChanger>();
		}
		virtual ~SerialMessageState(){
			SerialMessageStateLog("SerialMessageState", "Destructor",  "println", "");
			delete broadMessages;
			delete clientMessages;
			delete servers;
			delete serverProtocols;
			delete ports;
			delete portProtocols;
			delete receivedMessage;
			delete listener;
			delete methodListener;
			delete stateChanger;
		}
		
		virtual void initialize(Application *app){
			SerialMessageStateLog("SerialMessageState", "initialize",  "println", "");
		}
		
		void addSerialServer(SerialServer* serial, ServerProtocol* protocol){
			SerialMessageStateLog("SerialMessageState", "addSerialServer",  "println", "");
			serverProtocols->addPointer(protocol);
			servers->addPointer(serial);
			protocol->attach(this);
		}
    
		SerialServer* getSerialServer(int index){
			return servers->getByPosition(index);
		}

		SerialServer* getSerialServer(cppObjectClass* cls){
			for(int x = 0; x < servers->getPosition(); x++){
				if(servers->getByPosition(x)->getClass() == cls){
					return servers->getByPosition(x);
				}
			}
			return nullptr;
		}

		SerialServer* getSerialServer(String name, cppObjectClass* cls){
			for(int x = 0; x < servers->getPosition(); x++){
				if(servers->getByPosition(x)->getClass() == cls && 
						servers->getByPosition(x)->getName() == name){
					return servers->getByPosition(x);
				}
			}
			return nullptr;
		}
		
		int getSerialServerSize(){
			return servers->getPosition();
		}
		
		bool containSerialServer(SerialServer* serial){
			for(int x = 0; x < servers->getPosition(); x++){
				if(serial->equal(servers->getByPosition(x))){
					return true;
				}
			}
			return false;
		}
		
		template<class T>
		bool containSerialServer(T serial){
			for(int x = 0; x < servers->getPosition(); x++){
				if(serial.equal(servers->getByPosition(x))){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialServer(cppObjectClass* cls){
			for(int x = 0; x < servers->getPosition(); x++){
				if(servers->getByPosition(x)->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialServer(String name){
			for(int x = 0; x < servers->getPosition(); x++){
				if(servers->getByPosition(x)->getName() == name){
					return true;
				}
			}
			return false;
		}
		
		SerialServer* removeSerialServer(SerialServer* serial){
			int index = servers->getIndexByPointer(serial);
			serverProtocols->removeDeleteByPosition(index);
			return servers->removeByPointer(serial);
		}
		
		void removeDeleteSerialServer(SerialServer* serial){
			int index = servers->getIndexByPointer(serial);
			serverProtocols->removeDeleteByPosition(index);
			servers->removeDeleteByPointer(serial);
		}
		
		SerialServer* removeSerialServer(int index){
			serverProtocols->removeByPosition(index);
			return servers->removeByPosition(index);
		}
		
		void removeDeleteSerialServer(int index){
			serverProtocols->removeDeleteByPosition(index);
			servers->removeDeleteByPosition(index);
		}

		void removeAllSerialServer(){
			serverProtocols->resetDelete();
			servers->resetDelete();
		}
		
		template<class T>
		T* addSerialPort(T* serial, PortProtocol* protocol){
			SerialMessageStateLog("SerialMessageState", "addSerialPort",  "println", "with protocol");
			SerialMessageStateLog("SerialMessageState", "addSerialPort",  "println", String("name: ") + serial->getName());
			ports->addPointer(serial);
			portProtocols->addPointer(protocol);
			protocol->attach(this);
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onConnection(serial);
			}
			return serial;
		}
		
		List<SerialPort>* getSerialPorts(){
			return ports;
		}
		
		SerialPort* getSerialPort(String name){
			for(int x = 0; x < ports->getPosition(); x++){
				if(ports->getByPosition(x)->getName() == name){
					return ports->getByPosition(x);
				}
			}
			return nullptr;
		}
		
		SerialPort* getSerialPort(String name, cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* l_port = ports->getByPosition(x);
				if(l_port->getName() == name && l_port->getClass() == cls){
					return l_port;
				}
			}
			return nullptr;
		}
		
		SerialPort* getSerialPort(int index){
			return ports->getByPosition(index);
		}

		SerialPort* getSerialPort(cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				if(ports->getByPosition(x)->getClass() == cls){
					return ports->getByPosition(x);
				}
			}
			return nullptr;
		}
		
		int getSerialPortSize(){
			return ports->getPosition();
		}

		bool containSerialPort(String name, cppObjectClass* cls){
			for(int xp = 0; xp < ports->getPosition(); xp++){
				if(ports->getByPosition(xp)->getClass() == cls && 
					ports->getByPosition(xp)->getName() == name){
					return true;
				}
			}
			return false;
		}

		bool containSerialPort(cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				if(ports->getByPosition(x)->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialPort(SerialPort* serial){
			if(serial == nullptr){
				SerialMessageStateLog("SerialMessageState", "containSerialPort",  "println", "containSerialPort serial == nullptr");
				return false;
			}
			for(int x = 0; x < ports->getPosition(); x++){
				SerialMessageStateLog("SerialMessageState", "containSerialPort",  "println", "containSerialPort start ports->getPosition()");
				if(ports->getByPosition(x) == nullptr){
					SerialMessageStateLog("SerialMessageState", "containSerialPort",  "println", "containSerialPort ports->getByPosition(x) == nullptr");
					continue;
				}
				if(serial->equal(ports->getByPosition(x))){
					SerialMessageStateLog("SerialMessageState", "containSerialPort",  "println", "containSerialPort equal");
					return true;
				}
			}
			return false;
		}
		
		template<class T>
		bool containSerialPort(T serial){
			for(int x = 0; x < ports->getPosition(); x++){
				if(serial.equal(ports->getByPosition(x))){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialPort(String serial){
			for(int x = 0; x < ports->getPosition(); x++){
				if(ports->getByPosition(x)->getName() == serial){
					return true;
				}
			}
			return false;
		}
		
		SerialPort* removeSerialPort(int index){
			portProtocols->removeDeleteByPosition(index);
			SerialPort* p = ports->removeByPosition(index);
			if(p == nullptr){
				return nullptr;
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onDisconnection(p);
			}
			return p;
		}
		
		void removeDeleteSerialPort(int index){
			portProtocols->removeDeleteByPosition(index);
			SerialPort* p = ports->removeByPosition(index);
			if(p == nullptr){
				return;
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onDisconnection(p);
			}
			if(p != nullptr){
				delete p;
			}
		}
		
		SerialPort* removeSerialPort(SerialPort* serial){
			int x = ports->getIndexByPointer(serial);
			if(x == -1){
				//Serial.println("removeSerialPort: no index");
				return ports->removeByPointer(serial);
			}
			portProtocols->removeDeleteByPosition(x);
			SerialPort* p = ports->removeByPosition(x);
			if(p == nullptr){
				return nullptr;
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onDisconnection(p);
			}
			return p;
		}
		
		void removeDeleteSerialPort(SerialPort* serial){
			int x = ports->getIndexByPointer(serial);
			if(x == -1){
				return;
			}
			SerialMessageStateLog("SerialMessageState", "removeDeleteSerialPort",  "println", "");
			portProtocols->removeDeleteByPosition(x);
			SerialPort* p = ports->removeByPosition(x);
			if(p == nullptr){
				return;
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onDisconnection(p);
			}
			if(p != nullptr){
				delete p;
			}
		}
		
		void instantSend(String mns){
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "method with String as parameter");
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("Message: ") + mns);
			for(int x = 0; x < ports->getPosition(); x++){
				SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "portProtocols InstantBroadcastMessage");
				SerialPort* port = ports->getByPosition(x);
				PortProtocol* protocol = portProtocols->getByPosition(x);
				if(port == nullptr || protocol == nullptr){
					return;
				}
				protocol->InstantBroadcastMessage(port, mns);
			}
		}
		
		void instantSend(int index, String mns){
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "method with int and String as parameter");
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("Message: ") + mns);
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("index: ") + String(index));
			SerialPort* port = ports->getByPosition(index);
			PortProtocol* protocol = portProtocols->getByPosition(index);
			if(port == nullptr || protocol == nullptr){
				SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			protocol->InstantPrivateMessage(port, mns);
		}

		void instantSend(String name, String mns){
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "method with a String and a String as parameter");
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("Message: ") + mns);
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("name: ") + name);
			SerialPort* port = this->getSerialPort(name);
			int index = ports->getIndexByPointer(port);
			PortProtocol* portProtocol = portProtocols->getByPosition(index);
			if(port == nullptr || portProtocol == nullptr){
				SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			portProtocol->InstantPrivateMessage(port, mns);
		}

		void instantByteArraySend(String name, ByteArray array){
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "method with a String and a String as parameter");
			// SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("Message: ") + array);
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", String("name: ") + name);
			SerialPort* port = this->getSerialPort(name);
			int index = ports->getIndexByPointer(port);
			PortProtocol* portProtocol = portProtocols->getByPosition(index);
			if(port == nullptr || portProtocol == nullptr){
				SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			portProtocol->InstantPrivateByteArrayMessage(port, array);
		}
		
		void instantSend(Message mns){
			SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "method with Message as parameter");
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* port = ports->getByPosition(x);
				PortProtocol* portProtocol = portProtocols->getByPosition(x);
				if(port == nullptr || portProtocol == nullptr){
					SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "port == nullptr || protocol == nullptr");
					return;
				}
				if(mns.id() == -1){
					SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "portProtocols InstantBroadcastMessage");
					portProtocol->InstantBroadcastMessage(port, mns.text());
				}else{
					SerialMessageStateLog("SerialMessageState", "instantSend",  "println", "portProtocols InstantPrivateMessage");
					portProtocol->InstantPrivateMessage(port, mns.text());
				}
			}
		}
		
		void send(String mns){
			SerialMessageStateLog("SerialMessageState", "send",  "println", "method with String as parameter");
			SerialMessageStateLog("SerialMessageState", "send",  "println", String("Message: ") + mns);
			broadMessages->addLValue(mns);
		}
		
		void send(int index, String mns){
			SerialMessageStateLog("SerialMessageState", "send",  "println", "method with a int and a String as parameters");
			SerialMessageStateLog("SerialMessageState", "send",  "println", String("Message: ") + mns);
			SerialMessageStateLog("SerialMessageState", "send",  "println", String("index: ") + String(index));
			clientMessages->addPointers(new int(index), new String(mns));
		}

		void send(String name, String mns){
			SerialMessageStateLog("SerialMessageState", "send",  "println", "method with 2 Strings as parameters");
			SerialMessageStateLog("SerialMessageState", "send",  "println", String("Message: ") + mns);
			SerialMessageStateLog("SerialMessageState", "send",  "println", String("name: ") + name);
			for(int x = 0 ; x < ports->getPosition(); x++){
				if(ports->getByPosition(x)->getName() == name){
					clientMessages->addPointers(new int(x), new String(mns));
					SerialMessageStateLog("SerialMessageState", "send",  "println", String("adding"));
				}
			}
		}

		void send(SerialPort* port, String mns){
			SerialMessageStateLog("SerialMessageState", "send",  "println", "method with 2 Strings as parameters");
			SerialMessageStateLog("SerialMessageState", "send",  "println", String("Message: ") + mns);
			for(int x = 0 ; x < ports->getPosition(); x++){
				if(ports->getByPosition(x) == port){
					clientMessages->addPointers(new int(x), new String(mns));
					SerialMessageStateLog("SerialMessageState", "send",  "println", String("adding"));
				}
			}
		}
		
		void send(Message mns){
			SerialMessageStateLog("SerialMessageState", "send",  "println", "method with Message as parameter");
			if(mns.id() == -1){
				SerialMessageStateLog("SerialMessageState", "send",  "println", "no id");
				broadMessages->addLValue(mns.text());
			}else{
				SerialMessageStateLog("SerialMessageState", "send",  "println", "with id");
				clientMessages->addPointers(new int(mns.id()), new String(mns.text()));
			}
		}
		
		void send(Message* mns){
			SerialMessageStateLog("SerialMessageState", "send",  "println", "method with Message pointer as parameter");
			if(mns->id() == -1){
				SerialMessageStateLog("SerialMessageState", "send",  "println", "no id");
				broadMessages->addLValue(mns->text());
			}else{
				SerialMessageStateLog("SerialMessageState", "send",  "println", "with id");
				clientMessages->addPointers(new int(mns->id()), new String(mns->text()));
			}
		}
		
		void addListener(SerialListener* mnsCmd){
			SerialMessageStateLog("SerialMessageState", "addListener",  "println", "");
			listener->addPointer(mnsCmd);
		}
		
		void addListener(ListenerMethod method){
			SerialMessageStateLog("SerialMessageState", "addListener",  "println", "");
			methodListener->add(method);
		}
		
		SerialListener* getListener(cppObjectClass* cls){
			SerialMessageStateLog("SerialMessageState", "getListener",  "println", "");
			for(int x = 0; x < listener->getPosition(); x++){
				SerialListener* serialListener = listener->getByPosition(x);
				if(serialListener->getClass() == cls){
					return serialListener;
				}
			}
			return nullptr;
		}

		void removeDeleteListener(int index) {
			SerialMessageStateLog("SerialMessageState", "removeListener",  "println", "");
			SerialMessageStateLog("SerialMessageState", "removeListener",  "println", String("index: ") + String(index));
			listener->removeDeleteByPosition(index);
		}

		void removeAllListener() {
			SerialMessageStateLog("SerialMessageState", "removeAllListener",  "println", "");
			listener->resetDelete();
		}
		
		bool isConnected(String namae){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* port = ports->getByPosition(x);
				if(port->getName() == namae){
					return port->connected();
				}
			}
		}
    
		void disconect(void) {
			for(int x = 0; x < portProtocols->getPosition(); x++){
				portProtocols->getByPosition(x)->GlobalDisconect(ports->getByPosition(x));
			}
			ports->resetDelete();
			portProtocols->resetDelete();
		}
		
		void disconect(SerialPort* port) {
			int index = ports->getIndexByPointer(port);
			if(index == -1){
				return;
			}
			portProtocols->getByPosition(index)->Disconect(port);
			this->removeDeleteSerialPort(port);
		}
		
		void addReceivedMessage(Message* m){
			receivedMessage->addPointer(m);
		}
		
		List<Message>* getReceivedMessages(){
			return receivedMessage;
		}
		
		virtual PortProtocol* getPortProtocol(int index){
			return portProtocols->getByPosition(index);
		}
		
		virtual PortProtocol* getPortProtocol(SerialPort* port){
			return portProtocols->getByPosition(ports->getIndexByPointer(port));
		}
		
		virtual ServerProtocol* getServerProtocol(int index){
			return serverProtocols->getByPosition(index);
		}
		
		virtual ServerProtocol* getServerProtocol(SerialServer* server){
			return serverProtocols->getByPosition(servers->getIndexByPointer(server));
		}
		
		virtual void addConnectionStateChanger(SerialConnectionStateChanger* changer){
			stateChanger->addPointer(changer);
		}
		
		virtual SerialConnectionStateChanger* removeConnectionStateChanger(SerialConnectionStateChanger* changer){
			return stateChanger->removeByPointer(changer);
		}
		
		virtual void removeDeleteConnectionStateChanger(SerialConnectionStateChanger* changer){
			stateChanger->removeDeleteByPointer(changer);
		}
		
		virtual cppObjectClass* getClass(){
			return Class<SerialMessageState>::classType;
		}
		
		virtual void update(float tpc){
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* server = servers->getByPosition(x);
				ServerProtocol* serverProtocol = serverProtocols->getByPosition(x);
				if(server == nullptr || serverProtocol == nullptr){
					continue;
				}
				SerialPort* port = serverProtocol->getUpdateSerialPort(server);
				if(port != nullptr){
					SerialMessageStateLog("SerialMessageState", "update",  "println", "serial != nullptr");
					serverProtocol->UpdateSerialPort(port);
				}
				serverProtocol->update(server, tpc);
			}
			for(int index = 0; index < ports->getPosition(); index++){
				SerialPort* port = ports->getByPosition(index);
				PortProtocol* portProtocol = portProtocols->getByPosition(index);
				if(port == nullptr || portProtocol == nullptr){
					continue;
				}
				if(!port->connected()){
					SerialMessageStateLog("SerialMessageState", "update",  "println", "!port->connected()");
					portProtocol->UpdateDisconect(port);
					if(portProtocol->SafeDelete()){
						SerialMessageStateLog("SerialMessageState", "update",  "println", "portProtocol->SafeDelete()");
						portProtocols->removeByPosition(index);
						ports->removeByPosition(index);
						index--;
					}else{
						SerialMessageStateLog("SerialMessageState", "update",  "println", "!portProtocol->SafeDelete()");
						portProtocols->removeByPosition(index);
						ports->removeByPosition(index);
						index--;
					}
					for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
						SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
						schanger->onDisconnection(port);
					}
					delete port;
					delete portProtocol;
				}else{
					if(port->available() > 0) {
						SerialMessageStateLog("SerialMessageState", "update",  "println", "port->available() > 0");
						portProtocol->Read(index,port);
					}
					for(int x = 0; x < broadMessages->getPosition(); x++){
						portProtocol->BroadcastMessage(port, *broadMessages->getByPosition(x));
					}
					portProtocol->update(port,tpc);
				}
			}
			broadMessages->resetDelete();
			
			for(int x = 0; x < clientMessages->getPosition(); x++){
				int index = *clientMessages->getKeyByPosition(x);
				SerialPort* port = ports->getByPosition(index);
				PortProtocol* portProtocol = portProtocols->getByPosition(index);
				if(port == nullptr || portProtocol == nullptr){
					continue;
				}
				portProtocol->PrivateMessage(port, *clientMessages->getByPosition(x));
			}
			clientMessages->resetDelete();
			
			for(int x = 0; x < receivedMessage->getPosition(); x++){
				for(int y = 0; y < methodListener->getPosition(); y++){
					ListenerMethod  event = *methodListener->getByPosition(y);
					event(receivedMessage->getByPosition(x));
				}
				for(int y = 0; y < listener->getPosition(); y++){
					listener->getByPosition(y)->execute(receivedMessage->getByPosition(x));
				}
			}
			receivedMessage->resetDelete();
		}
		
	protected:
		List<String>* broadMessages = nullptr;
		Map<int,String>* clientMessages = nullptr;
		
		List<SerialServer>* servers = nullptr;
		List<ServerProtocol>* serverProtocols = nullptr;
		
		List<SerialPort>* ports = nullptr;
		List<PortProtocol>* portProtocols = nullptr;
		
		List<Message>* receivedMessage = nullptr;
		
		List<SerialListener>* listener = nullptr;
		
		List<ListenerMethod>* methodListener = nullptr;
		
		List<SerialConnectionStateChanger>* stateChanger = nullptr;
};

}

#endif