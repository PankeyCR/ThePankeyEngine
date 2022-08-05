
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ThreadControl)
	#define ThreadControl_hpp
#endif

#ifndef ThreadControl_hpp
#define ThreadControl_hpp
#define ThreadControl_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class ThreadControl{
    public:
		ThreadControl(){}
		virtual ~ThreadControl(){}
		
		virtual void initialize(){}
		
		virtual void update(){}
};

}

#endif