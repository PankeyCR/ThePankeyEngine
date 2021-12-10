
/*
*	Level macro system
*	
*	Types of macros for level selection:
*	
*	ame_Level_
*	ame_upToLevel_ 
*	ame_untilLevel_ 
*	
*
*
*	Macros for all types of enviroments:
*
*	ame_Windows
*	ame_Ubuntu
*	ame_RaspberryPiOS
*	ame_ArduinoIDE
*	ame_Expressif
*
*
*	Macros for all supported hardwares and its level:
*	
*	ame_GENERIC_ARDUINO					ame_Level_7
*	ame_ARDUINO_MEGA					ame_Level_6
*	ame_ARDUINO_UNO						ame_Level_4
*	ame_ARDUINO_NANO					ame_Level_1
*	ame_ARDUINO_LEONARDO				ame_Level_5
*	
*	ame_GENERIC_ESP8266					ame_Level_10
*	ame_GENERIC_ESP32					ame_Level_12
*	ame_ESP32_T2						ame_Level_12
*	ame_ESP32_LILYGO_CAMERA_PLUS		ame_Level_12
*	ame_ESP32_AUDIO_KIT					ame_Level_12
*	ame_ESP32_POE_ETHERNET				ame_Level_15
*
*	ame_ADAFRUIT_FEATHER_M0				ame_Level_8
*
*	ame_RaspberryPi_3					ame_Level_15
*	ame_RaspberryPi_4					ame_Level_15
*	
*	
*	If a level is defined, the macro ame_Hardware_Defined is defined:
*	ame_Hardware_Defined
*	
*	If a board is defined, the macro ame_Level_Defined is defined:
*	ame_Level_Defined
*	
*/

#ifndef ame_Level_hpp
#define ame_Level_hpp


///////////////////////////////////////////

#if defined(ame_Windows) || defined(ame_Ubuntu) || defined(ame_RaspberryPiOS) || defined(ame_ArduinoIDE) || defined(ame_Expressif)
	#define ame_Enviroment_Defined
#endif

///////////////////////////////////////////

#if defined(ame_Level_1) || defined(ame_Level_2) || defined(ame_Level_3) || defined(ame_Level_4) || defined(ame_Level_5) || defined(ame_Level_6) || defined(ame_Level_7) || defined(ame_Level_8) || defined(ame_Level_9) || defined(ame_Level_10) || defined(ame_Level_11) || defined(ame_Level_12) || defined(ame_Level_13) || defined(ame_Level_14) || defined(ame_Level_15)
	#define ame_Level_Defined
#endif


///////////////////////////////////////////

#if defined(ame_GENERIC_ARDUINO)
	#ifndef ame_Level_Defined
		#define ame_Level_7
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ARDUINO_MEGA)
	#ifndef ame_Level_Defined
		#define ame_Level_6
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ARDUINO_UNO)
	#ifndef ame_Level_Defined
		#define ame_Level_4
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ARDUINO_NANO)
	#ifndef ame_Level_Defined
		#define ame_Level_1
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ARDUINO_LEONARDO)
	#ifndef ame_Level_Defined
		#define ame_Level_5
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_GENERIC_ESP8266)
	#ifndef ame_Level_Defined
		#define ame_Level_10
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_GENERIC_ESP32)
	#ifndef ame_Level_Defined
		#define ame_Level_12
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ESP32_T2)
	#ifndef ame_Level_Defined
		#define ame_Level_12
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ESP32_LILYGO_CAMERA_PLUS)
	#ifndef ame_Level_Defined
		#define ame_Level_12
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ESP32_POE_ETHERNET)
	#ifndef ame_Level_Defined
		#define ame_Level_15
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

#if defined(ame_ADAFRUIT_FEATHER_M0)
	#ifndef ame_Level_Defined
		#define ame_Level_8
		#define ame_Level_Defined
	#endif
	#ifndef ame_Hardware_Defined
		#define ame_Hardware_Defined
	#endif
	#ifndef ame_Enviroment_Defined
		#define ame_ArduinoIDE
		#define ame_Enviroment_Defined
	#endif
#endif

///////////////////////////////////////////

#ifndef ame_Hardware_Defined

	#if defined(__AVR_ATmega2560__)
		#define ame_ARDUINO_MEGA
		#define ame_Hardware_Defined
		#ifndef ame_Level_Defined
			#define ame_Level_6
		#endif
	#endif

	#if defined(ARDUINO_ARCH_AVR)
		#define ame_GENERIC_ARDUINO
		#define ame_Hardware_Defined
		#ifndef ame_Level_Defined
			#define ame_Level_6
		#endif
	#endif

	#if defined(ARDUINO_ARCH_ESP8266)
		#define ame_GENERIC_ESP8266
		#define ame_Hardware_Defined
		#ifndef ame_Level_Defined
			#define ame_Level_9
		#endif
	#endif

	#if defined(ARDUINO_ESP32_DEV)
		#define ame_GENERIC_ESP32
		#define ame_Hardware_Defined
		#ifndef ame_Level_Defined
			#define ame_Level_10
		#endif
	#endif

	#if defined(ARDUINO_SAMD_ZERO)//feather
		#define ame_ADAFRUIT_FEATHER_M0
		#define ame_Hardware_Defined
		#ifndef ame_Level_Defined
			#define ame_Level_8
			#define ame_Level_Defined
		#endif
	#endif
	
#endif

///////////////////////////////////////////

#if defined(ame_Windows)
	#ifndef ame_Level_Defined
		#define ame_Level_15
		#define ame_Level_Defined
	#endif
#endif

#if defined(ame_Ubuntu)
	#ifndef ame_Level_Defined
		#define ame_Level_15
		#define ame_Level_Defined
	#endif
#endif

#if defined(ame_ArduinoIDE)
	#ifndef ame_Level_Defined
		#define ame_Level_5
		#define ame_Level_Defined
	#endif
#endif

#if defined(ame_Expressif)
	#ifndef ame_Level_Defined
		#define ame_Level_15
		#define ame_Level_Defined
	#endif
#endif

///////////////////////////////////////////

///////////////////////////////////////////


#if defined(ame_Level_1)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_upToLevel_1
		#define ame_upToLevel_1
	#endif
	#ifndef ame_upToLevel_2
		#define ame_upToLevel_2
	#endif
	#ifndef ame_upToLevel_3
		#define ame_upToLevel_3
	#endif
	#ifndef ame_upToLevel_4
		#define ame_upToLevel_4
	#endif
	#ifndef ame_upToLevel_5
		#define ame_upToLevel_5
	#endif
	#ifndef ame_upToLevel_6
		#define ame_upToLevel_6
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_2)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_upToLevel_2
		#define ame_upToLevel_2
	#endif
	#ifndef ame_upToLevel_3
		#define ame_upToLevel_3
	#endif
	#ifndef ame_upToLevel_4
		#define ame_upToLevel_4
	#endif
	#ifndef ame_upToLevel_5
		#define ame_upToLevel_5
	#endif
	#ifndef ame_upToLevel_6
		#define ame_upToLevel_6
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_3)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_upToLevel_3
		#define ame_upToLevel_3
	#endif
	#ifndef ame_upToLevel_4
		#define ame_upToLevel_4
	#endif
	#ifndef ame_upToLevel_5
		#define ame_upToLevel_5
	#endif
	#ifndef ame_upToLevel_6
		#define ame_upToLevel_6
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_4)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_upToLevel_4
		#define ame_upToLevel_4
	#endif
	#ifndef ame_upToLevel_5
		#define ame_upToLevel_5
	#endif
	#ifndef ame_upToLevel_6
		#define ame_upToLevel_6
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_5)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_upToLevel_5
		#define ame_upToLevel_5
	#endif
	#ifndef ame_upToLevel_6
		#define ame_upToLevel_6
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_6)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_upToLevel_6
		#define ame_upToLevel_6
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_7)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_upToLevel_7
		#define ame_upToLevel_7
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_8)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_upToLevel_8
		#define ame_upToLevel_8
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_9)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_upToLevel_9
		#define ame_upToLevel_9
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_10)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_untilLevel_10
		#define ame_untilLevel_10
	#endif
	#ifndef ame_upToLevel_10
		#define ame_upToLevel_10
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_11)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_untilLevel_10
		#define ame_untilLevel_10
	#endif
	#ifndef ame_untilLevel_11
		#define ame_untilLevel_11
	#endif
	#ifndef ame_upToLevel_11
		#define ame_upToLevel_11
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_12)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_untilLevel_10
		#define ame_untilLevel_10
	#endif
	#ifndef ame_untilLevel_11
		#define ame_untilLevel_11
	#endif
	#ifndef ame_untilLevel_12
		#define ame_untilLevel_12
	#endif
	#ifndef ame_upToLevel_12
		#define ame_upToLevel_12
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_13)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_untilLevel_10
		#define ame_untilLevel_10
	#endif
	#ifndef ame_untilLevel_11
		#define ame_untilLevel_11
	#endif
	#ifndef ame_untilLevel_12
		#define ame_untilLevel_12
	#endif
	#ifndef ame_untilLevel_13
		#define ame_untilLevel_13
	#endif
	#ifndef ame_upToLevel_13
		#define ame_upToLevel_13
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_14)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_untilLevel_10
		#define ame_untilLevel_10
	#endif
	#ifndef ame_untilLevel_11
		#define ame_untilLevel_11
	#endif
	#ifndef ame_untilLevel_12
		#define ame_untilLevel_12
	#endif
	#ifndef ame_untilLevel_13
		#define ame_untilLevel_13
	#endif
	#ifndef ame_untilLevel_14
		#define ame_untilLevel_14
	#endif
	#ifndef ame_upToLevel_14
		#define ame_upToLevel_14
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif

#if defined(ame_Level_15)
	#ifndef ame_untilLevel_1
		#define ame_untilLevel_1
	#endif
	#ifndef ame_untilLevel_2
		#define ame_untilLevel_2
	#endif
	#ifndef ame_untilLevel_3
		#define ame_untilLevel_3
	#endif
	#ifndef ame_untilLevel_4
		#define ame_untilLevel_4
	#endif
	#ifndef ame_untilLevel_5
		#define ame_untilLevel_5
	#endif
	#ifndef ame_untilLevel_6
		#define ame_untilLevel_6
	#endif
	#ifndef ame_untilLevel_7
		#define ame_untilLevel_7
	#endif
	#ifndef ame_untilLevel_8
		#define ame_untilLevel_8
	#endif
	#ifndef ame_untilLevel_9
		#define ame_untilLevel_9
	#endif
	#ifndef ame_untilLevel_10
		#define ame_untilLevel_10
	#endif
	#ifndef ame_untilLevel_11
		#define ame_untilLevel_11
	#endif
	#ifndef ame_untilLevel_12
		#define ame_untilLevel_12
	#endif
	#ifndef ame_untilLevel_13
		#define ame_untilLevel_13
	#endif
	#ifndef ame_untilLevel_14
		#define ame_untilLevel_14
	#endif
	#ifndef ame_untilLevel_15
		#define ame_untilLevel_15
	#endif
	#ifndef ame_upToLevel_15
		#define ame_upToLevel_15
	#endif
#endif


#endif