
#ifndef SerialState_hpp
	#define SerialState_hpp

	#include "pankey.hpp"

	#include "SerialNetwork.hpp"

	#include "SerialServer.hpp"
	#include "ServerProtocol.hpp"

	#include "SerialPort.hpp"
	#include "PortProtocol.hpp"

	#include "SerialConnectionStateChanger.hpp"
	#include "InvokeList.hpp"

	#include "PrimitiveRawList.hpp"
	#include "PrimitiveRawMap.hpp"

	#ifdef SerialState_LogApp
		#include "pankey_Logger.hpp"
		#define SerialStateLog(location,method,type,mns) pankey_Log((void*)this,location,"SerialState",method,type,mns)
	#else
		#define SerialStateLog(location,method,type,mns) 
	#endif

	namespace pankey{

		using serialport = obj<SerialPort>;
		using portprotocol = obj<PortProtocol>;

		using serialserver = obj<SerialServer>;
		using serverprotocol = obj<ServerProtocol>;

		using serialconnectionstatechanger = obj<SerialConnectionStateChanger>;

		class SerialState : public SerialNetwork{
			public:
				
				SerialState(){
					SerialStateLog(pankey_Log_StartMethod, "Constructor", "println", "");
					SerialStateLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				SerialState(const SerialState& a_serial){
					SerialStateLog(pankey_Log_StartMethod, "Constructor", "println", "const SerialState&");
					m_commands = a_serial.m_commands;
					m_methods = a_serial.m_methods;
					m_app_commands = a_serial.m_app_commands;
					m_app_methods = a_serial.m_app_methods;
					m_broadMessages = a_serial.m_broadMessages;
					m_clientMessages = a_serial.m_clientMessages;
					m_servers = a_serial.m_servers;
					m_ports = a_serial.m_ports;
					m_methodStateChanger_onConnection = a_serial.m_methodStateChanger_onConnection;
					m_methodStateChanger_onDisconnection = a_serial.m_methodStateChanger_onDisconnection;
					m_stateChanger = a_serial.m_stateChanger;
					m_methodStateGlobalChanger_onConnection = a_serial.m_methodStateGlobalChanger_onConnection;
					m_methodStateGlobalChanger_onDisconnection = a_serial.m_methodStateGlobalChanger_onDisconnection;
					SerialStateLog(pankey_Log_EndMethod, "Constructor", "println", "");
				}
				
				virtual ~SerialState(){
					SerialStateLog(pankey_Log_StartMethod, "Destructor", "println", "");
					SerialStateLog(pankey_Log_EndMethod, "Destructor", "println", "");
				}

				//The onConnections methods are only used if the port and the protocol are not nullptr

				virtual void onGlobalConnection(){
					SerialStateLog(pankey_Log_StartMethod, "onGlobalConnection", "println", "");
					invokeAll<>(m_methodStateGlobalChanger_onConnection);
					invokeAll<SerialConnectionStateChanger>(m_stateChanger, &SerialConnectionStateChanger::onGlobalConnection);
					SerialStateLog(pankey_Log_EndMethod, "onGlobalConnection", "println", "");
				}

				virtual void onGlobalDisconnection(){
					SerialStateLog(pankey_Log_StartMethod, "onGlobalDisconnection", "println", "");
					invokeAll<>(m_methodStateGlobalChanger_onDisconnection);
					invokeAll<SerialConnectionStateChanger>(m_stateChanger, &SerialConnectionStateChanger::onGlobalDisconnection);
					SerialStateLog(pankey_Log_EndMethod, "onGlobalDisconnection", "println", "");
				}

				virtual void onConnection(){
					SerialStateLog(pankey_Log_StartMethod, "onConnection", "println", "");
					for(int x_ports = 0; x_ports < m_ports.length(); x_ports++){
						serialport f_ports = m_ports.getKey(x_ports);
						portprotocol f_protocol = m_ports.getValue(x_ports);
						invokeAll<>(m_methodStateChanger_onConnection, f_ports, f_protocol);
						invokeAll<SerialConnectionStateChanger,serialport,portprotocol>(m_stateChanger, &SerialConnectionStateChanger::onConnection, f_ports, f_protocol);
					}
					SerialStateLog(pankey_Log_EndMethod, "onConnection", "println", "");
				}

				virtual void onDisconnection(){
					SerialStateLog(pankey_Log_StartMethod, "onDisconnection", "println", "");
					for(int x_ports = 0; x_ports < m_ports.length(); x_ports++){
						serialport f_ports = m_ports.getKey(x_ports);
						portprotocol f_protocol = m_ports.getValue(x_ports);
						invokeAll<>(m_methodStateChanger_onDisconnection, f_ports, f_protocol);
						invokeAll<SerialConnectionStateChanger,serialport,portprotocol>(m_stateChanger, &SerialConnectionStateChanger::onDisconnection, f_ports, f_protocol);
					}
					SerialStateLog(pankey_Log_EndMethod, "onDisconnection", "println", "");
				}

				virtual void onConnection(serialport a_serialport, portprotocol a_portprotocol){
					SerialStateLog(pankey_Log_StartMethod, "onConnection", "println", "");
					invokeAll<>(m_methodStateChanger_onConnection, a_serialport, a_portprotocol);
					invokeAll<SerialConnectionStateChanger,serialport,portprotocol>(m_stateChanger, &SerialConnectionStateChanger::onConnection, a_serialport, a_portprotocol);
					SerialStateLog(pankey_Log_EndMethod, "onConnection", "println", "");
				}

				virtual void onDisconnection(serialport a_serialport, portprotocol a_portprotocol){
					SerialStateLog(pankey_Log_StartMethod, "onDisconnection", "println", "");
					invokeAll<>(m_methodStateChanger_onDisconnection, a_serialport, a_portprotocol);
					invokeAll<SerialConnectionStateChanger,serialport,portprotocol>(m_stateChanger, &SerialConnectionStateChanger::onDisconnection, a_serialport, a_portprotocol);
					SerialStateLog(pankey_Log_EndMethod, "onDisconnection", "println", "");
				}

				virtual void addSerialServer(serialserver a_serial, serverprotocol a_protocol){
					SerialStateLog(pankey_Log_StartMethod, "addSerialServer", "println", "");
					m_servers.add(a_serial, a_protocol);
					if(this->hasInitialize() && !a_serial.isNull()){
						a_serial->begin();
					}
					SerialStateLog(pankey_Log_EndMethod, "addSerialServer", "println", "");
				}

				virtual serialserver getSerialServer(int index){
					SerialStateLog(pankey_Log_StartMethod, "getSerialServer", "println", "int index");
					SerialStateLog(pankey_Log_EndMethod, "getSerialServer", "println", "");
					return m_servers.get(index);
				}

				virtual int getSerialServerSize(){
					return m_servers.length();
				}

				virtual bool containSerialServer(serialserver a_server){
					return m_servers.containByPointer(a_server);
				}

				virtual bool containSerialServer(Note a_name){
					for(int x = 0; x < m_servers.length(); x++){
						serialserver i_server = m_servers.get(x);
						if(i_server.isNull()){
							continue;
						}
						if(i_server->getName() == a_name){
							return true;
						}
					}
					return false;
				}

				virtual void removeSerialServer(serialserver a_server){
					SerialStateLog(pankey_Log_StartMethod, "removeSerialServer", "println", "");
					m_servers.removeByPointer(a_server);
					SerialStateLog(pankey_Log_EndMethod, "removeSerialServer", "println", "");
				}

				virtual void removeSerialServer(int index){
					SerialStateLog(pankey_Log_StartMethod, "removeSerialServer", "println", "");
					m_servers.remove(index);
					SerialStateLog(pankey_Log_EndMethod, "removeSerialServer", "println", "");
				}

				virtual void removeAllSerialServer(){
					SerialStateLog(pankey_Log_StartMethod, "removeAllSerialServer", "println", "");
					m_servers.clear();
					SerialStateLog(pankey_Log_EndMethod, "removeAllSerialServer", "println", "");
				}

				virtual serverprotocol getServerProtocol(int index){
					return m_servers.getValue(index);
				}

				virtual serverprotocol getServerProtocol(serialserver a_server){
					return m_servers.getValueByPointer(a_server);
				}

				virtual void addSerialPort(serialport a_port, portprotocol a_protocol){
					SerialStateLog(pankey_Log_StartMethod, "addSerialPort",  "println", "serialport a_port, portprotocol a_protocol");
					SerialStateLog(pankey_Log_Statement, "addSerialPort",  "println", "is port null:");
					SerialStateLog(pankey_Log_Statement, "addSerialPort",  "println", a_port.isNull());
					SerialStateLog(pankey_Log_Statement, "addSerialPort",  "println", "is protocol null:");
					SerialStateLog(pankey_Log_Statement, "addSerialPort",  "println", a_protocol.isNull());
					SerialStateLog(pankey_Log_EndMethod, "addSerialPort", "println", "");
					m_ports.add(a_port, a_protocol);
				}

				virtual OMap<SerialPort,PortProtocol> getSerialPorts(){
					return m_ports;
				}

				virtual serialport getSerialPort(Note a_name){
					for(int x = 0; x < m_ports.length(); x++){
						serialport i_port = m_ports.getValue(x);
						if(i_port.isNull()){
							continue;
						}
						if(i_port->getName() == a_name){
							return i_port;
						}
					}
					return serialport();
				}

				virtual serialport getSerialPort(int index){
					return m_ports.getKey(index);
				}

				virtual int getSerialPortSize(){
					return m_ports.length();
				}

				virtual bool containSerialPort(serialport a_port){
					SerialStateLog(pankey_Log_StartMethod, "containSerialPort", "println", "");
					SerialStateLog(pankey_Log_EndMethod, "containSerialPort", "println", "");
					return m_ports.containKeyByPointer(a_port);
				}

				virtual bool containSerialPort(Note a_port){
					for(int x = 0; x < m_ports.length(); x++){
						serialport i_port = m_ports.getKey(x);
						if(i_port.isNull()){
							continue;
						}
						if(i_port->getName() == a_port){
							return true;
						}
					}
					return false;
				}

				virtual void removeSerialPort(int index){
					SerialStateLog(pankey_Log_StartMethod, "removeSerialPort",  "println", "with protocol");
					m_ports.remove(index);
					SerialStateLog(pankey_Log_EndMethod, "removeSerialPort", "println", "");
				}

				virtual void removeSerialPort(serialport a_port){
					SerialStateLog(pankey_Log_StartMethod, "removeSerialPort",  "println", "with protocol");
					m_ports.removeKeyByPointer(a_port);
					SerialStateLog(pankey_Log_EndMethod, "removeSerialPort", "println", "");
				}

				virtual void clearSerialPorts(){
					SerialStateLog(pankey_Log_StartMethod, "clearSerialPort",  "println", "with protocol");
					m_ports.clear();
					SerialStateLog(pankey_Log_EndMethod, "clearSerialPort", "println", "");
				}

				virtual portprotocol getPortProtocol(int index){
					return m_ports.getValue(index);
				}

				virtual portprotocol getPortProtocol(serialport a_port){
					return m_ports.getValueByPointer(a_port);
				}

				virtual void addConnectionStateChanger(serialconnectionstatechanger changer){
					m_stateChanger.add(changer);
				}

				virtual bool removeConnectionStateChanger(serialconnectionstatechanger changer){
					return m_stateChanger.removeByPointer(changer);
				}

				virtual void addGlobalConnectionStateChanger(InvokeMethod<> changer){
					m_methodStateGlobalChanger_onConnection.add(changer);
				}

				virtual void removeGlobalConnectionStateChanger(InvokeMethod<> changer){
					m_methodStateGlobalChanger_onConnection.remove(changer);
				}

				virtual void addGlobalDisconnectionStateChanger(InvokeMethod<> changer){
					m_methodStateGlobalChanger_onDisconnection.add(changer);
				}

				virtual void removeGlobalDisconnectionStateChanger(InvokeMethod<> changer){
					m_methodStateGlobalChanger_onDisconnection.remove(changer);
				}

				virtual void addConnectionStateChanger(InvokeMethod<serialport,portprotocol> changer){
					m_methodStateChanger_onConnection.add(changer);
				}

				virtual void removeConnectionStateChanger(InvokeMethod<serialport,portprotocol> changer){
					m_methodStateChanger_onConnection.remove(changer);
				}

				virtual void addDisconnectionStateChanger(InvokeMethod<serialport,portprotocol> changer){
					m_methodStateChanger_onDisconnection.add(changer);
				}

				virtual void removeDisconnectionStateChanger(InvokeMethod<serialport,portprotocol> changer){
					m_methodStateChanger_onDisconnection.remove(changer);
				}

				virtual void instantSend(Note mns){
					SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "method with Note as parameter");
					for(int x = 0; x < this->m_ports.length(); x++){
						serialport f_ports = m_ports.getKey(x);
						portprotocol f_protocol = m_ports.getValue(x);
						if(f_ports.isNull() || f_protocol.isNull()){
							return;
						}
						SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "trying to send port named: ");
						SerialStateLog(pankey_Log_Statement, "instantSend",  "println", f_ports->getName());
						f_protocol->InstantBroadcastMessage(f_ports, mns);
					}
					SerialStateLog(pankey_Log_EndMethod, "instantSend", "println", "");
				}

				virtual void instantSend(int index, Note mns){
					SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "method with int and Note as parameter");
					SerialStateLog(pankey_Log_Statement, "instantSend",  "println", Note("index: ") + Note(index));
					serialport i_port = m_ports.getKey(index);
					portprotocol i_protocol = m_ports.getValue(index);
					if(i_port.isNull() || i_protocol.isNull()){
						SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
						return;
					}
					SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "sending port named: ");
					SerialStateLog(pankey_Log_Statement, "instantSend",  "println", i_port->getName());
					i_protocol->InstantPrivateMessage(i_port, mns);
					SerialStateLog(pankey_Log_EndMethod, "instantSend", "println", "");
				}

				virtual void instantPortSend(serialport a_port, Note mns){
					SerialStateLog(pankey_Log_Statement, "instantPortSend",  "println", "method with serialport and Note as parameter");
					portprotocol i_protocol = this->getPortProtocol(a_port);
					if(a_port.isNull() || i_protocol.isNull()){
						SerialStateLog(pankey_Log_Statement, "instantPortSend",  "println", "port == nullptr || protocol == nullptr");
						return;
					}
					i_protocol->InstantPrivateMessage(a_port, mns);
					SerialStateLog(pankey_Log_EndMethod, "instantPortSend", "println", "");
				}

				virtual void instantSend(Note name, Note mns){
					SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "method with a Note and a Note as parameter");
					serialport i_port = this->getSerialPort(name);
					portprotocol i_protocol = m_ports.getValueByPointer(i_port);
					if(i_port.isNull() || i_protocol.isNull()){
						SerialStateLog(pankey_Log_Statement, "instantSend",  "println", "port == nullptr || protocol == nullptr");
						return;
					}
					i_protocol->InstantPrivateMessage(i_port, mns);
					SerialStateLog(pankey_Log_EndMethod, "instantSend", "println", "");
				}

				virtual void send(Note mns){
					SerialStateLog(pankey_Log_Statement, "send",  "println", "method with Note as parameter");
					m_broadMessages.add(mns);
					SerialStateLog(pankey_Log_EndMethod, "send", "println", "");
				}

				virtual void send(Note name, Note mns){
					SerialStateLog(pankey_Log_Statement, "send",  "println", "method with 2 Notes as parameters");
					for(int x = 0 ; x < this->m_ports.length(); x++){
						serialport f_port = m_ports.getKey(x);
						if(f_port.isNull()){
							continue;
						}
						if(f_port->getName() == name){
							m_clientMessages.addPointers(new int(x), new Note(mns));
							SerialStateLog(pankey_Log_Statement, "send",  "println", pankey_String("adding"));
						}
					}
					SerialStateLog(pankey_Log_EndMethod, "send", "println", "");
				}

				virtual void send(serialport port, Note mns){
					SerialStateLog(pankey_Log_Statement, "send",  "println", "method with 2 Notes as parameters");
					for(int x = 0 ; x < this->m_ports.length(); x++){
						serialport f_port = m_ports.getKey(x);
						if(f_port == port){
							m_clientMessages.addPointers(new int(x), new Note(mns));
							SerialStateLog(pankey_Log_Statement, "send",  "println", pankey_String("adding"));
						}
					}
					SerialStateLog(pankey_Log_EndMethod, "send", "println", "");
				}

				virtual bool isConnected(Note namae){
					SerialStateLog(pankey_Log_EndMethod, "isConnected", "println", "");
					for(int x = 0; x < this->m_ports.length(); x++){
						serialport i_port = this->m_ports.getKey(x);
						if(i_port.isNull()){
							continue;
						}
						if(i_port->getName() == namae){
							return i_port->connected();
						}
					}
					SerialStateLog(pankey_Log_EndMethod, "isConnected", "println", "");
					return false;
				}

				virtual void connect() {
					SerialStateLog(pankey_Log_EndMethod, "connect", "println", "");
					for(int x = 0; x < this->m_ports.length(); x++){
						serialport f_port = m_ports.getKey(x);
						portprotocol f_protocol = m_ports.getValue(x);
						if(f_port.isNull() || f_protocol.isNull()){
							continue;
						}
						f_protocol->GlobalConect(f_port);
						onConnection(f_port, f_protocol);
					}
					onGlobalConnection();
					SerialStateLog(pankey_Log_EndMethod, "connect", "println", "");
				}

				virtual void connect(serialport port) {
					SerialStateLog(pankey_Log_EndMethod, "connect", "println", "");
					portprotocol i_protocol = this->m_ports.getValueByPointer(port);
					if(port.isNull() || i_protocol.isNull()){
						return;
					}
					i_protocol->Conect(port);
					onConnection(port, i_protocol);
					SerialStateLog(pankey_Log_EndMethod, "connect", "println", "");
				}

				virtual void connect(Note a_name) {
					SerialStateLog(pankey_Log_EndMethod, "connect", "println", "");
					for(int x = 0; x < this->m_ports.length(); x++){
						serialport f_port = m_ports.getKey(x);
						portprotocol f_protocol = m_ports.getValue(x);
						if(f_port.isNull() || f_protocol.isNull()){
							continue;
						}
						if(a_name != f_port->getName()){
							continue;
						}
						f_protocol->Conect(f_port);
						onConnection(f_port, f_protocol);
					}
					SerialStateLog(pankey_Log_EndMethod, "connect", "println", "");
				}

				virtual void addConnect(serialport port, portprotocol protocol) {
					SerialStateLog(pankey_Log_StartMethod, "addConnect",  "println", "with protocol");
					if(port.isNull()){
						return;
					}
					this->m_ports.add(port, protocol);
					if(protocol.isNull()){
						return;
					}
					protocol->Conect(port);
					onConnection(port, protocol);
					SerialStateLog(pankey_Log_EndMethod, "addConnect", "println", "");
				}

				virtual void disconect() {
					SerialStateLog(pankey_Log_EndMethod, "disconect", "println", "");
					for(int x = 0; x < m_ports.length(); x++){
						serialport f_port = m_ports.getKey(x);
						portprotocol f_protocol = m_ports.getValue(x);
						if(f_port.isNull() || f_protocol.isNull()){
							continue;
						}
						f_protocol->GlobalDisconect(f_port);
						onDisconnection(f_port, f_protocol);
					}
					onGlobalDisconnection();
					SerialStateLog(pankey_Log_EndMethod, "disconect", "println", "");
				}

				virtual void disconect(serialport port) {
					SerialStateLog(pankey_Log_EndMethod, "disconect", "println", "");
					portprotocol i_protocol = m_ports.getValueByPointer(port);
					if(i_protocol.isNull()){
						return;
					}
					i_protocol->Disconect(port);
					SerialStateLog(pankey_Log_EndMethod, "disconect", "println", "");
				}

				virtual void disconect(Note a_name) {
					SerialStateLog(pankey_Log_EndMethod, "disconect", "println", "");
					for(int x = 0; x < m_ports.length(); x++){
						serialport f_port = m_ports.getKey(x);
						portprotocol f_protocol = m_ports.getValue(x);
						if(f_port.isNull() || f_protocol.isNull()){
							continue;
						}
						if(a_name != f_port->getName()){
							continue;
						}
						f_protocol->GlobalDisconect(f_port);
						onDisconnection(f_port, f_protocol);
					}
					SerialStateLog(pankey_Log_EndMethod, "disconect", "println", "");
				}

				virtual bool ping(Note note){
					SerialStateLog(pankey_Log_StartMethod, "ping", "println", "");
					SerialStateLog(pankey_Log_EndMethod, "ping", "println", "");
					#ifdef pankey_Windows
						return false;
					#endif
					#ifdef pankey_ArduinoIDE
						#ifdef pankey_GENERIC_ESP32
						return false;
						// return WIFI.ping() == WL_PING_SUCCESS;
						#else
							return false;
						#endif
					#else
						return false;
					#endif
				}

				virtual void initializeState(Application& a_app){
					SerialStateLog(pankey_Log_StartMethod, "initializeState", "println", "");
					for(int x = 0; x < this->m_servers.length(); x++){
						SerialStateLog(pankey_Log_Statement, "updateState",  "println", "server iteration");
						SerialStateLog(pankey_Log_Statement, "updateState",  "println", x);
						serialserver i_server = m_servers.getKey(x);
						if(!i_server.isNull()){
							i_server->begin();
						}
					}
					SerialStateLog(pankey_Log_EndMethod, "initializeState", "println", "");
				}

				virtual void updateState(Application& a_app, long a_tpc){
					SerialStateLog(pankey_Log_StartMethod, "updateState",  "println", "");
					SerialStateLog(pankey_Log_Statement, "updateState",  "println", "server length");
					SerialStateLog(pankey_Log_Statement, "updateState",  "println", this->m_servers.length());
					for(int x = 0; x < this->m_servers.length(); x++){
						SerialStateLog(pankey_Log_Statement, "updateState",  "println", "server iteration");
						SerialStateLog(pankey_Log_Statement, "updateState",  "println", x);
						serialserver server = m_servers.getKey(x);
						serverprotocol serverProtocol = m_servers.getValue(x);
						if(server.isNull() || serverProtocol.isNull()){
							continue;
						}
						serialport port = serverProtocol->accept(server);
						if(!port.isNull()){
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", "serial != nullptr");
							serverProtocol->UpdateSerialPort(port);
							if(!serverProtocol->isPortManaged()){
								this->addSerialPort(port, serverProtocol->createPortProtocol());
							}
						}
						serverProtocol->update(server, a_tpc);
					}
					SerialStateLog(pankey_Log_Statement, "updateState",  "println", "port length");
					SerialStateLog(pankey_Log_Statement, "updateState",  "println", this->m_ports.length());
					for(int index = 0; index < this->m_ports.length(); index++){
						serialport port = m_ports.getKey(index);
						portprotocol portProtocol = m_ports.getValue(index);
						if(port.isNull() || portProtocol.isNull()){
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", "port == nullptr || portProtocol == nullptr");
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", "is port null:");
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", port.isNull());
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", "is protocol null:");
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", portProtocol.isNull());
							continue;
						}
						if(!port->connected()){
							SerialStateLog(pankey_Log_Statement, "updateState",  "println", "!port->connected()");
							portProtocol->UpdateDisconect(port);
							onDisconnection(port, portProtocol);
							this->m_ports.remove(index);
							index--;
						}else{
							// SerialStateLog(pankey_Log_Statement, "update",  "println", Note("index: ") + Note(index));
							// SerialStateLog(pankey_Log_Statement, "update",  "println", Note("Port Name: ") + port->getName());
							if(port->available() > 0) {
								SerialStateLog(pankey_Log_Statement, "updateState",  "println", "port->available() > 0");
								Note i_message = portProtocol->Read(port);
								SerialStateLog(pankey_Log_Statement, "updateState",  "println", "incoming message:");
								SerialStateLog(pankey_Log_Statement, "updateState",  "println", i_message);
								if(!i_message.isEmpty()){
									this->DeliverMessage(a_app, i_message);
								}
							}
							for(int x = 0; x < m_broadMessages.getPosition(); x++){
								portProtocol->BroadcastMessage(port, *m_broadMessages.getByPosition(x));
							}
							portProtocol->update(port, a_tpc);
						}
					}
					m_broadMessages.resetDelete();

					for(int x = 0; x < m_clientMessages.getPosition(); x++){
						int index = *m_clientMessages.getKeyByPosition(x);
						serialport port = m_ports.getKey(x);
						portprotocol portProtocol = m_ports.getValue(x);
						if(port.isNull() || portProtocol.isNull()){
							continue;
						}
						portProtocol->PrivateMessage(port, *m_clientMessages.getValueByPosition(x));
					}
					m_clientMessages.resetDelete();
					SerialStateLog(pankey_Log_EndMethod, "updateState",  "println", "");
				}
				
				virtual void operator=(const SerialState& a_serial){
					SerialStateLog(pankey_Log_StartMethod, "operator=", "println", "const SerialState&");
					m_commands = a_serial.m_commands;
					m_methods = a_serial.m_methods;
					m_app_commands = a_serial.m_app_commands;
					m_app_methods = a_serial.m_app_methods;
					m_broadMessages = a_serial.m_broadMessages;
					m_clientMessages = a_serial.m_clientMessages;
					m_servers = a_serial.m_servers;
					m_ports = a_serial.m_ports;
					m_methodStateChanger_onConnection = a_serial.m_methodStateChanger_onConnection;
					m_methodStateChanger_onDisconnection = a_serial.m_methodStateChanger_onDisconnection;
					m_stateChanger = a_serial.m_stateChanger;
					m_methodStateGlobalChanger_onConnection = a_serial.m_methodStateGlobalChanger_onConnection;
					m_methodStateGlobalChanger_onDisconnection = a_serial.m_methodStateGlobalChanger_onDisconnection;
					SerialStateLog(pankey_Log_EndMethod, "operator=", "println", "");
				}

			protected:
				PrimitiveRawList<Note> m_broadMessages;
				PrimitiveRawMap<int,Note> m_clientMessages;

				OMap<SerialServer,ServerProtocol> m_servers;
				OMap<SerialPort,PortProtocol> m_ports;

				MethodList<serialport,portprotocol> m_methodStateChanger_onConnection;
				MethodList<serialport,portprotocol> m_methodStateChanger_onDisconnection;

				//StateChanger
				InvokerList<SerialConnectionStateChanger> m_stateChanger;

				MethodList<> m_methodStateGlobalChanger_onConnection;
				MethodList<> m_methodStateGlobalChanger_onDisconnection;
		};

	}

#endif
