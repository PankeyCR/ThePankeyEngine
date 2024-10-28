
#ifndef pankey_Enviroment_deep_define_hpp
	#define pankey_Enviroment_deep_define_hpp
	
	#if defined(__MINGW32__) || defined(_WIN32) || defined(__CYGWIN32__) || defined(_MSC_VER)
		#ifndef pankey_Enviroment
			#define pankey_Enviroment pankey_Windows_Enviroment
		#endif
		#ifndef pankey_Enviroment_Name
			#define pankey_Enviroment_Name "Windows"
		#endif
	#endif

	#if defined(__APPLE__)
		#ifndef pankey_Enviroment
			#define pankey_Enviroment pankey_Apple_Enviroment
		#endif
		#ifndef pankey_Enviroment_Name
			#define pankey_Enviroment_Name "Apple"
		#endif
	#endif

	#if defined(__linux__)
		#ifndef pankey_Enviroment
			#define pankey_Enviroment pankey_Linux_Enviroment
		#endif
		#ifndef pankey_Enviroment_Name
			#define pankey_Enviroment_Name "Linux"
		#endif
	#endif

#endif