
#ifndef UsbNetwork_hpp
	#define UsbNetwork_hpp

	#include "SerialNetwork.hpp"

	#ifdef higgs_ArduinoIDE
		#include "Stream.h"
	#endif

	#ifdef UsbNetwork_LogApp
		#include "higgs_Logger.hpp"
		#define UsbNetworkLog(location,method,type,mns) higgs_Log((void*)this,location,"UsbNetwork",method,type,mns)
	#else
		#define UsbNetworkLog(location,method,type,mns) 
	#endif

	namespace higgs{

		class UsbNetwork : public SerialNetwork{	
			public:	
				UsbNetwork(Stream* a_serial){
					m_port = a_serial;
				}
				virtual ~UsbNetwork(){}
				
				virtual void instantSend(Note a_message){
					m_port->print(a_message);
				}

				virtual void instantSend(Note a_name, Note a_message){}
				
				virtual void send(Note a_message){}

				virtual void send(Note a_name, Note a_message){}
				
				virtual bool isConnected(Note a_name){return false;}
			
				virtual void connect() {}
				
				virtual void connect(Note a_name) {}
					
				virtual void disconect() {}
				
				virtual void disconect(Note a_name) {}
				
				virtual bool ping(Note a_name){
					return false;
				}

				virtual void updateState(Args... a_values){
					if(m_port->available() > 0) {
						Read(m_port);
					}
					if() {
						Read(m_port);
					}
					for(int x = 0; x < m_broadMessages.getPosition(); x++){
						portProtocol->BroadcastMessage(port, *m_broadMessages.getByPosition(x));
					}
					m_broadMessages.resetDelete();
				}
				
			protected:
				Stream* m_port = nullptr;
		};

	}

#endif