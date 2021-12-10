
#ifndef ServerProtocol_hpp
#define ServerProtocol_hpp

#include "Application.hpp"
#include "SerialServer.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"

namespace ame{
	
class SerialMessageState;

class ServerProtocol{	
    public:
		ServerProtocol(){}
		
		virtual ~ServerProtocol(){}
		
		virtual void attach(SerialMessageState* state){
			this->serialState = state;
		}
		
		virtual SerialPort* getUpdateSerialPort(SerialServer* server){return nullptr;}
		
		virtual void UpdateSerialPort(SerialPort* port){}
		
		virtual void update(SerialServer* server, float tpc){}
		
		virtual void operator=(ServerProtocol b){}
		virtual bool operator==(ServerProtocol b){return true;}
		virtual bool operator!=(ServerProtocol b){return true;}
		
	protected:
		SerialMessageState* serialState = nullptr;
};

}

#endif 
