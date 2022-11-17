
/*
*
*	ame_Render_Windows_Console
*	ame_Render_
*	
*	
*	
*	
*	
*	
*
*
*	
*	
*	
*	
*/
/*
///////////////////////////////////////////

#if defined(ame_Windows) || defined(ame_Linux) || defined(ame_RaspberryPiOS) || defined(ame_ArduinoIDE) || defined(ame_Expressif)
	#ifndef ame_Enviroment_Defined
		#define ame_Enviroment_Defined
	#endif
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
	#ifndef ame_GENERIC_ARDUINO
		#define ame_GENERIC_ARDUINO
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
	#ifndef ame_GENERIC_ARDUINO
		#define ame_GENERIC_ARDUINO
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
	#ifndef ame_GENERIC_ARDUINO
		#define ame_GENERIC_ARDUINO
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
	#ifndef ame_GENERIC_ARDUINO
		#define ame_GENERIC_ARDUINO
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
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
	#ifndef ame_GENERIC_ADAFRUIT_FEATHER
		#define ame_GENERIC_ADAFRUIT_FEATHER
	#endif
#endif

#if defined(ame_ESP32_LORA_V1)
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
	#endif
#endif

#if defined(ame_LILYGO_WATCH_2020_V1)
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
	#endif
#endif

#if defined(ame_LILYGO_WATCH_2020_V2)
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
	#endif
#endif

#if defined(ame_LILYGO_WATCH_2020_V3)
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
	#endif
#endif

#if defined(ame_ESP32_DEV)
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
	#endif
#endif

#if defined(ame_TTGO_T7)
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
	#ifndef ame_GENERIC_ESP32
		#define ame_GENERIC_ESP32
	#endif
#endif

#if defined(ame_GENERIC_ESP32_S3)
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

//////////////////////////////////////////////////////

#if defined(ame_Windows)
	#ifndef ame_Level_Defined
		#define ame_Level_15
		#define ame_Level_Defined
	#endif
#endif

#if defined(ame_Linux)
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
*/