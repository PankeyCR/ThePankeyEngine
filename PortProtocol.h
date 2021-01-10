
#ifndef PortProtocol_h
#define PortProtocol_h

#include "SerialPort.h"
class SerialMessageState;

class PortProtocol{	
    public:
		PortProtocol(){}
		virtual ~PortProtocol(){}
		
		virtual void attach(SerialMessageState* state){
			this->serialState = state;
		}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantBroadcastMessage(SerialPort* port, String mns){}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantPrivateMessage(SerialPort* port, String mns){}
		
		virtual void GlobalDisconect(SerialPort* port){}
		virtual void Disconect(SerialPort* port){}
		virtual void UpdateDisconect(SerialPort* port){}
		
		virtual void Read(int index, SerialPort* port){}
		
		//you need to send to message manually
		virtual void BroadcastMessage(SerialPort* port, String mns){}
		//you need to send to message manually
		virtual void PrivateMessage(SerialPort* port, String mns){}
		
		virtual void operator=(PortProtocol b){}
		virtual bool operator==(PortProtocol b){return true;}
		virtual bool operator!=(PortProtocol b){return true;}
		
	protected:
		SerialMessageState* serialState = nullptr;
};
#endif 
