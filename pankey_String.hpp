
#ifndef pankey_String_hpp
#define pankey_String_hpp

#if defined(pankey_Windows)
    #include <iostream>
	typedef std::string pankey_String;
#elif defined(pankey_ArduinoIDE)
	#include "Arduino.h"
	typedef String pankey_String;
#else
	typedef char* pankey_String;
#endif

#endif

