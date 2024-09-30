
#ifndef SerialConnectionStateChanger_hpp
	#define SerialConnectionStateChanger_hpp

	#include "SerialPort.hpp"
	#include "PortProtocol.hpp"

	namespace pankey{

		class SerialConnectionStateChanger{
			public:
				SerialConnectionStateChanger(){}
				virtual ~SerialConnectionStateChanger(){}
				
				virtual void onGlobalConnection(){}
				virtual void onGlobalDisconnection(){}
				
				virtual void onConnection(obj<SerialPort> port, obj<PortProtocol> protocol){}
				virtual void onDisconnection(obj<SerialPort> port, obj<PortProtocol> protocol){}
				
				virtual void operator=(const SerialConnectionStateChanger& a_changer){}
				virtual bool operator==(const SerialConnectionStateChanger& a_changer){return false;}
				virtual bool operator!=(const SerialConnectionStateChanger& a_changer){return false;}
			protected:
		};

	}

#endif