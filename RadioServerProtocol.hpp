
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RadioServerProtocol)
	#define RadioServerProtocol_hpp
#endif

#ifndef RadioServerProtocol_hpp
#define RadioServerProtocol_hpp
#define RadioServerProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ServerProtocol.hpp"
#include "SerialServer.hpp"
#include "SerialPort.hpp"
#include "Message.hpp"
#include "RadioType.hpp"
#include "RadioReliability.hpp"

namespace ame{

class RadioServerProtocol : public ServerProtocol{	
    public:
		RadioServerProtocol(){}
		RadioServerProtocol(RadioType c_type, RadioReliability c_r){}
		
		virtual ~RadioServerProtocol(){}
		
		virtual SerialPort* getUpdateSerialPort(SerialServer* server){return nullptr;}
		
		virtual void UpdateSerialPort(SerialPort* port){}
		
		virtual void update(SerialServer* server, float tpc){}
		
		virtual void operator=(RadioServerProtocol b){}
		virtual bool operator==(RadioServerProtocol b){return true;}
		virtual bool operator!=(RadioServerProtocol b){return true;}
		
		virtual cppObjectClass* getClass(){return Class<RadioServerProtocol>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<RadioServerProtocol>::classType || ServerProtocol::instanceof(cls);
		}
	protected:
};

}

#endif