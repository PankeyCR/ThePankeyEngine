
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Driver)
	#define Driver_hpp
#endif

#ifndef Driver_hpp
#define Driver_hpp
#define Driver_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class Driver{
    public:
		Driver(){}
		virtual ~Driver(){}
		
		virtual void initialize(){}
		
		virtual void update(){}
};

}

#endif