
#ifndef pankey_Hardware_Defined

	#if defined(__AVR_ATmega2560__)
		#ifndef pankey_ARDUINO_MEGA
			#define pankey_ARDUINO_MEGA
		#endif
		#ifndef pankey_GENERIC_ARDUINO
			#define pankey_GENERIC_ARDUINO
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_6
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "__AVR_ATmega2560__"
		#endif
	#endif

	#if defined(ARDUINO_ARCH_AVR)
		#ifndef pankey_GENERIC_ARDUINO
			#define pankey_GENERIC_ARDUINO
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_6
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_ARCH_AVR"
		#endif
	#endif

	#if defined(ARDUINO_ARCH_ESP8266)
		#ifndef pankey_GENERIC_ESP8266
			#define pankey_GENERIC_ESP8266
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_9
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_ARCH_ESP8266"
		#endif
	#endif

	#if defined(ARDUINO_ESP32S3_DEV)
		#ifndef pankey_GENERIC_ESP32_S3
			#define pankey_GENERIC_ESP32_S3
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_15
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_ESP32S3_DEV"
		#endif
	#endif

	#if defined(ARDUINO_ESP32_DEV)
		#ifndef pankey_ESP32_DEV
			#define pankey_ESP32_DEV
		#endif
		#ifndef pankey_GENERIC_ESP32
			#define pankey_GENERIC_ESP32
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_10
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_ESP32_DEV"
		#endif
	#endif

	#if defined(ARDUINO_ARCH_ESP32)
		#ifndef pankey_GENERIC_ESP32
			#define pankey_GENERIC_ESP32
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_10
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_ARCH_ESP32"
		#endif
	#endif

	#if defined(ARDUINO_TTGO_T7_V14_Mini32)
		#ifndef pankey_TTGO_T7
			#define pankey_TTGO_T7
		#endif
		#ifndef pankey_GENERIC_ESP32
			#define pankey_GENERIC_ESP32
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_10
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_TTGO_T7_V14_Mini32"
		#endif
	#endif

	#if defined(ARDUINO_SAMD_ZERO)//feather
		#ifndef pankey_ADAFRUIT_FEATHER_M0
			#define pankey_ADAFRUIT_FEATHER_M0
		#endif
		#ifndef pankey_GENERIC_ADAFRUIT_FEATHER
			#define pankey_GENERIC_ADAFRUIT_FEATHER
		#endif
		#ifndef pankey_Hardware_Defined
			#define pankey_Hardware_Defined
		#endif
		#ifndef pankey_Level_Defined
			#define pankey_Level_8
			#define pankey_Level_Defined
		#endif
		#ifndef pankey_Enviroment_Defined
			#define pankey_ArduinoIDE
			#define pankey_Enviroment_Defined
			#define pankey_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef pankey_Hardware_Name
			#define pankey_Hardware_Name "ARDUINO_SAMD_ZERO"
		#endif
	#endif
	
#endif