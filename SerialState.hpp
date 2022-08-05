
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialState)
	#define SerialState_hpp
#endif

#ifndef SerialState_hpp
#define SerialState_hpp
#define SerialState_AVAILABLE

#ifndef ame_Enviroment_Defined

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
#include "List.hpp"
#include "PrimitiveList.hpp"
#include "Map.hpp"
#include "PrimitiveMap.hpp"
#include "SerialConnectionStateChanger.hpp"

#ifdef SerialState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define SerialStateLog(location,method,type,mns) ame_Log(this,location,"SerialState",method,type,mns)
	#define const_SerialStateLog(location,method,type,mns) 
	#define StaticSerialStateLog(pointer,location,method,type,mns) ame_Log(pointer,location,"SerialState",method,type,mns)
#else
	#ifdef SerialState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define SerialStateLog(location,method,type,mns) ame_LogDebug(this,location,"SerialState",method,type)
		#define const_SerialStateLog(location,method,type,mns) 
		#define StaticSerialStateLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"SerialState",method,type)
	#else
		#define SerialStateLog(location,method,type,mns) 
		#define const_SerialStateLog(location,method,type,mns) 
		#define StaticSerialStateLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{

class SerialState : public AppState{	
    public:
		using MethodStateChanger = void (*)(SerialPort*,PortProtocol*);
		using MethodStateGlobalChanger = void (*)();
		
		Application* app;
		
		SerialState(){
			SerialStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			
			broadMessages = new PrimitiveList<Note>();
			clientMessages = new PrimitiveMap<int,Note>();
			servers = new PrimitiveList<SerialServer>();
			serverProtocols = new PrimitiveList<ServerProtocol>();
			ports = new PrimitiveList<SerialPort>();
			portProtocols = new PrimitiveList<PortProtocol>();
			
			stateChanger = new PrimitiveList<SerialConnectionStateChanger>();
			
			methodStateGlobalChanger_onConnection = new PrimitiveList<MethodStateGlobalChanger>();
			methodStateGlobalChanger_onDisconnection = new PrimitiveList<MethodStateGlobalChanger>();
			
			methodStateChanger_onConnection = new PrimitiveList<MethodStateChanger>();
			methodStateChanger_onDisconnection = new PrimitiveList<MethodStateChanger>();
			
			SerialStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~SerialState(){
			SerialStateLog(ame_Log_StartMethod, "Destructor", "println", "");
			delete broadMessages;
			delete clientMessages;
			delete servers;
			delete serverProtocols;
			delete ports;
			delete portProtocols;
			
			delete stateChanger;
			
			delete methodStateGlobalChanger_onConnection;
			delete methodStateGlobalChanger_onDisconnection;
			
			delete methodStateChanger_onConnection;
			delete methodStateChanger_onDisconnection;
			
			SerialStateLog(ame_Log_EndMethod, "Destructor", "println", "");
		}
		
		virtual void initialize(Application *a){
			SerialStateLog(ame_Log_StartMethod, "initialize", "println", "");
			app = a;
			hasInit = true;
			for(int x = 0; x < serverProtocols->getPosition(); x++){
				ServerProtocol* proto = serverProtocols->getByPosition(x);
				if(proto == nullptr){
					continue;
				}
				proto->attach(this);
			}
			for(int x = 0; x < portProtocols->getPosition(); x++){
				PortProtocol* proto = portProtocols->getByPosition(x);
				if(proto == nullptr){
					continue;
				}
				proto->attach(this);
			}
			SerialStateLog(ame_Log_EndMethod, "initialize", "println", "");
		}
		
		Application* getApplication(){return app;}
		
		//The onConnections methods are only used if the port and the protocol are not nullptr
		
		void onGlobalConnection(){
			SerialStateLog(ame_Log_StartMethod, "onGlobalConnection", "println", "");
			for(int xDisc = 0; xDisc < methodStateGlobalChanger_onConnection->getPosition(); xDisc++){
				MethodStateGlobalChanger* schanger = methodStateGlobalChanger_onConnection->getByPosition(xDisc);
				(*schanger)();//change
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onGlobalConnection();
			}
			SerialStateLog(ame_Log_EndMethod, "onGlobalConnection", "println", "");
		}
		
		void onGlobalDisconnection(){
			SerialStateLog(ame_Log_StartMethod, "onGlobalDisconnection", "println", "");
			for(int xDisc = 0; xDisc < methodStateGlobalChanger_onDisconnection->getPosition(); xDisc++){
				MethodStateGlobalChanger* schanger = methodStateGlobalChanger_onDisconnection->getByPosition(xDisc);
				(*schanger)();//change
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onGlobalDisconnection();
			}
			SerialStateLog(ame_Log_EndMethod, "onGlobalDisconnection", "println", "");
		}
		
		void onConnection(){
			SerialStateLog(ame_Log_StartMethod, "onConnection", "println", "");
			for(int x_ports = 0; x_ports < ports->getPosition(); x_ports++){
				SerialPort* f_ports = ports->getByPosition(x_ports);
				PortProtocol* f_protocol = portProtocols->getByPosition(x_ports);
				for(int xDisc = 0; xDisc < methodStateChanger_onConnection->getPosition(); xDisc++){
					MethodStateChanger* schanger = methodStateChanger_onConnection->getByPosition(xDisc);
					(*schanger)(f_ports, f_protocol);//change
				}
				for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
					SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
					schanger->onConnection(f_ports, f_protocol);
				}
			}
			SerialStateLog(ame_Log_EndMethod, "onConnection", "println", "");
		}
		
		void onDisconnection(){
			SerialStateLog(ame_Log_StartMethod, "onDisconnection", "println", "");
			for(int x_ports = 0; x_ports < ports->getPosition(); x_ports++){
				SerialPort* f_ports = ports->getByPosition(x_ports);
				PortProtocol* f_protocol = portProtocols->getByPosition(x_ports);
				for(int xDisc = 0; xDisc < methodStateChanger_onDisconnection->getPosition(); xDisc++){
					MethodStateChanger* schanger = methodStateChanger_onDisconnection->getByPosition(xDisc);
					(*schanger)(f_ports, f_protocol);//change
				}
				for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
					SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
					schanger->onDisconnection(f_ports, f_protocol);
				}
			}
			SerialStateLog(ame_Log_EndMethod, "onDisconnection", "println", "");
		}
		
		void onConnection(SerialPort* a_serialport, PortProtocol* a_portprotocol){
			SerialStateLog(ame_Log_StartMethod, "onConnection", "println", "");
			for(int xDisc = 0; xDisc < methodStateChanger_onConnection->getPosition(); xDisc++){
				MethodStateChanger* schanger = methodStateChanger_onConnection->getByPosition(xDisc);
				(*schanger)(a_serialport, a_portprotocol);//change
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onConnection(a_serialport, a_portprotocol);
			}
			SerialStateLog(ame_Log_EndMethod, "onConnection", "println", "");
		}
		
		void onDisconnection(SerialPort* a_serialport, PortProtocol* a_portprotocol){
			SerialStateLog(ame_Log_StartMethod, "onDisconnection", "println", "");
			for(int xDisc = 0; xDisc < methodStateChanger_onDisconnection->getPosition(); xDisc++){
				MethodStateChanger* schanger = methodStateChanger_onDisconnection->getByPosition(xDisc);
				(*schanger)(a_serialport, a_portprotocol);//change
			}
			for(int xDisc = 0; xDisc < stateChanger->getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = stateChanger->getByPosition(xDisc);
				schanger->onDisconnection(a_serialport, a_portprotocol);
			}
			SerialStateLog(ame_Log_EndMethod, "onDisconnection", "println", "");
		}
		
		SerialServer* addSerialServer(SerialServer* serial, ServerProtocol* protocol){
			SerialStateLog(ame_Log_StartMethod, "addSerialServer", "println", "");
			if(serial == nullptr && protocol == nullptr){
				return nullptr;
			}
			serverProtocols->addPointer(protocol);
			servers->addPointer(serial);
			if(protocol != nullptr && hasInit){
				protocol->attach(this);
			}
			SerialStateLog(ame_Log_EndMethod, "addSerialServer", "println", "");
			return serial;
		}
    
		SerialServer* getSerialServer(int index){
			return servers->getByPosition(index);
		}

		SerialServer* getSerialServer(cppObjectClass* cls){
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* i_server = servers->getByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getClass() == cls){
					return i_server;
				}
			}
			return nullptr;
		}

		SerialServer* getSerialServer(Note name, cppObjectClass* cls){
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* i_server = servers->getByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getClass() == cls && i_server->getName() == name){
					return i_server;
				}
			}
			return nullptr;
		}
		
		int getSerialServerSize(){
			return servers->getPosition();
		}
		
		bool containSerialServer(SerialServer* serial){
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* i_server = servers->getByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(serial->equal(i_server)){
					return true;
				}
			}
			return false;
		}
		/*
		template<class T>
		bool containSerialServer(T serial){
			for(int x = 0; x < servers->getPosition(); x++){
				if(serial.equal(servers->getByPosition(x))){
					return true;
				}
			}
			return false;
		}
		*/
		bool containSerialServer(cppObjectClass* cls){
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* i_server = servers->getByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialServer(Note name){
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* i_server = servers->getByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getName() == name){
					return true;
				}
			}
			return false;
		}
		
		SerialServer* removeSerialServer(SerialServer* serial){
			SerialStateLog(ame_Log_StartMethod, "removeSerialServer", "println", "");
			int index = servers->getIndexByPointer(serial);
			if(index == -1){
				return nullptr;
			}
			serverProtocols->removeDeleteByPosition(index);
			SerialStateLog(ame_Log_EndMethod, "removeSerialServer", "println", "");
			return servers->removeByPointer(serial);
		}
		
		void removeDeleteSerialServer(SerialServer* serial){
			SerialStateLog(ame_Log_StartMethod, "removeDeleteSerialServer", "println", "");
			int index = servers->getIndexByPointer(serial);
			if(index == -1){
				return;
			}
			serverProtocols->removeDeleteByPosition(index);
			servers->removeDeleteByPointer(serial);
			SerialStateLog(ame_Log_EndMethod, "removeDeleteSerialServer", "println", "");
		}
		
		SerialServer* removeSerialServer(int index){
			SerialStateLog(ame_Log_StartMethod, "removeSerialServer", "println", "");
			serverProtocols->removeDeleteByPosition(index);
			SerialStateLog(ame_Log_EndMethod, "removeSerialServer", "println", "");
			return servers->removeByPosition(index);
		}
		
		void removeDeleteSerialServer(int index){
			SerialStateLog(ame_Log_StartMethod, "removeDeleteSerialServer", "println", "");
			serverProtocols->removeDeleteByPosition(index);
			servers->removeDeleteByPosition(index);
			SerialStateLog(ame_Log_EndMethod, "removeDeleteSerialServer", "println", "");
		}

		void removeAllSerialServer(){
			SerialStateLog(ame_Log_StartMethod, "removeAllSerialServer", "println", "");
			serverProtocols->reset();
			servers->reset();
			SerialStateLog(ame_Log_EndMethod, "removeAllSerialServer", "println", "");
		}

		void removeDeleteAllSerialServer(){
			SerialStateLog(ame_Log_StartMethod, "removeAllSerialServer", "println", "");
			serverProtocols->resetDelete();
			servers->resetDelete();
			SerialStateLog(ame_Log_EndMethod, "removeAllSerialServer", "println", "");
		}
		
		SerialPort* addSerialPort(SerialPort* serial, PortProtocol* protocol){
			SerialStateLog(ame_Log_StartMethod, "addSerialPort",  "println", "with protocol");
			if(serial == nullptr && protocol == nullptr){
				return nullptr;
			}
			ports->addPointer(serial);
			portProtocols->addPointer(protocol);
			if(protocol != nullptr && hasInit){
				protocol->attach(this);
			}
			SerialStateLog(ame_Log_EndMethod, "addSerialPort", "println", "");
			return serial;
		}
		
		List<SerialPort>* getSerialPorts(){
			return ports;
		}
		
		SerialPort* getSerialPort(Note name){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == name){
					return i_port;
				}
			}
			return nullptr;
		}
		
		SerialPort* getSerialPort(Note name, cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == name && i_port->getClass() == cls){
					return i_port;
				}
			}
			return nullptr;
		}
		
		SerialPort* getSerialPort(int index){
			return ports->getByPosition(index);
		}

		SerialPort* getSerialPort(cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getClass() == cls){
					return i_port;
				}
			}
			return nullptr;
		}
		
		int getSerialPortSize(){
			return ports->getPosition();
		}

		bool containSerialPort(Note name, cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getClass() == cls && i_port->getName() == name){
					return true;
				}
			}
			return false;
		}

		bool containSerialPort(cppObjectClass* cls){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		bool containSerialPort(SerialPort* serial){
			SerialStateLog(ame_Log_StartMethod, "containSerialPort", "println", "");
			if(serial == nullptr){
				SerialStateLog(ame_Log_Statement, "containSerialPort",  "println", "containSerialPort serial == nullptr");
				return false;
			}
			for(int x = 0; x < ports->getPosition(); x++){
				SerialStateLog(ame_Log_Statement, "containSerialPort",  "println", "containSerialPort start ports->getPosition()");
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					SerialStateLog(ame_Log_Statement, "containSerialPort",  "println", "containSerialPort ports->getByPosition(x) == nullptr");
					continue;
				}
				if(serial->equal(i_port)){
					SerialStateLog(ame_Log_Statement, "containSerialPort",  "println", "containSerialPort equal");
					return true;
				}
			}
			SerialStateLog(ame_Log_EndMethod, "containSerialPort", "println", "");
			return false;
		}
		/*
		template<class T>
		bool containSerialPort(T serial){
			for(int x = 0; x < ports->getPosition(); x++){
				if(serial.equal(ports->getByPosition(x))){
					return true;
				}
			}
			return false;
		}
		*/
		bool containSerialPort(Note serial){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == serial){
					return true;
				}
			}
			return false;
		}
		
		SerialPort* removeSerialPort(int index){
			SerialStateLog(ame_Log_StartMethod, "removeSerialPort",  "println", "with protocol");
			SerialPort* i_port = ports->removeByPosition(index);
			PortProtocol* i_protocol = portProtocols->removeByPosition(index);
			if(i_protocol != nullptr){
				delete i_protocol;
			}
			SerialStateLog(ame_Log_EndMethod, "removeSerialPort", "println", "");
			return i_port;
		}
		
		void removeDeleteSerialPort(int index){
			SerialStateLog(ame_Log_StartMethod, "removeDeleteSerialPort",  "println", "with protocol");
			SerialPort* i_port = ports->removeByPosition(index);
			PortProtocol* i_protocol = portProtocols->removeByPosition(index);
			if(i_port != nullptr){
				delete i_port;
			}
			if(i_protocol != nullptr){
				delete i_protocol;
			}
			SerialStateLog(ame_Log_EndMethod, "removeDeleteSerialPort", "println", "");
		}
		
		SerialPort* removeSerialPort(SerialPort* serial){
			SerialStateLog(ame_Log_StartMethod, "removeSerialPort",  "println", "with protocol");
			int x = ports->getIndexByPointer(serial);
			if(x == -1){
				return nullptr;
			}
			SerialPort* i_port = ports->removeByPosition(x);
			PortProtocol* i_protocol = portProtocols->removeByPosition(x);
			if(i_protocol != nullptr){
				delete i_protocol;
			}
			SerialStateLog(ame_Log_EndMethod, "removeSerialPort", "println", "");
			return i_port;
		}
		
		void removeDeleteSerialPort(SerialPort* serial){
			SerialStateLog(ame_Log_StartMethod, "removeDeleteSerialPort",  "println", "with protocol");
			int x = ports->getIndexByPointer(serial);
			if(x == -1){
				return;
			}
			SerialStateLog(ame_Log_Statement, "removeDeleteSerialPort",  "println", "");
			SerialPort* i_port = ports->removeByPosition(x);
			PortProtocol* i_protocol = portProtocols->removeByPosition(x);
			if(i_port != nullptr){
				delete i_port;
			}
			if(i_protocol != nullptr){
				delete i_protocol;
			}
			SerialStateLog(ame_Log_EndMethod, "removeDeleteSerialPort", "println", "");
		}
		
		void removeAllSerialPort(){
			SerialStateLog(ame_Log_StartMethod, "removeAllSerialPort",  "println", "with protocol");
			ports->reset();
			portProtocols->reset();
			SerialStateLog(ame_Log_EndMethod, "removeAllSerialPort", "println", "");
		}
		
		void removeDeleteAllSerialPort(){
			SerialStateLog(ame_Log_StartMethod, "removeAllSerialPort",  "println", "with protocol");
			ports->resetDelete();
			portProtocols->resetDelete();
			SerialStateLog(ame_Log_EndMethod, "removeAllSerialPort", "println", "");
		}
		
		void ServerSend(Note a_server_name, Note a_mns){
			SerialStateLog(ame_Log_StartMethod, "removeAllSerialPort",  "println", "with protocol");
			for(int x = 0; x < servers->getPosition(); x++){
				SerialServer* server = servers->getByPosition(x);
				ServerProtocol* protocol = serverProtocols->getByPosition(x);
				if(server == nullptr || protocol == nullptr){
					continue;
				}
				if(server->getName() != a_server_name){
					continue;
				}
				protocol->NetworkMessage(server, a_mns);
			}
			SerialStateLog(ame_Log_EndMethod, "removeAllSerialPort", "println", "");
		}
		
		void instantSend(Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with Note as parameter");
			//SerialStateLog(ame_Log_Statement, "instantSend",  "println", ame_String("Message: ") + ame_String(mns));
			for(int x = 0; x < ports->getPosition(); x++){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "portProtocols InstantBroadcastMessage");
				SerialPort* port = ports->getByPosition(x);
				PortProtocol* protocol = portProtocols->getByPosition(x);
				if(port == nullptr || protocol == nullptr){
					return;
				}
				protocol->InstantBroadcastMessage(port, mns);
			}
		}
		
		void instantSend(int index, Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with int and Note as parameter");
			//SerialStateLog(ame_Log_Statement, "instantSend",  "println", ame_String("Message: ") + ame_String(mns));
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", ame_String("index: ") + ame_String(index));
			SerialPort* port = ports->getByPosition(index);
			PortProtocol* protocol = portProtocols->getByPosition(index);
			if(port == nullptr || protocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			protocol->InstantPrivateMessage(port, mns);
		}
		
		void instantPortSend(SerialPort* a_port, Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with serialport and Note as parameter");
			SerialPort* port = a_port;
			PortProtocol* protocol = getPortProtocol(a_port);
			if(port == nullptr || protocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			protocol->InstantPrivateMessage(port, mns);
		}

		void instantSend(Note name, Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with a Note and a Note as parameter");
			//SerialStateLog(ame_Log_Statement, "instantSend",  "println", ame_String("Message: ") + ame_String(mns.pointer()));
			//SerialStateLog(ame_Log_Statement, "instantSend",  "println", ame_String("name: ") + ame_String(name.pointer()));
			SerialPort* port = this->getSerialPort(name);
			int index = ports->getIndexByPointer(port);
			PortProtocol* portProtocol = portProtocols->getByPosition(index);
			if(port == nullptr || portProtocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			portProtocol->InstantPrivateMessage(port, mns);
		}

		void instantByteArraySend(Note name, ByteArray array){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with a Note and a Note as parameter");
			//////SerialStateLog(ame_Log_Statement, "instantSend",  "println", Note("Message: ") + array);
			//SerialStateLog(ame_Log_Statement, "instantSend",  "println", ame_String("name: ") + ame_String(name));
			SerialPort* port = this->getSerialPort(name);
			int index = ports->getIndexByPointer(port);
			PortProtocol* portProtocol = portProtocols->getByPosition(index);
			if(port == nullptr || portProtocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			portProtocol->InstantPrivateByteArrayMessage(port, array);
		}
		
		void instantSend(Message mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with Message as parameter");
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* port = ports->getByPosition(x);
				PortProtocol* portProtocol = portProtocols->getByPosition(x);
				if(port == nullptr || portProtocol == nullptr){
					SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
					return;
				}
				if(mns.id() == -1){
					SerialStateLog(ame_Log_Statement, "instantSend",  "println", "portProtocols InstantBroadcastMessage");
					portProtocol->InstantBroadcastMessage(port, mns.text());
				}else{
					SerialStateLog(ame_Log_Statement, "instantSend",  "println", "portProtocols InstantPrivateMessage");
					portProtocol->InstantPrivateMessage(port, mns.text());
				}
			}
		}
		
		void send(Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with Note as parameter");
			//SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("Message: ") + ame_String(mns.pointer());
			broadMessages->addLValue(mns);
		}
		
		void send(int index, Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with a int and a Note as parameters");
			//SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("Message: ") + ame_String(mns.pointer());
			SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("index: ") + ame_String(index));
			clientMessages->addPointers(new int(index), new Note(mns));
		}

		void send(Note name, Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with 2 Notes as parameters");
			//SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("Message: ") + ame_String(mns.pointer()));
			//SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("name: ") + ame_String(name.pointer()));
			for(int x = 0 ; x < ports->getPosition(); x++){
				if(ports->getByPosition(x)->getName() == name){
					clientMessages->addPointers(new int(x), new Note(mns));
					SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("adding"));
				}
			}
		}

		void send(SerialPort* port, Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with 2 Notes as parameters");
			//SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("Message: ") + ame_String(mns.pointer()));
			for(int x = 0 ; x < ports->getPosition(); x++){
				if(ports->getByPosition(x) == port){
					clientMessages->addPointers(new int(x), new Note(mns));
					SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("adding"));
				}
			}
		}
		
		void send(Message mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with Message as parameter");
			if(mns.id() == -1){
				SerialStateLog(ame_Log_Statement, "send",  "println", "no id");
				broadMessages->addLValue(mns.text());
			}else{
				SerialStateLog(ame_Log_Statement, "send",  "println", "with id");
				clientMessages->addPointers(new int(mns.id()), new Note(mns.text()));
			}
		}
		
		void send(Message* mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with Message pointer as parameter");
			if(mns->id() == -1){
				SerialStateLog(ame_Log_Statement, "send",  "println", "no id");
				broadMessages->addLValue(mns->text());
			}else{
				//SerialStateLog(ame_Log_Statement, "send",  "println", "with id");
				clientMessages->addPointers(new int(mns->id()), new Note(mns->text()));
			}
		}
		
		bool isConnected(Note namae){
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				if(i_port->getName() == namae){
					return i_port->connected();
				}
			}
			return false;
		}
    
		void connect(void) {
			for(int x = 0; x < ports->getPosition(); x++){
				SerialPort* i_ports = ports->getByPosition(x);
				PortProtocol* i_protocol = portProtocols->getByPosition(x);
				if(i_ports == nullptr || i_protocol == nullptr){
					continue;
				}
				i_protocol->GlobalConect(i_ports);
				onConnection(i_ports, i_protocol);
			}
			onGlobalConnection();
		}
		
		void connect(SerialPort* port) {
			int index = ports->getIndexByPointer(port);
			if(index == -1){
				return;
			}
			PortProtocol* i_protocol = portProtocols->getByPosition(index);
			if(port == nullptr || i_protocol == nullptr){
				return;
			}
			i_protocol->Conect(port);
			onConnection(port, i_protocol);
		}
		
		void connect(Note a_name) {
			for(int x = 0; x < portProtocols->getPosition(); x++){
				SerialPort* i_port = ports->getByPosition(x);
				PortProtocol* i_protocol = portProtocols->getByPosition(x);
				if(i_port == nullptr || i_protocol == nullptr){
					continue;
				}
				if(a_name != i_port->getName()){
					continue;
				}
				i_protocol->Conect(i_port);
				onConnection(i_port, i_protocol);
			}
		}
		
		void addConnect(SerialPort* port, PortProtocol* protocol) {
			SerialStateLog(ame_Log_StartMethod, "addConnect",  "println", "with protocol");
			if(port == nullptr){
				return;
			}
			ports->addPointer(port);
			portProtocols->addPointer(protocol);
			if(protocol == nullptr){
				return;
			}
			protocol->attach(this);
			protocol->Conect(port);
			onConnection(port, protocol);
			SerialStateLog(ame_Log_EndMethod, "addConnect", "println", "");
		}
    
		void disconect(void) {
			for(int x = 0; x < portProtocols->getPosition(); x++){
				SerialPort* i_ports = ports->getByPosition(x);
				PortProtocol* i_protocol = portProtocols->getByPosition(x);
				if(i_ports == nullptr || i_protocol == nullptr){
					continue;
				}
				i_protocol->GlobalDisconect(i_ports);
				onDisconnection(i_ports, i_protocol);
			}
			onGlobalDisconnection();
		}
    
		void disconectDelete(void) {
			for(int x = 0; x < portProtocols->getPosition(); x++){
				SerialPort* i_ports = ports->getByPosition(x);
				PortProtocol* i_protocol = portProtocols->getByPosition(x);
				if(i_ports == nullptr || i_protocol == nullptr){
					continue;
				}
				i_protocol->GlobalDisconect(i_ports);
				onDisconnection(i_ports, i_protocol);
			}
			onGlobalDisconnection();
			ports->resetDelete();
			portProtocols->resetDelete();
		}
		
		void disconect(SerialPort* port) {
			int index = ports->getIndexByPointer(port);
			if(index == -1){
				return;
			}
			PortProtocol* i_protocol = portProtocols->getByPosition(index);
			if(i_protocol == nullptr){
				return;
			}
			i_protocol->Disconect(port);
		}
		
		void disconect(Note a_name) {
			for(int x = 0; x < portProtocols->getPosition(); x++){
				SerialPort* i_ports = ports->getByPosition(x);
				PortProtocol* i_protocol = portProtocols->getByPosition(x);
				if(i_ports == nullptr || i_protocol == nullptr){
					continue;
				}
				if(a_name != i_ports->getName()){
					continue;
				}
				i_protocol->GlobalDisconect(i_ports);
				onDisconnection(i_ports, i_protocol);
			}
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
		
		virtual void addGlobalConnectionStateChanger(MethodStateGlobalChanger changer){
			methodStateGlobalChanger_onConnection->addLValue(changer);
		}
		
		virtual void removeGlobalConnectionStateChanger(MethodStateGlobalChanger changer){
			methodStateGlobalChanger_onConnection->removeByLValue(changer);
		}
		
		virtual void removeDeleteGlobalConnectionStateChanger(MethodStateGlobalChanger changer){
			methodStateGlobalChanger_onConnection->removeDeleteByLValue(changer);
		}
		
		virtual void addConnectionStateChanger(MethodStateChanger changer){
			methodStateChanger_onConnection->addLValue(changer);
		}
		
		virtual void removeConnectionStateChanger(MethodStateChanger changer){
			methodStateChanger_onConnection->removeByLValue(changer);
		}
		
		virtual void removeDeleteConnectionStateChanger(MethodStateChanger changer){
			methodStateChanger_onConnection->removeDeleteByLValue(changer);
		}
		
		virtual void addGlobalDisconnectionStateChanger(MethodStateGlobalChanger changer){
			methodStateGlobalChanger_onDisconnection->addLValue(changer);
		}
		
		virtual void removeGlobalDisconnectionStateChanger(MethodStateGlobalChanger changer){
			methodStateGlobalChanger_onDisconnection->removeByLValue(changer);
		}
		
		virtual void removeDeleteGlobalDisconnectionStateChanger(MethodStateGlobalChanger changer){
			methodStateGlobalChanger_onDisconnection->removeDeleteByLValue(changer);
		}
		
		virtual void addDisconnectionStateChanger(MethodStateChanger changer){
			methodStateChanger_onDisconnection->addLValue(changer);
		}
		
		virtual void removeDisconnectionStateChanger(MethodStateChanger changer){
			methodStateChanger_onDisconnection->removeByLValue(changer);
		}
		
		virtual void removeDeleteDisconnectionStateChanger(MethodStateChanger changer){
			methodStateChanger_onDisconnection->removeDeleteByLValue(changer);
		}
		
		virtual cppObjectClass* getClass(){
			return Class<SerialState>::classType;
		}
		
		virtual bool ping(Note note){
		#if defined(ame_Windows)
			return false;
		#elif defined(ame_ArduinoIDE)
			#if defined(ame_GENERIC_ESP32)
			return false;
			// return WIFI.ping() == WL_PING_SUCCESS;
			#else
				return false;
			#endif
		#else
			return false;
		#endif
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
					SerialStateLog(ame_Log_Statement, "update",  "println", "serial != nullptr");
					serverProtocol->UpdateSerialPort(port);
				}
				serverProtocol->update(server, tpc);
			}
			for(int index = 0; index < ports->getPosition(); index++){
				SerialPort* port = ports->getByPosition(index);
				PortProtocol* portProtocol = portProtocols->getByPosition(index);
				if(port == nullptr || portProtocol == nullptr){
					SerialStateLog(ame_Log_Statement, "update",  "println", "port == nullptr || portProtocol == nullptr");
					continue;
				}
				if(!port->connected()){
					SerialStateLog(ame_Log_Statement, "update",  "println", "!port->connected()");
					portProtocol->UpdateDisconect(port);
					if(portProtocol->SafeDelete()){
						SerialStateLog(ame_Log_Statement, "update",  "println", "portProtocol->SafeDelete()");
						onDisconnection(port, portProtocol);
						portProtocols->removeDeleteByPosition(index);
						ports->removeDeleteByPosition(index);
						index--;
					}else{
						SerialStateLog(ame_Log_Statement, "update",  "println", "!portProtocol->SafeDelete()");
						onDisconnection(port, portProtocol);
						portProtocols->removeByPosition(index);
						ports->removeByPosition(index);
						index--;
					}
				}else{
					// SerialStateLog(ame_Log_Statement, "update",  "println", Note("index: ") + Note(index));
					// SerialStateLog(ame_Log_Statement, "update",  "println", Note("Port Name: ") + port->getName());
					if(port->available() > 0) {
						// Serial.println("port->available() > 0");
						SerialStateLog(ame_Log_Statement, "update",  "println", "port->available() > 0");
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
			
			// Serial.println("SerialState end update");
		}
		
	protected:
		List<Note>* broadMessages = nullptr;
		Map<int,Note>* clientMessages = nullptr;
		
		List<SerialServer>* servers = nullptr;
		List<ServerProtocol>* serverProtocols = nullptr;
		
		List<SerialPort>* ports = nullptr;
		List<PortProtocol>* portProtocols = nullptr;
		
		//StateChanger
		List<SerialConnectionStateChanger>* stateChanger = nullptr;
		
		List<MethodStateGlobalChanger>* methodStateGlobalChanger_onConnection = nullptr;
		List<MethodStateGlobalChanger>* methodStateGlobalChanger_onDisconnection = nullptr;
		
		List<MethodStateChanger>* methodStateChanger_onConnection = nullptr;
		List<MethodStateChanger>* methodStateChanger_onDisconnection = nullptr;
		
		bool hasInit = false;
};

}

#endif