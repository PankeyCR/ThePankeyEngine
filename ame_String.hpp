
#ifndef ame_String_hpp
#define ame_String_hpp

#if defined(ame_Windows)
    #include <iostream>
	typedef std::string ame_String;
#elif defined(ame_ArduinoIDE)
	#include "Arduino.h"
	typedef String ame_String;
#else
	typedef char* ame_String;
#endif

#endif

