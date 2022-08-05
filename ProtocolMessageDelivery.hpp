
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ProtocolMessageDelivery)
	#define ProtocolMessageDelivery_hpp
#endif

#ifndef ProtocolMessageDelivery_hpp
#define ProtocolMessageDelivery_hpp
#define ProtocolMessageDelivery_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Note.hpp"
#include "ByteArray.hpp"

namespace ame{

class ProtocolMessageDelivery : public cppObject{

    public:
		ProtocolMessageDelivery(){}
		virtual ~ProtocolMessageDelivery(){}
		
		virtual void SaveMessage(SerialPort* port, Note a_mns){}
		virtual void SaveMessage(SerialPort* port, ByteArray a_mns){}
		
		virtual void operator=(ProtocolMessageDelivery b){}
		virtual bool operator==(ProtocolMessageDelivery b){return true;}
		virtual bool operator!=(ProtocolMessageDelivery b){return true;}
		
		virtual cppObjectClass* getClass(){return Class<ProtocolMessageDelivery>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<ProtocolMessageDelivery>::classType || cppObject::instanceof(cls);
		}
		
	protected:
};

}

#endif