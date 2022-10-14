
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MessageDelivery)
	#define MessageDelivery_hpp
#endif

#ifndef MessageDelivery_hpp
#define MessageDelivery_hpp
#define MessageDelivery_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "cppObject.hpp"
#include "Note.hpp"
#include "ame_Byte.hpp"
#include "ByteArray.hpp"

namespace ame{
	
class SerialNetwork;

class MessageDelivery : public cppObject{

    public:
		MessageDelivery(){}
		virtual ~MessageDelivery(){}
		
		virtual void initialize(SerialNetwork* a_network){}
		
		virtual bool DeliverMessage(Note* a_mns){return false;}
		virtual bool DeliverMessage(ByteArray* a_mns){return false;}
		
		virtual bool StreamDeliverMessage(char a_mns){return false;}
		virtual bool StreamDeliverMessage(ame_Byte a_mns){return false;}
		
		virtual void operator=(MessageDelivery b){}
		virtual bool operator==(MessageDelivery b){return false;}
		virtual bool operator!=(MessageDelivery b){return false;}
		
		virtual cppObjectClass* getClass(){return Class<MessageDelivery>::classType;}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<MessageDelivery>::classType || cppObject::instanceof(cls);
		}
		
	protected:
};

}

#endif