
#include "ame_Enviroment.hpp"

#if defined(DISABLE_PostDelivery)
	#define PostDelivery_hpp
#endif

#ifndef PostDelivery_hpp
#define PostDelivery_hpp
#define PostDelivery_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "MessageDelivery.hpp"
#include "SerialPort.hpp"
#include "SerialPost.hpp"

namespace ame{

class PostDelivery : public MessageDelivery{	
    public:
		PostDelivery(){
		}
		virtual ~PostDelivery(){}
		
		virtual void initialize(SerialNetwork* a_network){}
		
		virtual bool DeliverMessage(Note* a_mns){
			//serialPost->addMail<Note>(a_mns);
			return true;
		}
		
		virtual bool DeliverMessage(ByteArray* a_mns){
			return false;
		}
	protected:
		//SerialPost* serialPost = nullptr;
};

}

#endif