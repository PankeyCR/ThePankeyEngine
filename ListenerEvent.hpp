
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ListenerEvent)
	#define ListenerEvent_hpp
#endif

#ifndef ListenerEvent_hpp
#define ListenerEvent_hpp
#define ListenerEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class ListenerEvent{
    public:
		ListenerEvent(){}
		virtual ~ListenerEvent(){}
		virtual void enable(){enable_m = true;}
		virtual void disable(){enable_m = false;}
		virtual bool isEnable(){return enable_m;}
		
		virtual void event(int interrupt, long milli, bool state){}
		
		virtual void operator=(ListenerEvent b){}
		virtual bool operator==(ListenerEvent b){return true;}
		virtual bool operator!=(ListenerEvent b){return true;}
	protected:
		bool enable_m = true;
};

}

#endif