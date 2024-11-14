
#ifndef ServerProtocol_hpp
	#define ServerProtocol_hpp

	#include "SerialServer.hpp"
	#include "SerialPort.hpp"
	#include "PortProtocol.hpp"

	namespace pankey{

		class ServerProtocol{	
			public:
				ServerProtocol(){}
				
				virtual ~ServerProtocol(){}
				
				virtual obj<SerialPort> accept(obj<SerialServer> server){return nullptr;}
				
				virtual void UpdateSerialPort(obj<SerialPort> port){}
				
				virtual bool isPortManaged(){return true;}
				
				virtual obj<PortProtocol> createPortProtocol(){return obj<PortProtocol>();}
				
				virtual void update(obj<SerialServer> server, long a_tpc){}
				
				virtual void NetworkMessage(obj<SerialServer> a_server, Note a_mns){}
				
				virtual void operator=(const ServerProtocol& a_protocol){}
				virtual bool operator==(const ServerProtocol& a_protocol){return true;}
				virtual bool operator!=(const ServerProtocol& a_protocol){return true;}
				
		};

	}

#endif