
#ifndef SerialNetwork_hpp
#define SerialNetwork_hpp
#define SerialNetwork_AVAILABLE

#include "BaseAppState.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"
#include "MessageDelivery.hpp"
#include "NetworkConnectivity.hpp"
#include "NetworkReliability.hpp"

namespace ame{
	class SerialNetwork;
}

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

class SerialNetwork : public BaseAppState , public SerialController{	
    public:	
		virtual ~SerialNetwork(){}
			
		virtual cppObjectClass* getClass(){
			return Class<SerialNetwork>::getClass();
		}
		
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialNetwork>::getClass() || AppState::instanceof(cls);
		}
		
		virtual void setIP(Note a_ip){m_ip = a_ip;}
		virtual void setMAc(Note a_mac){m_mac = a_mac;}
		
		virtual void instantSend(Note a_message){}
		
		virtual void instantSend(ByteArray a_message){}

		virtual void instantSend(Note a_name, Note a_message){}

		virtual void instantSend(Note a_name, ByteArray a_message){}
		
		virtual void send(Note a_message){}
		
		virtual void send(ByteArray a_message){}

		virtual void send(Note a_name, Note a_message){}

		virtual void send(Note a_name, ByteArray a_message){}
		
		virtual bool isConnected(Note a_name){return false;}
    
		virtual void connect() {}
		
		virtual void connect(Note a_name) {}
		    
		virtual void disconect() {}
		
		virtual void disconect(Note a_name) {}
		
		virtual bool ping(Note a_name){
			return false;
		}
		
		virtual void setDelivery(MessageDelivery* a_delivery){
			m_delivery = a_delivery;
			if(m_delivery == nullptr){
				return;
			}
			if(this->hasInitialize()){
				m_delivery->initialize(this);
			}
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
		
		virtual void initialize(Application* app){
			SerialNetworkLog(ame_Log_StartMethod, "initialize", "println", "");
			if(m_delivery != nullptr){
				m_delivery->initialize(this);
			}
			BaseAppState::initialize(app);
			SerialNetworkLog(ame_Log_EndMethod, "initialize", "println", "");
		}
		
		virtual void initializeState(Application* app){
			
		}
		
		virtual void updateState(float tpc){
			
		}
		
	protected:
		Note m_ip = "150.1.0.0";
		Note m_mac = "0.0.0.0.0.0,0";
	
		MessageDelivery* m_delivery = nullptr;
		
		NetworkConnectivity m_connectivity = NetworkConnectivity::Mesh;
		NetworkReliability m_reliability = NetworkReliability::Tcp;
};

}

#endif