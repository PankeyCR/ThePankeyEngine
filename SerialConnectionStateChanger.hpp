
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialConnectionStateChanger) || defined(ame_upToLevel_1)
	#define SerialConnectionStateChanger_hpp
#endif

#ifndef SerialConnectionStateChanger_hpp
#define SerialConnectionStateChanger_hpp
#define SerialConnectionStateChanger_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialPort.hpp"
#include "PortProtocol.hpp"
#include "List.hpp"

namespace ame{

class SerialConnectionStateChanger{
    public:
		SerialConnectionStateChanger(){}
		virtual ~SerialConnectionStateChanger(){}
		
		virtual void onGlobalConnection(){}
		virtual void onGlobalDisconnection(){}
		
		virtual void onConnection(SerialPort* port, PortProtocol* protocol){}
		virtual void onDisconnection(SerialPort* port, PortProtocol* protocol){}
		
		virtual void operator=(SerialConnectionStateChanger b){}
		virtual bool operator==(SerialConnectionStateChanger b){
			return false;
		}
		virtual bool operator!=(SerialConnectionStateChanger b){
			return false;
		}
	protected:
};

}

#endif