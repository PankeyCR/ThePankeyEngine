
#ifndef SerialConnectionStateChanger_hpp
#define SerialConnectionStateChanger_hpp

#include "SerialPort.hpp"
#include "PortProtocol.hpp"

namespace higgs{

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