
#include "ame_Enviroment.hpp"

#if defined(DISABLE_TimeCheck)
	#define TimeCheck_hpp
#endif

#ifndef TimeCheck_hpp
#define TimeCheck_hpp
#define TimeCheck_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class TimeCheck {
	InBetween,
	Equal,
	LessThan,
	LessEqualThan,
	GreaterEqualThan,
	GreaterThan
};

}

#endif