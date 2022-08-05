
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RadioType)
	#define RadioType_hpp
#endif

#ifndef RadioType_hpp
#define RadioType_hpp
#define RadioType_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class RadioType {
	Spy,
	Mesh,
	Server,
	Client,
	P2P
};

}

#endif