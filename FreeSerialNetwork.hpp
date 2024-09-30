
#ifndef FreeSerialNetwork_hpp
	#define FreeSerialNetwork_hpp

	#include "SerialState.hpp"

	#ifdef FreeSerialNetwork_LogApp
		#include "pankey_Logger.hpp"
		#define FreeSerialNetworkLog(location,method,type,mns) pankey_Log((void*)this,location,"FreeSerialNetwork",method,type,mns)
	#else
		#define FreeSerialNetworkLog(location,method,type,mns) 
	#endif

	namespace pankey{

	class FreeSerialNetwork : public SerialState{
		public:
			FreeSerialNetwork(){
				FreeSerialNetworkLog(pankey_Log_StartMethod, "Constructor", "println", "");
				FreeSerialNetworkLog(pankey_Log_EndMethod, "Constructor", "println", "");
			}
			virtual ~FreeSerialNetwork(){
				FreeSerialNetworkLog(pankey_Log_StartMethod, "Destructor", "println", "");
				FreeSerialNetworkLog(pankey_Log_EndMethod, "Destructor", "println", "");
			}

			virtual void updateState(float tpc){
				for(int x = 0; x < this->m_servers.length(); x++){
					auto f_entry = m_servers.getDuoMember(x);
					serialserver server = f_entry.getMember();
					serverprotocol serverProtocol = f_entry.getDuoMember();
					if(server.isNull() || serverProtocol.isNull()){
						continue;
					}
					serialport port = serverProtocol->accept(server);
					if(!port.isNull()){
						FreeSerialNetworkLog(pankey_Log_Statement, "update",  "println", "serial != nullptr");
						serverProtocol->UpdateSerialPort(port);
					}
					serverProtocol->update(server, tpc);
				}
				for(int index = 0; index < this->m_ports.length(); index++){
					auto f_entry = this->m_ports.getDuoMember(index);
					serialport port = f_entry.getMember();
					portprotocol portProtocol = f_entry.getDuoMember();
					if(port.isNull() || portProtocol.isNull()){
						FreeSerialNetworkLog(pankey_Log_Statement, "update",  "println", "port == nullptr || portProtocol == nullptr");
						continue;
					}
					if(!port->connected()){
						FreeSerialNetworkLog(pankey_Log_Statement, "update",  "println", "!port->connected()");
						portProtocol->UpdateDisconect(port);
						onDisconnection(port, portProtocol);
						this->m_ports.remove(index);
						index--;
					}else{
						// FreeSerialNetworkLog(pankey_Log_Statement, "update",  "println", Note("index: ") + Note(index));
						// FreeSerialNetworkLog(pankey_Log_Statement, "update",  "println", Note("Port Name: ") + port->getName());
						if(port->available() > 0) {
							// Serial.println("port->available() > 0");
							FreeSerialNetworkLog(pankey_Log_Statement, "update",  "println", "port->available() > 0");
							portProtocol->Read(index, port);
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
					auto f_entry = m_ports.getDuoMember(index);
					serialport port = f_entry.getMember();
					portprotocol portProtocol = f_entry.getDuoMember();
					if(port.isNull() || portProtocol.isNull()){
						continue;
					}
					portProtocol->PrivateMessage(port, *m_clientMessages.getValueByPosition(x));
				}
				m_clientMessages.resetDelete();
			}

		protected:
	};

	}

#endif
