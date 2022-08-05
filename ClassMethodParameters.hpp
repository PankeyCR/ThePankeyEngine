
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassMethodParameters)
	#define ClassMethodParameters_hpp
#endif

#ifndef ClassMethodParameters_hpp
#define ClassMethodParameters_hpp
#define ClassMethodParameters_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{
	
template<class T>
struct ClassMethodParameters{
	// static Class_Method<T,R,Args...> m_method;
	
	static void add(Note a_name, int parameters){
		
	}
	
};

}

#endif