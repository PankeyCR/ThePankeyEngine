
#ifndef pankey_Byte_hpp
	#define pankey_Byte_hpp

	#if pankey_Enviroment == pankey_Windows_Enviroment
		#include <bitset>
		typedef std::bitset<8> pankey_Byte;
	#elif pankey_IDE == pankey_Arduino_IDE
		#include "Arduino.h"
		typedef byte pankey_Byte;
		#define pankey_Byte_Null 0b10000001
		#define pankey_Byte_Zero 0b00000000
	#else
		// typedef char* pankey_Byte;
	#endif

#endif

