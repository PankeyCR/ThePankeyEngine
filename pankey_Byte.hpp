
#ifndef pankey_Byte_hpp
#define pankey_Byte_hpp

#if defined(pankey_Windows)
    #include <bitset>
	typedef std::bitset<8> pankey_Byte;
#elif defined(pankey_ArduinoIDE)
	#include "Arduino.h"
	typedef byte pankey_Byte;
	#define pankey_Byte_Null 0b10000001
	#define pankey_Byte_Zero 0b00000000
#else
	// typedef char* pankey_String;
#endif

#endif

