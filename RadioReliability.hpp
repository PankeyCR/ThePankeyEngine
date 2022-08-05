
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RadioReliability)
	#define RadioReliability_hpp
#endif

#ifndef RadioReliability_hpp
#define RadioReliability_hpp
#define RadioReliability_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class RadioReliability {
	Tcp,
	Udp,
	Sdt
};

}

#endif