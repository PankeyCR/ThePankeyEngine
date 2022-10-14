
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SerialListener)
	#define SerialListener_hpp
#endif

#ifndef SerialListener_hpp
#define SerialListener_hpp
#define SerialListener_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Command.hpp"
#include "Message.hpp"
#include "cppObject.hpp"
#include "AbstractClass.hpp"

namespace ame{

class SerialState;

template<class T>
class SerialListener : public Command<T>{
    public:
		SerialListener(){}
		virtual ~SerialListener(){}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == AbstractClass<SerialListener<T>>::getClass();
		}
		virtual cppObjectClass* getClass(){return AbstractClass<SerialListener<T>>::getClass();}
		
		virtual void setSerialState(SerialState* sT){
			serialState = sT;
		}
		virtual SerialState* getSerialState(){
			return serialState;
		}
	protected:
		SerialState* serialState = nullptr;
};

}

#endif