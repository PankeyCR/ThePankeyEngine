
#if defined(__AVR_ATmega2560__)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Arduino_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Arduino_Mega_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "__AVR_ATmega2560__"
	#endif
#endif

#if defined(ARDUINO_ARCH_AVR)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Arduino_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Generic_Arduino_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_ARCH_AVR"
	#endif
#endif

#if defined(ARDUINO_ARCH_ESP8266)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Esp8266_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Generic_Esp8266_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_ARCH_ESP8266"
	#endif
#endif

#if defined(ARDUINO_ESP32S3_DEV)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Esp32_S3_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Generic_Esp32_S3_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_ESP32S3_DEV"
	#endif
#endif

#if defined(ARDUINO_ESP32_DEV)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Esp32_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Generic_Esp32_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_ESP32_DEV"
	#endif
#endif

#if defined(ARDUINO_ARCH_ESP32)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Esp32_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Generic_Esp32_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_ARCH_ESP32"
	#endif
#endif

#if defined(ARDUINO_TTGO_T7_V14_Mini32)
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Esp32_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Esp32_ttgo_T7_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_TTGO_T7_V14_Mini32"
	#endif
#endif

#if defined(ARDUINO_SAMD_ZERO)//feather
	#ifndef pankey_Generic_Hardware
		#define pankey_Generic_Hardware pankey_Generic_Adafruit_Feather_Hardware
	#endif
	#ifndef pankey_Hardware
		#define pankey_Hardware pankey_Adafruit_Feather_M0_Hardware
	#endif
	#ifndef pankey_Hardware_Name
		#define pankey_Hardware_Name "ARDUINO_SAMD_ZERO"
	#endif
#endif