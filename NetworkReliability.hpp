
#include "ame_Enviroment.hpp"

#if defined(DISABLE_NetworkReliability)
	#define NetworkReliability_hpp
#endif

#ifndef NetworkReliability_hpp
#define NetworkReliability_hpp
#define NetworkReliability_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class NetworkReliability {
	Tcp,
	Udp,
	Sdt
};

}

#endif