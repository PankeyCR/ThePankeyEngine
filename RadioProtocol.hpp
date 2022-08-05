
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RadioProtocol)
	#define RadioProtocol_hpp
#endif

#ifndef RadioProtocol_hpp
#define RadioProtocol_hpp
#define RadioProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PortProtocol.hpp"
#include "SerialPort.hpp"

#ifdef RadioProtocolLogApp
	#include "Logger.hpp"
	#define RadioProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define RadioProtocolLog(name,method,type,mns) 
#endif

namespace ame{

class RadioProtocol : public BufferProtocol{	
    public:
		RadioProtocol(){}
		virtual ~RadioProtocol(){}
		
		virtual void GlobalDisconect(SerialPort* port){
			RadioProtocolLog("RadioProtocol", "GlobalDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void Disconect(SerialPort* port){
			RadioProtocolLog("RadioProtocol", "Disconect",  "println", "");
			port->flush();
			port->stop();
		}
		virtual void UpdateDisconect(SerialPort* port){
			RadioProtocolLog("RadioProtocol", "UpdateDisconect",  "println", "");
			port->flush();
			port->stop();
		}
		
		virtual void Read(int index, SerialPort* port){
			char m = port->read();
			
		}
		
		virtual void setType(RadioType t){
			radioType = t;
		}
		
		virtual void setReliability(RadioReliability t){
			radioR = t;
		}
		
	protected:
		RadioType radioType = RadioType::SPY;
		RadioReliability radioR = RadioReliability::Sdt;
		
		
};

}

#endif