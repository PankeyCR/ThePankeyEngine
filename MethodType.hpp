
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodType)
	#define MethodType_hpp
#endif

#ifndef MethodType_hpp
#define MethodType_hpp
#define MethodType_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class MethodType {
	MethodInvokerType,
	MethodPointerInvokerType,
	ClassMethodInvokerType,
	PolicyBaseMethodInvokerType
};

}

#endif