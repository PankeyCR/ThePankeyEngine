
#ifndef PortProtocol_hpp
	#define PortProtocol_hpp

	#include "SerialPort.hpp"
	#include "Note.hpp"

	namespace pankey{

		class PortProtocol{
			public:
				PortProtocol(){}
				virtual ~PortProtocol(){}
				
				//this method has control of the sending of the message, so remember sending it
				virtual void InstantBroadcastMessage(obj<SerialPort> a_port, Note a_message){}
				
				//this method has control of the sending of the message, so remember sending it
				virtual void InstantPrivateMessage(obj<SerialPort> a_port, Note a_message){}
				
				virtual bool GlobalConect(obj<SerialPort> a_port){return false;}
				virtual bool Conect(obj<SerialPort> a_port){return false;}
				virtual bool UpdateConect(obj<SerialPort> a_port){return false;}
				
				virtual bool GlobalDisconect(obj<SerialPort> a_port){return false;}
				virtual bool Disconect(obj<SerialPort> a_port){return false;}
				virtual bool UpdateDisconect(obj<SerialPort> a_port){return false;}
				
				virtual Note Read(obj<SerialPort> a_port){}
				
				//you need to send to message manually
				virtual void BroadcastMessage(obj<SerialPort> a_port, Note a_message){}
				//you need to send to message manually
				virtual void PrivateMessage(obj<SerialPort> a_port, Note a_message){}
				
				virtual void update(obj<SerialPort> a_port, long a_tpc){}
				
				virtual void operator=(const PortProtocol& a_protocol){}
				virtual bool operator==(const PortProtocol& a_protocol){return true;}
				virtual bool operator!=(const PortProtocol& a_protocol){return true;}
				
			protected:

		};

	}

#endif