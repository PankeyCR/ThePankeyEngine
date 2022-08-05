
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Priority) || defined(ame_upToLevel_1)
	#define Priority_hpp
#endif

#ifndef Priority_hpp
#define Priority_hpp
#define Priority_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class Priority {
	First,
	Second,
	Third,
	Fourth,
	Fith,
	Never,
	Last,
	Normal,
	AlphaOmega,
	Lucky
};

}

#endif