
#ifndef pankey_Enviroment_deep_define_hpp
#define pankey_Enviroment_deep_define_hpp

///////////////////////////////////////////

#include "pankey_Windows_Enviroment_deep_define.hpp"
#include "pankey_ArduinoIDE_Enviroment_deep_define.hpp"

///////////////////////////////////////////

#ifndef pankey_Hardware_Defined

	#if defined(__APPLE__)
		#ifndef pankey_Level_Defined
			#define pankey_Level_15
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_Apple
			#define pankey_Enviroment_Defined
		#endif
	#endif

	#if defined(__linux__)
		#ifndef pankey_Level_Defined
			#define pankey_Level_15
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_Linux
			#define pankey_Enviroment_Defined
		#endif
	#endif
	
#endif

///////////////////////////////////////////

#endif