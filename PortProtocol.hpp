
#include "ame_Enviroment.hpp"

#if defined(DISABLE_PortProtocol)
	#define PortProtocol_hpp
#endif

#ifndef PortProtocol_hpp
#define PortProtocol_hpp
#define PortProtocol_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialPort.hpp"
#include "ProtocolMessageDelivery.hpp"
#include "ByteArray.hpp"

namespace ame{
	
class SerialState;

class PortProtocol : public cppObject{

    public:
		PortProtocol(){}
		virtual ~PortProtocol(){}
		
		virtual void attach(SerialState* state){
			this->serialState = state;
		}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantBroadcastMessage(SerialPort* port, const Note& mns){}
		
		//this method has control of the sending of the message, so remember sending it
		virtual void InstantPrivateMessage(SerialPort* port, const Note& mns){}
		
		virtual void InstantPrivateByteArrayMessage(SerialPort* port, ByteArray array){}
		
		virtual void GlobalConect(SerialPort* port){}
		virtual void Conect(SerialPort* port){}
		virtual void UpdateConect(SerialPort* port){}
		
		virtual void GlobalDisconect(SerialPort* port){}
		virtual void Disconect(SerialPort* port){}
		virtual void UpdateDisconect(SerialPort* port){}
		
		virtual void Read(int index, SerialPort* port){}
		
		//you need to send to message manually
		virtual void BroadcastMessage(SerialPort* port, const Note& mns){}
		//you need to send to message manually
		virtual void PrivateMessage(SerialPort* port, const Note& mns){}
		
		virtual void setSafeDelete(bool s){safeDelete = s;}
		virtual bool SafeDelete(){return safeDelete;}
		
		virtual void SaveMessage(SerialPort* port, Note a_mns){
			if(delivery == nullptr){
				return;
			}
			delivery->SaveMessage(port,a_mns);
		}
		virtual void SaveMessage(SerialPort* port, ByteArray a_mns){
			if(delivery == nullptr){
				return;
			}
			delivery->SaveMessage(port,a_mns);
		}
		
		virtual void update(SerialPort* port, float tpc){}
		
		virtual void operator=(PortProtocol b){}
		virtual bool operator==(PortProtocol b){return true;}
		virtual bool operator!=(PortProtocol b){return true;}
		
		virtual cppObjectClass* getClass(){return Class<PortProtocol>::classType;}
		virtual Note toNote(){return "PortProtocol";}
		virtual bool equal(cppObject *b){
			if(b == this){
				return true;
			}
			return false;
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<PortProtocol>::classType || cppObject::instanceof(cls);
		}
		
		virtual cppObject *clone(){return nullptr;}
		
	protected:
		bool safeDelete = true;
		SerialState* serialState = nullptr;
		ProtocolMessageDelivery* delivery = nullptr;
};

}

#endif