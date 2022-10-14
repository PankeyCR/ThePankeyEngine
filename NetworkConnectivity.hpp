
#include "ame_Enviroment.hpp"

#if defined(DISABLE_NetworkConnectivity)
	#define NetworkConnectivity_hpp
#endif

#ifndef NetworkConnectivity_hpp
#define NetworkConnectivity_hpp
#define NetworkConnectivity_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class NetworkConnectivity {
	Spy,
	Mesh,
	Server,
	Client,
	P2P
};

}

#endif