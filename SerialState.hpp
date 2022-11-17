
#ifndef CONFIGURATION_SerialState_hpp
#define CONFIGURATION_SerialState_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_SerialState)
		#define SerialState_hpp

		#define IMPLEMENTATION_SerialState
		#define IMPLEMENTING_SerialState
	#else
		#if defined(DISABLE_IMPLEMENTATION_SerialState)
			#define IMPLEMENTATION_SerialState
			#define IMPLEMENTING_SerialState
		#endif
	#endif
#endif

#ifndef SerialState_hpp
#define SerialState_hpp
#define SerialState_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_SerialState
	#define IMPLEMENTATION_SerialState IMPLEMENTATION(public SerialState)
	#define IMPLEMENTING_SerialState IMPLEMENTING(public SerialState)
#endif

#include "SerialNetwork.hpp"

#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"

#ifdef SerialState_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define SerialStateLog(location,method,type,mns) ame_Log(this,location,"SerialState",method,type,mns)
	#define const_SerialStateLog(location,method,type,mns)
#else
	#ifdef SerialState_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define SerialStateLog(location,method,type,mns) ame_LogDebug(this,location,"SerialState",method,type)
		#define const_SerialStateLog(location,method,type,mns)
	#else
		#define SerialStateLog(location,method,type,mns)
		#define const_SerialStateLog(location,method,type,mns)
	#endif
#endif

namespace ame{

class SerialState IMPLEMENTATION_SerialNetwork {
    public:
		SerialState(){
			SerialStateLog(ame_Log_StartMethod, "Constructor", "println", "");
			SerialStateLog(ame_Log_EndMethod, "Constructor", "println", "");
		}
		virtual ~SerialState(){
			SerialStateLog(ame_Log_StartMethod, "Destructor", "println", "");
			SerialStateLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		virtual void instantSend(Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with Note as parameter");
			for(int x = 0; x < this->m_ports.getPosition(); x++){
				auto f_entry = this->m_ports.getMapEntryByPosition(x);
				SerialPort* f_ports = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_ports == nullptr || f_protocol == nullptr){
					return;
				}
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "trying to send port named: ");
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", f_ports->getName());
				f_protocol->InstantBroadcastMessage(f_ports, mns);
			}
			SerialStateLog(ame_Log_EndMethod, "instantSend", "println", "");
		}

		virtual void instantSend(ByteArray a_message){}

		virtual void instantSend(int index, Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with int and Note as parameter");
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", Note("index: ") + Note(index));
			auto f_entry = m_ports.getMapEntryByPosition(index);
			SerialPort* f_ports = f_entry.getKey();
			PortProtocol* i_protocol = f_entry.getValue();
			if(f_ports == nullptr || i_protocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "sending port named: ");
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", f_ports->getName());
			i_protocol->InstantPrivateMessage(f_ports, mns);
			SerialStateLog(ame_Log_EndMethod, "instantSend", "println", "");
		}

		virtual void instantPortSend(SerialPort* a_port, Note mns){
			SerialStateLog(ame_Log_Statement, "instantPortSend",  "println", "method with serialport and Note as parameter");
			SerialPort* port = a_port;
			PortProtocol* protocol = this->getPortProtocol(a_port);
			if(port == nullptr || protocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantPortSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			protocol->InstantPrivateMessage(port, mns);
			SerialStateLog(ame_Log_EndMethod, "instantPortSend", "println", "");
		}

		virtual void instantSend(Note name, Note mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with a Note and a Note as parameter");
			SerialPort* port = this->getSerialPort(name);
			PortProtocol* portProtocol = m_ports.getValueByPointer(port);
			if(port == nullptr || portProtocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			portProtocol->InstantPrivateMessage(port, mns);
			SerialStateLog(ame_Log_EndMethod, "instantSend", "println", "");
		}

		virtual void instantByteArraySend(Note name, ByteArray array){
			SerialStateLog(ame_Log_Statement, "instantByteArraySend",  "println", "method with a Note and a Note as parameter");
			SerialPort* port = this->getSerialPort(name);
			PortProtocol* portProtocol = m_ports.getValueByPointer(port);
			if(port == nullptr || portProtocol == nullptr){
				SerialStateLog(ame_Log_Statement, "instantByteArraySend",  "println", "port == nullptr || protocol == nullptr");
				return;
			}
			portProtocol->InstantPrivateByteArrayMessage(port, array);
			SerialStateLog(ame_Log_EndMethod, "instantByteArraySend", "println", "");
		}

		virtual void instantSend(Message mns){
			SerialStateLog(ame_Log_Statement, "instantSend",  "println", "method with Message as parameter");
			for(int x = 0; x < this->m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_ports = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_ports == nullptr || f_protocol == nullptr){
					SerialStateLog(ame_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
					return;
				}
				if(mns.id() == -1){
					SerialStateLog(ame_Log_Statement, "instantSend",  "println", "portProtocols InstantBroadcastMessage");
					f_protocol->InstantBroadcastMessage(f_ports, mns.text());
				}else{
					SerialStateLog(ame_Log_Statement, "instantSend",  "println", "portProtocols InstantPrivateMessage");
					f_protocol->InstantPrivateMessage(f_ports, mns.text());
				}
			}
			SerialStateLog(ame_Log_EndMethod, "instantSend", "println", "");
		}

		virtual void send(Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with Note as parameter");
			m_broadMessages.addLValue(mns);
			SerialStateLog(ame_Log_EndMethod, "send", "println", "");
		}

		virtual void send(ByteArray a_message){}

		virtual void send(int index, Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with a int and a Note as parameters");
			SerialStateLog(ame_Log_Statement, "send",  "println", Note("index: ") + Note(index));
			m_clientMessages.addPointers(new int(index), new Note(mns));
			SerialStateLog(ame_Log_EndMethod, "send", "println", "");
		}

		virtual void send(Note name, Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with 2 Notes as parameters");
			for(int x = 0 ; x < this->m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				if(f_port == nullptr){
					continue;
				}
				if(f_port->getName() == name){
					m_clientMessages.addPointers(new int(x), new Note(mns));
					SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("adding"));
				}
			}
			SerialStateLog(ame_Log_EndMethod, "send", "println", "");
		}

		virtual void send(Note a_name, ByteArray a_message){}

		virtual void send(SerialPort* port, Note mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with 2 Notes as parameters");
			for(int x = 0 ; x < this->m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				if(f_port == port){
					m_clientMessages.addPointers(new int(x), new Note(mns));
					SerialStateLog(ame_Log_Statement, "send",  "println", ame_String("adding"));
				}
			}
			SerialStateLog(ame_Log_EndMethod, "send", "println", "");
		}

		virtual void send(Message mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with Message as parameter");
			if(mns.id() == -1){
				SerialStateLog(ame_Log_Statement, "send",  "println", "no id");
				m_broadMessages.addLValue(mns.text());
			}else{
				SerialStateLog(ame_Log_Statement, "send",  "println", "with id");
				m_clientMessages.addPointers(new int(mns.id()), new Note(mns.text()));
			}
			SerialStateLog(ame_Log_EndMethod, "send", "println", "");
		}

		virtual void send(Message* mns){
			SerialStateLog(ame_Log_Statement, "send",  "println", "method with Message pointer as parameter");
			if(mns->id() == -1){
				SerialStateLog(ame_Log_Statement, "send",  "println", "no id");
				m_broadMessages.addLValue(mns->text());
			}else{
				//SerialStateLog(ame_Log_Statement, "send",  "println", "with id");
				m_clientMessages.addPointers(new int(mns->id()), new Note(mns->text()));
			}
			SerialStateLog(ame_Log_EndMethod, "send", "println", "");
		}

		virtual bool isConnected(Note namae){
			SerialStateLog(ame_Log_EndMethod, "isConnected", "println", "");
			for(int x = 0; x < this->m_ports.getPosition(); x++){
				SerialPort* i_port = this->m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == namae){
					return i_port->connected();
				}
			}
			SerialStateLog(ame_Log_EndMethod, "isConnected", "println", "");
			return false;
		}

		virtual void connect() {
			SerialStateLog(ame_Log_EndMethod, "connect", "println", "");
			for(int x = 0; x < this->m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_port == nullptr || f_protocol == nullptr){
					continue;
				}
				f_protocol->GlobalConect(f_port);
				onConnection(f_port, f_protocol);
			}
			onGlobalConnection();
			SerialStateLog(ame_Log_EndMethod, "connect", "println", "");
		}

		virtual void connect(SerialPort* port) {
			SerialStateLog(ame_Log_EndMethod, "connect", "println", "");
			PortProtocol* i_protocol = this->m_ports.getValueByPointer(port);
			if(port == nullptr || i_protocol == nullptr){
				return;
			}
			i_protocol->Conect(port);
			onConnection(port, i_protocol);
			SerialStateLog(ame_Log_EndMethod, "connect", "println", "");
		}

		virtual void connect(Note a_name) {
			SerialStateLog(ame_Log_EndMethod, "connect", "println", "");
			for(int x = 0; x < this->m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_port == nullptr || f_protocol == nullptr){
					continue;
				}
				if(a_name != f_port->getName()){
					continue;
				}
				f_protocol->Conect(f_port);
				onConnection(f_port, f_protocol);
			}
			SerialStateLog(ame_Log_EndMethod, "connect", "println", "");
		}

		virtual void addConnect(SerialPort* port, PortProtocol* protocol) {
			SerialStateLog(ame_Log_StartMethod, "addConnect",  "println", "with protocol");
			if(port == nullptr){
				return;
			}
			this->m_ports.addPointers(port, protocol);
			if(protocol == nullptr){
				return;
			}
			protocol->initialize(this);
			protocol->Conect(port);
			onConnection(port, protocol);
			SerialStateLog(ame_Log_EndMethod, "addConnect", "println", "");
		}

		virtual void disconect() {
			SerialStateLog(ame_Log_EndMethod, "disconect", "println", "");
			for(int x = 0; x < m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_port == nullptr || f_protocol == nullptr){
					continue;
				}
				f_protocol->GlobalDisconect(f_port);
				onDisconnection(f_port, f_protocol);
			}
			onGlobalDisconnection();
			SerialStateLog(ame_Log_EndMethod, "disconect", "println", "");
		}

		virtual void disconectDelete() {
			SerialStateLog(ame_Log_EndMethod, "disconectDelete", "println", "");
			for(int x = 0; x < m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_port == nullptr || f_protocol == nullptr){
					continue;
				}
				f_protocol->GlobalDisconect(f_port);
				onDisconnection(f_port, f_protocol);
			}
			onGlobalDisconnection();
			this->m_ports.resetDelete();
			SerialStateLog(ame_Log_EndMethod, "disconectDelete", "println", "");
		}

		virtual void disconect(SerialPort* port) {
			SerialStateLog(ame_Log_EndMethod, "disconect", "println", "");
			PortProtocol* i_protocol = m_ports.getValueByPointer(port);
			if(i_protocol == nullptr){
				return;
			}
			i_protocol->Disconect(port);
			SerialStateLog(ame_Log_EndMethod, "disconect", "println", "");
		}

		virtual void disconect(Note a_name) {
			SerialStateLog(ame_Log_EndMethod, "disconect", "println", "");
			for(int x = 0; x < m_ports.getPosition(); x++){
				auto f_entry = m_ports.getMapEntryByPosition(x);
				SerialPort* f_port = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				if(f_port == nullptr || f_protocol == nullptr){
					continue;
				}
				if(a_name != f_port->getName()){
					continue;
				}
				f_protocol->GlobalDisconect(f_port);
				onDisconnection(f_port, f_protocol);
			}
			SerialStateLog(ame_Log_EndMethod, "disconect", "println", "");
		}

		virtual bool ping(Note note){
			SerialStateLog(ame_Log_EndMethod, "ping", "println", "");
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
			SerialStateLog(ame_Log_EndMethod, "ping", "println", "");
		}

		virtual void updateState(float tpc){
			for(int x = 0; x < this->m_servers.getPosition(); x++){
				auto f_entry = m_servers.getMapEntryByPosition(x);
				SerialServer* server = f_entry.getKey();
				ServerProtocol* serverProtocol = f_entry.getValue();
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
			for(int index = 0; index < this->m_ports.getPosition(); index++){
				auto f_entry = this->m_ports.getMapEntryByPosition(index);
				SerialPort* port = f_entry.getKey();
				PortProtocol* portProtocol = f_entry.getValue();
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
						this->m_ports.removeDeleteByPosition(index);
						index--;
					}else{
						SerialStateLog(ame_Log_Statement, "update",  "println", "!portProtocol->SafeDelete()");
						onDisconnection(port, portProtocol);
						this->m_ports.removeByPosition(index);
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
					for(int x = 0; x < m_broadMessages.getPosition(); x++){
						portProtocol->BroadcastMessage(port, *m_broadMessages.getByPosition(x));
					}
					portProtocol->update(port,tpc);
				}
			}
			m_broadMessages.resetDelete();

			for(int x = 0; x < m_clientMessages.getPosition(); x++){
				int index = *m_clientMessages.getKeyByPosition(x);
				auto f_entry = m_ports.getMapEntryByPosition(index);
				SerialPort* port = f_entry.getKey();
				PortProtocol* portProtocol = f_entry.getValue();
				if(port == nullptr || portProtocol == nullptr){
					continue;
				}
				portProtocol->PrivateMessage(port, *m_clientMessages.getValueByPosition(x));
			}
			m_clientMessages.resetDelete();
		}
			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return Class<SerialState>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialState>::getClass() || AppState::instanceof(cls);
		}
		#endif

	protected:
		PrimitiveList<Note> m_broadMessages;
		PrimitiveMap<int,Note> m_clientMessages;
};

}

#endif
