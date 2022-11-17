
#ifndef CONFIGURATION_SerialController_hpp
#define CONFIGURATION_SerialController_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_SerialController)
		#define SerialController_hpp

		#define IMPLEMENTATION_SerialController
		#define IMPLEMENTING_SerialController
	#else
		#if defined(DISABLE_IMPLEMENTATION_SerialController)
			#define IMPLEMENTATION_SerialController
			#define IMPLEMENTING_SerialController
		#endif
	#endif
#endif

#ifndef SerialController_hpp
#define SerialController_hpp
#define SerialController_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_SerialController
	#define IMPLEMENTATION_SerialController IMPLEMENTATION(public SerialController)
	#define IMPLEMENTING_SerialController IMPLEMENTING(public SerialController)
#endif

#include "PrimitiveList.hpp"
#include "PrimitiveMap.hpp"

#ifdef SerialController_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"

	#define SerialControllerLog(location,method,type,mns) ame_Log(this,location,"SerialController",method,type,mns)
	#define const_SerialControllerLog(location,method,type,mns)
#else
	#ifdef SerialController_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"

		#define SerialControllerLog(location,method,type,mns) ame_LogDebug(this,location,"SerialController",method,type)
		#define const_SerialControllerLog(location,method,type,mns)
	#else
		#define SerialControllerLog(location,method,type,mns)
		#define const_SerialControllerLog(location,method,type,mns)
	#endif
#endif

namespace ame{

class SerialController{
    public:
		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		using MethodStateChanger = void (*)(SerialPort*,PortProtocol*);
		#endif
		using MethodStateGlobalChanger = void (*)();
		
		virtual ~SerialController(){
			SerialControllerLog(ame_Log_StartMethod, "Destructor", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "Destructor", "println", "");
		}

		//The onConnections methods are only used if the port and the protocol are not nullptr

		virtual void onGlobalConnection(){
			SerialControllerLog(ame_Log_StartMethod, "onGlobalConnection", "println", "");
			for(int xDisc = 0; xDisc < m_methodStateGlobalChanger_onConnection.getPosition(); xDisc++){
				MethodStateGlobalChanger* schanger = m_methodStateGlobalChanger_onConnection.getByPosition(xDisc);
				(*schanger)();//change
			}
			for(int xDisc = 0; xDisc < m_stateChanger.getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = m_stateChanger.getByPosition(xDisc);
				schanger->onGlobalConnection();
			}
			SerialControllerLog(ame_Log_EndMethod, "onGlobalConnection", "println", "");
		}

		virtual void onGlobalDisconnection(){
			SerialControllerLog(ame_Log_StartMethod, "onGlobalDisconnection", "println", "");
			for(int xDisc = 0; xDisc < m_methodStateGlobalChanger_onDisconnection.getPosition(); xDisc++){
				MethodStateGlobalChanger* schanger = m_methodStateGlobalChanger_onDisconnection.getByPosition(xDisc);
				(*schanger)();//change
			}
			for(int xDisc = 0; xDisc < m_stateChanger.getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = m_stateChanger.getByPosition(xDisc);
				schanger->onGlobalDisconnection();
			}
			SerialControllerLog(ame_Log_EndMethod, "onGlobalDisconnection", "println", "");
		}

		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		virtual void onConnection(){
			SerialControllerLog(ame_Log_StartMethod, "onConnection", "println", "");
			for(int x_ports = 0; x_ports < m_ports.getPosition(); x_ports++){
				auto f_entry = m_ports.getMapEntryByPosition(x_ports);
				SerialPort* f_ports = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				for(int xDisc = 0; xDisc < m_methodStateChanger_onConnection.getPosition(); xDisc++){
					MethodStateChanger* schanger = m_methodStateChanger_onConnection.getByPosition(xDisc);
					(*schanger)(f_ports, f_protocol);//change
				}
				for(int xDisc = 0; xDisc < m_stateChanger.getPosition(); xDisc++){
					SerialConnectionStateChanger* schanger = m_stateChanger.getByPosition(xDisc);
					schanger->onConnection(f_ports, f_protocol);
				}
			}
			SerialControllerLog(ame_Log_EndMethod, "onConnection", "println", "");
		}

		virtual void onDisconnection(){
			SerialControllerLog(ame_Log_StartMethod, "onDisconnection", "println", "");
			for(int x_ports = 0; x_ports < m_ports.getPosition(); x_ports++){
				auto f_entry = m_ports.getMapEntryByPosition(x_ports);
				SerialPort* f_ports = f_entry.getKey();
				PortProtocol* f_protocol = f_entry.getValue();
				for(int xDisc = 0; xDisc < m_methodStateChanger_onDisconnection.getPosition(); xDisc++){
					MethodStateChanger* schanger = m_methodStateChanger_onDisconnection.getByPosition(xDisc);
					(*schanger)(f_ports, f_protocol);//change
				}
				for(int xDisc = 0; xDisc < m_stateChanger.getPosition(); xDisc++){
					SerialConnectionStateChanger* schanger = m_stateChanger.getByPosition(xDisc);
					schanger->onDisconnection(f_ports, f_protocol);
				}
			}
			SerialControllerLog(ame_Log_EndMethod, "onDisconnection", "println", "");
		}

		virtual void onConnection(SerialPort* a_serialport, PortProtocol* a_portprotocol){
			SerialControllerLog(ame_Log_StartMethod, "onConnection", "println", "");
			for(int xDisc = 0; xDisc < m_methodStateChanger_onConnection.getPosition(); xDisc++){
				MethodStateChanger* schanger = m_methodStateChanger_onConnection.getByPosition(xDisc);
				(*schanger)(a_serialport, a_portprotocol);//change
			}
			for(int xDisc = 0; xDisc < m_stateChanger.getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = m_stateChanger.getByPosition(xDisc);
				schanger->onConnection(a_serialport, a_portprotocol);
			}
			SerialControllerLog(ame_Log_EndMethod, "onConnection", "println", "");
		}

		virtual void onDisconnection(SerialPort* a_serialport, PortProtocol* a_portprotocol){
			SerialControllerLog(ame_Log_StartMethod, "onDisconnection", "println", "");
			for(int xDisc = 0; xDisc < m_methodStateChanger_onDisconnection.getPosition(); xDisc++){
				MethodStateChanger* schanger = m_methodStateChanger_onDisconnection.getByPosition(xDisc);
				(*schanger)(a_serialport, a_portprotocol);//change
			}
			for(int xDisc = 0; xDisc < m_stateChanger.getPosition(); xDisc++){
				SerialConnectionStateChanger* schanger = m_stateChanger.getByPosition(xDisc);
				schanger->onDisconnection(a_serialport, a_portprotocol);
			}
			SerialControllerLog(ame_Log_EndMethod, "onDisconnection", "println", "");
		}
		#endif

		#if defined(SerialServer_AVAILABLE) && defined(ServerProtocol_AVAILABLE)
		virtual MapEntry<SerialServer,ServerProtocol> addSerialServer(SerialServer* serial, ServerProtocol* protocol){
			SerialControllerLog(ame_Log_StartMethod, "addSerialServer", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "addSerialServer", "println", "");
			return m_servers.addPointers(serial, protocol);
		}

		#if defined(SerialNetwork_AVAILABLE)
		virtual void initializeSerialServers(SerialNetwork* a_serialNetwork){
			SerialControllerLog(ame_Log_StartMethod, "initializeSerialServers", "println", "");
			for(int x = 0; x < m_servers.getPosition(); x++){
				ServerProtocol* f_protocol = m_servers.getValueByPosition(x);
				if(f_protocol == nullptr){
					continue;
				}
				f_protocol->initialize(a_serialNetwork);
			}
			SerialControllerLog(ame_Log_EndMethod, "initializeSerialServers", "println", "");
		}
		#endif

		virtual SerialServer* getSerialServer(int index){
			SerialControllerLog(ame_Log_StartMethod, "getSerialServer", "println", "int index");
			SerialControllerLog(ame_Log_EndMethod, "getSerialServer", "println", "");
			return m_servers.getKeyByPosition(index);
		}

		virtual int getSerialServerSize(){
			return m_servers.getPosition();
		}

		virtual bool containSerialServer(SerialServer* a_server){
			return m_servers.containKeyByPointer(a_server);
		}

		virtual bool containSerialServer(Note name){
			for(int x = 0; x < m_servers.getPosition(); x++){
				SerialServer* i_server = m_servers.getKeyByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getName() == name){
					return true;
				}
			}
			return false;
		}

		virtual MapEntry<SerialServer,ServerProtocol> removeSerialServer(SerialServer* a_server){
			SerialControllerLog(ame_Log_StartMethod, "removeSerialServer", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "removeSerialServer", "println", "");
			return m_servers.removeByKeyPointer(a_server);
		}

		virtual bool removeDeleteSerialServer(SerialServer* a_server){
			SerialControllerLog(ame_Log_StartMethod, "removeDeleteSerialServer", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "removeDeleteSerialServer", "println", "");
			return m_servers.removeDeleteByKeyPointer(a_server);
		}

		virtual MapEntry<SerialServer,ServerProtocol> removeSerialServer(int index){
			SerialControllerLog(ame_Log_StartMethod, "removeSerialServer", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "removeSerialServer", "println", "");
			return m_servers.removeByPosition(index);
		}

		virtual bool removeDeleteSerialServer(int index){
			SerialControllerLog(ame_Log_StartMethod, "removeDeleteSerialServer", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "removeDeleteSerialServer", "println", "");
			return m_servers.removeDeleteByPosition(index);
		}

		virtual void removeAllSerialServer(){
			SerialControllerLog(ame_Log_StartMethod, "removeAllSerialServer", "println", "");
			m_servers.reset();
			SerialControllerLog(ame_Log_EndMethod, "removeAllSerialServer", "println", "");
		}

		virtual void removeDeleteAllSerialServer(){
			SerialControllerLog(ame_Log_StartMethod, "removeAllSerialServer", "println", "");
			m_servers.resetDelete();
			SerialControllerLog(ame_Log_EndMethod, "removeAllSerialServer", "println", "");
		}

		virtual ServerProtocol* getServerProtocol(int index){
			return m_servers.getValueByPosition(index);
		}

		virtual ServerProtocol* getServerProtocol(SerialServer* a_server){
			return m_servers.getValueByPointer(a_server);
		}

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE)
		virtual SerialServer* getSerialServer(cppObjectClass* cls){
			SerialControllerLog(ame_Log_StartMethod, "getSerialServer", "println", "cppObjectClass* cls");
			for(int x = 0; x < m_servers.getPosition(); x++){
				SerialServer* i_server = m_servers.getKeyByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getClass() == cls){
					SerialControllerLog(ame_Log_EndMethod, "getSerialServer", "println", "");
					return i_server;
				}
			}
			SerialControllerLog(ame_Log_EndMethod, "getSerialServer", "println", "");
			return nullptr;
		}

		virtual SerialServer* getSerialServer(Note name, cppObjectClass* cls){
			for(int x = 0; x < m_servers.getPosition(); x++){
				SerialServer* i_server = m_servers.getKeyByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getClass() == cls && i_server->getName() == name){
					return i_server;
				}
			}
			return nullptr;
		}
		
		virtual bool containSerialServer(cppObjectClass* cls){
			for(int x = 0; x < m_servers.getPosition(); x++){
				SerialServer* i_server = m_servers.getKeyByPosition(x);
				if(i_server == nullptr){
					continue;
				}
				if(i_server->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		#endif
		#endif

		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		virtual MapEntry<SerialPort,PortProtocol> addSerialPort(SerialPort* a_port, PortProtocol* a_protocol){
			SerialControllerLog(ame_Log_StartMethod, "addSerialPort",  "println", "SerialPort* a_port, PortProtocol* a_protocol");
			SerialControllerLog(ame_Log_EndMethod, "addSerialPort", "println", "");
			return m_ports.addPointers(a_port, a_protocol);
		}

		#if defined(SerialNetwork_AVAILABLE)
		virtual void initializeSerialPorts(SerialNetwork* a_serialNetwork){
			SerialControllerLog(ame_Log_StartMethod, "initializeSerialPorts", "println", "");
			for(int x = 0; x < m_ports.getPosition(); x++){
				PortProtocol* f_protocol = m_ports.getValueByPosition(x);
				if(f_protocol == nullptr){
					continue;
				}
				f_protocol->initialize(a_serialNetwork);
			}
			SerialControllerLog(ame_Log_EndMethod, "initializeSerialPorts", "println", "");
		}
		#endif

		virtual PrimitiveMap<SerialPort,PortProtocol>& getSerialPorts(){
			return m_ports;
		}

		virtual SerialPort* getSerialPort(Note name){
			for(int x = 0; x < m_ports.getPosition(); x++){
				SerialPort* i_port = m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == name){
					return i_port;
				}
			}
			return nullptr;
		}

		virtual SerialPort* getSerialPort(int index){
			return m_ports.getKeyByPosition(index);
		}

		virtual int getSerialPortSize(){
			return m_ports.getPosition();
		}

		virtual bool containSerialPort(SerialPort* a_port){
			SerialControllerLog(ame_Log_StartMethod, "containSerialPort", "println", "");
			SerialControllerLog(ame_Log_EndMethod, "containSerialPort", "println", "");
			return m_ports.containKeyByPointer(a_port);
		}
		
		virtual bool containSerialPort(Note a_port){
			for(int x = 0; x < m_ports.getPosition(); x++){
				SerialPort* i_port = m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == a_port){
					return true;
				}
			}
			return false;
		}

		virtual MapEntry<SerialPort,PortProtocol> removeSerialPort(int index){
			SerialControllerLog(ame_Log_StartMethod, "removeSerialPort",  "println", "with protocol");
			SerialControllerLog(ame_Log_EndMethod, "removeSerialPort", "println", "");
			return m_ports.removeByPosition(index);
		}

		virtual bool removeDeleteSerialPort(int index){
			SerialControllerLog(ame_Log_StartMethod, "removeDeleteSerialPort",  "println", "with protocol");
			SerialControllerLog(ame_Log_EndMethod, "removeDeleteSerialPort", "println", "");
			return m_ports.removeDeleteByPosition(index);
		}

		virtual MapEntry<SerialPort,PortProtocol> removeSerialPort(SerialPort* a_port){
			SerialControllerLog(ame_Log_StartMethod, "removeSerialPort",  "println", "with protocol");
			SerialControllerLog(ame_Log_EndMethod, "removeSerialPort", "println", "");
			return m_ports.removeByKeyPointer(a_port);
		}

		virtual bool removeDeleteSerialPort(SerialPort* a_port){
			SerialControllerLog(ame_Log_StartMethod, "removeDeleteSerialPort",  "println", "with protocol");
			SerialControllerLog(ame_Log_EndMethod, "removeDeleteSerialPort", "println", "");
			return m_ports.removeDeleteByKeyPointer(a_port);
		}

		virtual void removeAllSerialPort(){
			SerialControllerLog(ame_Log_StartMethod, "removeAllSerialPort",  "println", "with protocol");
			m_ports.reset();
			SerialControllerLog(ame_Log_EndMethod, "removeAllSerialPort", "println", "");
		}

		virtual void removeDeleteAllSerialPort(){
			SerialControllerLog(ame_Log_StartMethod, "removeAllSerialPort",  "println", "with protocol");
			m_ports.resetDelete();
			SerialControllerLog(ame_Log_EndMethod, "removeAllSerialPort", "println", "");
		}

		virtual PortProtocol* getPortProtocol(int index){
			return m_ports.getValueByPosition(index);
		}

		virtual PortProtocol* getPortProtocol(SerialPort* a_port){
			return m_ports.getValueByPointer(a_port);
		}

		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE)
		virtual SerialPort* getSerialPort(Note name, cppObjectClass* cls){
			for(int x = 0; x < m_ports.getPosition(); x++){
				SerialPort* i_port = m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getName() == name && i_port->getClass() == cls){
					return i_port;
				}
			}
			return nullptr;
		}

		virtual SerialPort* getSerialPort(cppObjectClass* cls){
			for(int x = 0; x < m_ports.getPosition(); x++){
				SerialPort* i_port = m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getClass() == cls){
					return i_port;
				}
			}
			return nullptr;
		}

		virtual bool containSerialPort(Note name, cppObjectClass* cls){
			for(int x = 0; x < m_ports.getPosition(); x++){
				SerialPort* i_port = m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getClass() == cls && i_port->getName() == name){
					return true;
				}
			}
			return false;
		}

		virtual bool containSerialPort(cppObjectClass* cls){
			for(int x = 0; x < m_ports.getPosition(); x++){
				SerialPort* i_port = m_ports.getKeyByPosition(x);
				if(i_port == nullptr){
					continue;
				}
				if(i_port->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		#endif
		#endif

		virtual void addConnectionStateChanger(SerialConnectionStateChanger* changer){
			m_stateChanger.addPointer(changer);
		}
		
		virtual SerialConnectionStateChanger* removeConnectionStateChanger(SerialConnectionStateChanger* changer){
			return m_stateChanger.removeByPointer(changer);
		}

		virtual void removeDeleteConnectionStateChanger(SerialConnectionStateChanger* changer){
			m_stateChanger.removeDeleteByPointer(changer);
		}

		virtual void addGlobalConnectionStateChanger(MethodStateGlobalChanger changer){
			m_methodStateGlobalChanger_onConnection.addLValue(changer);
		}

		virtual void removeGlobalConnectionStateChanger(MethodStateGlobalChanger changer){
			m_methodStateGlobalChanger_onConnection.removeByLValue(changer);
		}

		virtual void removeDeleteGlobalConnectionStateChanger(MethodStateGlobalChanger changer){
			m_methodStateGlobalChanger_onConnection.removeDeleteByLValue(changer);
		}

		virtual void addGlobalDisconnectionStateChanger(MethodStateGlobalChanger changer){
			m_methodStateGlobalChanger_onDisconnection.addLValue(changer);
		}

		virtual void removeGlobalDisconnectionStateChanger(MethodStateGlobalChanger changer){
			m_methodStateGlobalChanger_onDisconnection.removeByLValue(changer);
		}

		virtual void removeDeleteGlobalDisconnectionStateChanger(MethodStateGlobalChanger changer){
			m_methodStateGlobalChanger_onDisconnection.removeDeleteByLValue(changer);
		}

		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		virtual void addConnectionStateChanger(MethodStateChanger changer){
			m_methodStateChanger_onConnection.addLValue(changer);
		}

		virtual void removeConnectionStateChanger(MethodStateChanger changer){
			m_methodStateChanger_onConnection.removeByLValue(changer);
		}

		virtual void removeDeleteConnectionStateChanger(MethodStateChanger changer){
			m_methodStateChanger_onConnection.removeDeleteByLValue(changer);
		}

		virtual void addDisconnectionStateChanger(MethodStateChanger changer){
			m_methodStateChanger_onDisconnection.addLValue(changer);
		}

		virtual void removeDisconnectionStateChanger(MethodStateChanger changer){
			m_methodStateChanger_onDisconnection.removeByLValue(changer);
		}

		virtual void removeDeleteDisconnectionStateChanger(MethodStateChanger changer){
			m_methodStateChanger_onDisconnection.removeDeleteByLValue(changer);
		}
		#endif

	protected:
		#if defined(SerialServer_AVAILABLE) && defined(ServerProtocol_AVAILABLE)
		PrimitiveMap<SerialServer,ServerProtocol> m_servers;
		#endif

		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		PrimitiveMap<SerialPort,PortProtocol> m_ports;

		PrimitiveList<MethodStateChanger> m_methodStateChanger_onConnection;
		PrimitiveList<MethodStateChanger> m_methodStateChanger_onDisconnection;
		#endif

		//StateChanger
		PrimitiveList<SerialConnectionStateChanger> m_stateChanger;

		PrimitiveList<MethodStateGlobalChanger> m_methodStateGlobalChanger_onConnection;
		PrimitiveList<MethodStateGlobalChanger> m_methodStateGlobalChanger_onDisconnection;
};

}

#endif
