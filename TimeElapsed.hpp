
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TimeElapsed)
	#define TimeElapsed_hpp
#endif

#ifndef TimeElapsed_hpp
#define TimeElapsed_hpp
#define TimeElapsed_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class TimeControl;

class TimeElapsed {
    public:
		virtual void Play(TimeControl *t){}
		virtual void operator=(TimeElapsed a){}
		virtual bool operator==(TimeElapsed a){
				return true;
		}
		virtual bool operator!=(TimeElapsed a){
				return true;
		}
	private:	
};

}

#endif