
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ListenerAnalogEvent)
	#define ListenerAnalogEvent_hpp
#endif

#ifndef ListenerAnalogEvent_hpp
#define ListenerAnalogEvent_hpp
#define ListenerAnalogEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class ListenerAnalogEvent{
    public:
		ListenerAnalogEvent(){}
		virtual ~ListenerAnalogEvent(){}
		
		virtual void event(int interrupt, float value, float tpc){}
		
		virtual void operator=(ListenerAnalogEvent b){}
		virtual bool operator==(ListenerAnalogEvent b){return true;}
		virtual bool operator!=(ListenerAnalogEvent b){return true;}
	protected:
};

}

#endif