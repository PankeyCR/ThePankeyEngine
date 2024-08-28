
#ifndef RadioProtocol_hpp
#define RadioProtocol_hpp

#include "PortProtocol.hpp"
#include "SerialPort.hpp"

#ifdef RadioProtocolLogApp
	#include "Logger.hpp"
	#define RadioProtocolLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define RadioProtocolLog(name,method,type,mns) 
#endif

namespace pankey{

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