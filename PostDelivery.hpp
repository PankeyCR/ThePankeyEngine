
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

#include "ProtocolMessageDelivery.hpp"
#include "SerialPort.hpp"
#include "SerialPost.hpp"

namespace ame{

template<class T>
class PostDelivery : public ProtocolMessageDelivery{	
    public:
		PostDelivery(SerialPost* a_post){
			serialPost = a_post;
		}
		virtual ~PostDelivery(){}
		
		virtual void SaveMessage(SerialPort* port, Note a_mns){
			serialPost->addPortMail<Note>(port->getName(), a_mns);
		}
		
		virtual void SaveMessage(SerialPort* port, ByteArray a_mns){}
	protected:
		SerialPost* serialPost = nullptr;
};

}

#endif