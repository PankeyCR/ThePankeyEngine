

#ifndef SerialConnectionStateChanger_hpp
#define SerialConnectionStateChanger_hpp

#include "SerialPort.hpp"
#include "List.hpp"

namespace ame{

class SerialConnectionStateChanger{
    public:
		SerialConnectionStateChanger(){}
		virtual ~SerialConnectionStateChanger(){}
		
		virtual void onConnection(SerialPort* port){}
		virtual void onDisconnection(SerialPort* port){}
		
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
