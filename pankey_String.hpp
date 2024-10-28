
#ifndef pankey_String_hpp
#define pankey_String_hpp

#if pankey_Enviroment == pankey_Windows_Enviroment
    #include <iostream>
	typedef std::string pankey_String;
#elif pankey_IDE == pankey_Arduino_IDE
	#include "Arduino.h"
	typedef String pankey_String;
#else
	typedef char* pankey_String;
#endif

#endif

