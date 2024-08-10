
#ifndef higgs_Byte_hpp
#define higgs_Byte_hpp

#if defined(higgs_Windows)
    #include <bitset>
	typedef std::bitset<8> higgs_Byte;
#elif defined(higgs_ArduinoIDE)
	#include "Arduino.h"
	typedef byte higgs_Byte;
	#define higgs_Byte_Null 0b10000001
	#define higgs_Byte_Zero 0b00000000
#else
	// typedef char* higgs_String;
#endif

#endif

