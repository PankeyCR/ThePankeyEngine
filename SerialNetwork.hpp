
#ifndef CONFIGURATION_SerialNetwork_hpp
#define CONFIGURATION_SerialNetwork_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_SerialNetwork)
		#define SerialNetwork_hpp

		#define IMPLEMENTATION_SerialNetwork
		#define IMPLEMENTING_SerialNetwork
	#else
		#if defined(DISABLE_IMPLEMENTATION_SerialNetwork)
			#define IMPLEMENTATION_SerialNetwork
			#define IMPLEMENTING_SerialNetwork
		#endif
	#endif
#endif

#ifndef SerialNetwork_hpp
#define SerialNetwork_hpp
#define SerialNetwork_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_SerialNetwork
	#define IMPLEMENTATION_SerialNetwork IMPLEMENTATION(public SerialNetwork)
	#define IMPLEMENTING_SerialNetwork IMPLEMENTING(public SerialNetwork)
#endif

#include "BaseAppState.hpp"
#include "Note.hpp"
#include "NoteHelper.hpp"
#include "ByteArray.hpp"
#include "NetworkConnectivity.hpp"
#include "NetworkReliability.hpp"

namespace ame{
	class SerialNetwork;
}

#include "MessageDelivery.hpp"

#include "SerialPort.hpp"
#include "SerialServer.hpp"

#include "ServerProtocol.hpp"
#include "PortProtocol.hpp"

#include "SerialConnectionStateChanger.hpp"

#include "SerialController.hpp"

#include "Message.hpp"

#ifdef SerialNetwork_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define SerialNetworkLog(location,method,type,mns) ame_Log(this,location,"SerialNetwork",method,type,mns)
#else
	#ifdef SerialNetwork_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define SerialNetworkLog(location,method,type,mns) ame_LogDebug(this,location,"SerialNetwork",method,type)
	#else
		#define SerialNetworkLog(location,method,type,mns) 
	#endif
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTATION_BaseAppState
*/
class SerialNetwork : public SerialController IMPLEMENTING_BaseAppState {	
    public:	
		virtual ~SerialNetwork(){}
			
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){
			return Class<SerialNetwork>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialNetwork>::getClass()
			#if defined(BaseAppState_AVAILABLE)
			|| BaseAppState::instanceof(cls)
			#endif
			;
		}
		#endif
		
		virtual void setIP(Note a_ip){m_ip = a_ip;}
		virtual void setMAC(Note a_mac){m_mac = a_mac;}

		virtual Note getIP(){return this->m_ip;}
		virtual Note getMAC(){return this->m_mac;}
		
		// virtual void instantSend(Note a_message){}
		
		// virtual void instantSend(ByteArray a_message){}

		// virtual void instantSend(Note a_name, Note a_message){}

		// virtual void instantSend(Note a_name, ByteArray a_message){}
		
		// virtual void send(Note a_message){}
		
		// virtual void send(ByteArray a_message){}

		// virtual void send(Note a_name, Note a_message){}

		// virtual void send(Note a_name, ByteArray a_message){}
		
		// virtual bool isConnected(Note a_name){return false;}
    
		// virtual void connect() {}
		
		// virtual void connect(Note a_name) {}
		    
		// virtual void disconect() {}
		
		// virtual void disconect(Note a_name) {}
		
		// virtual bool ping(Note a_name){
		// 	return false;
		// }
		
		virtual void setDelivery(MessageDelivery* a_delivery){
			m_delivery = a_delivery;
			if(m_delivery == nullptr){
				return;
			}
			#if defined(AppState_AVAILABLE)
			if(this->hasInitialize()){
				m_delivery->initialize(this);
			}
			#endif
		}
		
		virtual MessageDelivery* getDelivery(){
			return m_delivery;
		}
		
		virtual bool DeliverMessage(Note* a_mns){
			if(m_delivery == nullptr){
				return false;
			}
			return m_delivery->DeliverMessage(a_mns);
		}
		
		virtual bool DeliverMessage(ByteArray* a_mns){
			if(m_delivery == nullptr){
				return false;
			}
			return m_delivery->DeliverMessage(a_mns);
		}
		
		virtual void setConnectivity(NetworkConnectivity a_connectivity){
			m_connectivity = a_connectivity;
		}
		
		virtual void setReliability(NetworkReliability a_reliability){
			m_reliability = a_reliability;
		}
		
		virtual void initializeState(){
			SerialNetworkLog(ame_Log_StartMethod, "initializeState", "println", "");
			if(m_delivery != nullptr){
				m_delivery->initialize(this);
			}
			#if defined(SerialServer_AVAILABLE) && defined(ServerProtocol_AVAILABLE)
			this->initializeSerialServers(this);
			#endif
			#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
			this->initializeSerialPorts(this);
			#endif
			SerialNetworkLog(ame_Log_EndMethod, "initializeState", "println", "");
		}
		
		virtual void updateState(float tpc){
			
		}

		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		virtual MapEntry<SerialPort,PortProtocol> addSerialPort(SerialPort* a_port, PortProtocol* a_protocol){
			SerialNetworkLog(ame_Log_StartMethod, "addSerialPort",  "println", "SerialPort* a_port, PortProtocol* a_protocol");
			SerialNetworkLog(ame_Log_EndMethod, "addSerialPort", "println", "");
			#if defined(AppState_AVAILABLE)
			if(a_protocol != nullptr && this->hasInitialize()){
				a_protocol->initialize(this);
			}
			#else
			a_protocol->initialize(this);
			#endif
			return SerialController::addSerialPort(a_port, a_protocol);
		}
		#endif
		
	protected:
		Note m_ip = "150.1.0.0";
		Note m_mac = "0.0.0.0.0.0,0";
	
		MessageDelivery* m_delivery = nullptr;
		
		NetworkConnectivity m_connectivity = NetworkConnectivity::Mesh;
		NetworkReliability m_reliability = NetworkReliability::Tcp;
};

}

#endif