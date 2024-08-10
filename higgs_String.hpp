
#ifndef higgs_String_hpp
#define higgs_String_hpp

#if defined(higgs_Windows)
    #include <iostream>
	typedef std::string higgs_String;
#elif defined(higgs_ArduinoIDE)
	#include "Arduino.h"
	typedef String higgs_String;
#else
	typedef char* higgs_String;
#endif

#endif

