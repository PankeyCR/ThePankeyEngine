
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Rectifier)
	#define Rectifier_hpp
#endif

#ifndef Rectifier_hpp
#define Rectifier_hpp
#define Rectifier_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class Rectifier {
	Single_Phase,
	Three_Phase
};

}

#endif