

#ifndef SerialPost_hpp
#define SerialPost_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "SerialMessageState.hpp"
#include "PrimitiveList.hpp"
#include "Command.hpp"
#include "Message.hpp"
#include "SerialListener.hpp"
#include "MemoryRam.hpp"

#ifdef SerialPostLogApp
	#include "Logger.hpp"
	#define SerialPostLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define SerialPostLog(name,method,type,mns)
#endif

namespace ame{

class SerialPost : public SerialListener{
    public:
		SerialPost(){
			SerialPostLog("SerialPost", "Constructor",  "println", "");
		}
		virtual ~SerialPost(){
			SerialPostLog("SerialPost", "Destructor",  "println", "");
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<SerialPost>::classType;
		}
		virtual cppObjectClass* getClass(){return Class<SerialPost>::classType;}
		
		virtual void execute(Message* message){
			
		}
	protected:
};

}

#endif 
