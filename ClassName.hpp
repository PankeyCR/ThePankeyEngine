
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassName)
	#define ClassName_hpp
#endif

#ifndef ClassName_hpp
#define ClassName_hpp
#define ClassName_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Note.hpp"

namespace ame{
	
template<class cls>
struct ClassName{
	static Note className;
	
	static Note get(){return className;}
	static void set(Note a_note){className = a_note;}
};

template<class cls> Note ClassName<cls>::className = "Default";

}

#endif