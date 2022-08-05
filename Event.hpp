
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Event)
	#define Event_hpp
#endif

#ifndef Event_hpp
#define Event_hpp
#define Event_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class Event{
    public:
		virtual ~Event(){}
		virtual bool event(){return false;}
		
		virtual void operator=(Event b){}
		virtual bool operator==(Event b){return false;}
		virtual bool operator!=(Event b){return true;}
};

}

#endif