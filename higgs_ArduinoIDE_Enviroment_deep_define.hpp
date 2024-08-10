
#ifndef higgs_Hardware_Defined

	#if defined(__AVR_ATmega2560__)
		#ifndef higgs_ARDUINO_MEGA
			#define higgs_ARDUINO_MEGA
		#endif
		#ifndef higgs_GENERIC_ARDUINO
			#define higgs_GENERIC_ARDUINO
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_6
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "__AVR_ATmega2560__"
		#endif
	#endif

	#if defined(ARDUINO_ARCH_AVR)
		#ifndef higgs_GENERIC_ARDUINO
			#define higgs_GENERIC_ARDUINO
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_6
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_ARCH_AVR"
		#endif
	#endif

	#if defined(ARDUINO_ARCH_ESP8266)
		#ifndef higgs_GENERIC_ESP8266
			#define higgs_GENERIC_ESP8266
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_9
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_ARCH_ESP8266"
		#endif
	#endif

	#if defined(ARDUINO_ESP32S3_DEV)
		#ifndef higgs_GENERIC_ESP32_S3
			#define higgs_GENERIC_ESP32_S3
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_15
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_ESP32S3_DEV"
		#endif
	#endif

	#if defined(ARDUINO_ESP32_DEV)
		#ifndef higgs_ESP32_DEV
			#define higgs_ESP32_DEV
		#endif
		#ifndef higgs_GENERIC_ESP32
			#define higgs_GENERIC_ESP32
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_10
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_ESP32_DEV"
		#endif
	#endif

	#if defined(ARDUINO_ARCH_ESP32)
		#ifndef higgs_GENERIC_ESP32
			#define higgs_GENERIC_ESP32
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_10
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_ARCH_ESP32"
		#endif
	#endif

	#if defined(ARDUINO_TTGO_T7_V14_Mini32)
		#ifndef higgs_TTGO_T7
			#define higgs_TTGO_T7
		#endif
		#ifndef higgs_GENERIC_ESP32
			#define higgs_GENERIC_ESP32
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_10
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_TTGO_T7_V14_Mini32"
		#endif
	#endif

	#if defined(ARDUINO_SAMD_ZERO)//feather
		#ifndef higgs_ADAFRUIT_FEATHER_M0
			#define higgs_ADAFRUIT_FEATHER_M0
		#endif
		#ifndef higgs_GENERIC_ADAFRUIT_FEATHER
			#define higgs_GENERIC_ADAFRUIT_FEATHER
		#endif
		#ifndef higgs_Hardware_Defined
			#define higgs_Hardware_Defined
		#endif
		#ifndef higgs_Level_Defined
			#define higgs_Level_8
			#define higgs_Level_Defined
		#endif
		#ifndef higgs_Enviroment_Defined
			#define higgs_ArduinoIDE
			#define higgs_Enviroment_Defined
			#define higgs_Enviroment_Name "ArduinoIDE"
		#endif
		#ifndef higgs_Hardware_Name
			#define higgs_Hardware_Name "ARDUINO_SAMD_ZERO"
		#endif
	#endif
	
#endif