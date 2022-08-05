
#ifndef ame_Byte_hpp
#define ame_Byte_hpp

#include "ame_Enviroment_config.hpp"
#include "ame_Enviroment_define.hpp"

#if defined(ame_Windows)
    #include <bitset>
	typedef std::bitset<8> ame_Byte;
#elif defined(ame_ArduinoIDE)
	#include "Arduino.h"
	typedef byte ame_Byte;
	#define ame_Byte_Null 0b10000001
	#define ame_Byte_Zero 0b00000000
#else
	// typedef char* ame_String;
#endif

#endif

