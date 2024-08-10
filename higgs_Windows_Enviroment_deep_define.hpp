
#ifndef higgs_Hardware_Defined

	#if defined(__MINGW32__) || defined(_WIN32) || defined(__CYGWIN32__) || defined(_MSC_VER)
		#ifndef higgs_Level_Defined
			#define higgs_Level_15
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_Windows
			#define higgs_Enviroment_Defined
		#endif
		#ifndef higgs_Enviroment_Name
			#define higgs_Enviroment_Name "Windows"
		#endif
	#endif

#endif