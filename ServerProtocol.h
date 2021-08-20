
#ifndef ServerProtocol_h
#define ServerProtocol_h

#include "Application.h"
#include "SerialServer.h"
#include "SerialPort.h"
#include "Message.h"

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
		
		virtual void operator=(ServerProtocol b){}
		virtual bool operator==(ServerProtocol b){return true;}
		virtual bool operator!=(ServerProtocol b){return true;}
		
	protected:
		SerialMessageState* serialState = nullptr;
};

}

#endif 
