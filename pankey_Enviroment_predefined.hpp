
#if pankey_Enviroment == pankey_Windows_Enviroment
	#ifndef pankey_Enviroment_Name
		#define pankey_Enviroment_Name "Windows"
	#endif
#endif

#if pankey_Enviroment == pankey_Linux_Enviroment
	#ifndef pankey_Enviroment_Name
		#define pankey_Enviroment_Name "Linux"
	#endif
#endif

#if pankey_Enviroment == pankey_Apple_Enviroment
	#ifndef pankey_Enviroment_Name
		#define pankey_Enviroment_Name "Apple"
	#endif
#endif

#if pankey_Enviroment == pankey_RaspberryPi_Enviroment
	#ifndef pankey_Enviroment_Name
		#define pankey_Enviroment_Name "RaspberryPiOS"
	#endif
#endif
