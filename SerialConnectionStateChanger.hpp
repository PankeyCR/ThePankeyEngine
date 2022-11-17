
#ifndef CONFIGURATION_SerialConnectionStateChanger_hpp
#define CONFIGURATION_SerialConnectionStateChanger_hpp

	#include "ame_Enviroment.hpp"

	#if defined(DISABLE_SerialConnectionStateChanger)
		#define SerialConnectionStateChanger_hpp

		#define IMPLEMENTATION_SerialConnectionStateChanger
		#define IMPLEMENTING_SerialConnectionStateChanger
	#else
		#if defined(DISABLE_IMPLEMENTATION_SerialConnectionStateChanger)
			#define IMPLEMENTATION_SerialConnectionStateChanger
			#define IMPLEMENTING_SerialConnectionStateChanger
		#endif
	#endif
#endif

#ifndef SerialConnectionStateChanger_hpp
#define SerialConnectionStateChanger_hpp
#define SerialConnectionStateChanger_AVAILABLE

#ifndef DISABLE_IMPLEMENTATION_SerialConnectionStateChanger
	#define IMPLEMENTATION_SerialConnectionStateChanger IMPLEMENTATION(public SerialConnectionStateChanger)
	#define IMPLEMENTING_SerialConnectionStateChanger IMPLEMENTING(public SerialConnectionStateChanger)
#endif

namespace ame{

class SerialConnectionStateChanger{
    public:
		SerialConnectionStateChanger(){}
		virtual ~SerialConnectionStateChanger(){}
		
		virtual void onGlobalConnection(){}
		virtual void onGlobalDisconnection(){}
		
		#if defined(SerialPort_AVAILABLE) && defined(PortProtocol_AVAILABLE)
		virtual void onConnection(SerialPort* port, PortProtocol* protocol){}
		virtual void onDisconnection(SerialPort* port, PortProtocol* protocol){}
		#endif
		
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