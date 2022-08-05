
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ServerProtocol)
	#define ServerProtocol_hpp
#endif

#ifndef ServerProtocol_hpp
#define ServerProtocol_hpp
#define ServerProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Application.hpp"
#include "SerialServer.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"

namespace ame{
	
class SerialState;

class ServerProtocol : public cppObject{	
    public:
		ServerProtocol(){}
		
		virtual ~ServerProtocol(){}
		
		virtual void attach(SerialState* state){
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
		SerialState* serialState = nullptr;
};

}

#endif