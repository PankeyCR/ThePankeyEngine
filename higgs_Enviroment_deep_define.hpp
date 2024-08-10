
#ifndef higgs_Enviroment_deep_define_hpp
#define higgs_Enviroment_deep_define_hpp

///////////////////////////////////////////

#include "higgs_Windows_Enviroment_deep_define.hpp"
#include "higgs_ArduinoIDE_Enviroment_deep_define.hpp"

///////////////////////////////////////////

#ifndef higgs_Hardware_Defined

	#if defined(__APPLE__)
		#ifndef higgs_Level_Defined
			#define higgs_Level_15
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_Apple
			#define higgs_Enviroment_Defined
		#endif
	#endif

	#if defined(__linux__)
		#ifndef higgs_Level_Defined
			#define higgs_Level_15
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_Linux
			#define higgs_Enviroment_Defined
		#endif
	#endif
	
#endif

///////////////////////////////////////////

#endif