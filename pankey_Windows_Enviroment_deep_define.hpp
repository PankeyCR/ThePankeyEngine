
#ifndef pankey_Hardware_Defined

	#if defined(__MINGW32__) || defined(_WIN32) || defined(__CYGWIN32__) || defined(_MSC_VER)
		#ifndef pankey_Level_Defined
			#define pankey_Level_15
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_Windows
			#define pankey_Enviroment_Defined
		#endif
		#ifndef pankey_Enviroment_Name
			#define pankey_Enviroment_Name "Windows"
		#endif
	#endif

#endif