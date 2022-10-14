
#ifndef ServerProtocol_hpp
#define ServerProtocol_hpp
#define ServerProtocol_AVAILABLE

#include "Application.hpp"

namespace ame{

class ServerProtocol : public cppObject{	
    public:
		ServerProtocol(){}
		
		virtual ~ServerProtocol(){}
		
		virtual void attach(SerialNetwork* state){
			this->serialState = state;
		}
		
		virtual SerialPort* getUpdateSerialPort(SerialServer* server){return nullptr;}
		
		virtual void UpdateSerialPort(SerialPort* port){}
		
		virtual void update(SerialServer* server, float tpc){}
		
		virtual void operator=(ServerProtocol b){}
		virtual bool operator==(ServerProtocol b){return true;}
		virtual bool operator!=(ServerProtocol b){return true;}
		
		virtual cppObjectClass* getClass(){return Class<ServerProtocol>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<ServerProtocol>::classType || cls == Class<cppObject>::classType;
		}
		
		virtual void NetworkMessage(SerialServer* a_server, Note a_mns){}
		
	protected:
		SerialNetwork* serialState = nullptr;
};

}

#endif