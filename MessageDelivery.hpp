
#ifndef MessageDelivery_hpp
#define MessageDelivery_hpp
#define MessageDelivery_AVAILABLE

#include "cppObject.hpp"
#include "Note.hpp"
#include "ame_Byte.hpp"
#include "ByteArray.hpp"

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

/*
*	Class Configuration:
*	DISABLE_IMPLEMENTATION_cppObject
*/
class MessageDelivery IMPLEMENTATION_cppObject {

    public:
		MessageDelivery(){}
		virtual ~MessageDelivery(){}
		
		virtual void initialize(SerialNetwork* state){
			this->serialState = state;
		}

		virtual SerialNetwork* getSerialNetwork(){
			return this->serialState;
		}
		
		virtual bool DeliverMessage(Note* a_mns){return false;}
		virtual bool DeliverMessage(ByteArray* a_mns){return false;}
		
		virtual bool StreamDeliverMessage(char a_mns){return false;}
		virtual bool StreamDeliverMessage(ame_Byte a_mns){return false;}
		
		virtual void operator=(MessageDelivery b){}
		virtual bool operator==(MessageDelivery b){return false;}
		virtual bool operator!=(MessageDelivery b){return false;}
		
		#if defined(cppObject_AVAILABLE) && defined(cppObjectClass_AVAILABLE) && defined(Class_AVAILABLE)
		virtual cppObjectClass* getClass(){return Class<MessageDelivery>::getClass();}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<MessageDelivery>::getClass();
		}
		#endif
		
	protected:
		SerialNetwork* serialState = nullptr;
};

}

#endif