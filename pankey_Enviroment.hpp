
/*
*
*	Macros for all types of enviroments:
*
*	pankey_Windows
*	pankey_Linux
*	pankey_Apple
*	pankey_RaspberryPiOS
*	pankey_ArduinoIDE
*	pankey_Expressif
*
*
*	Macros for all supported hardwares and its level:
*	
*	pankey_GENERIC_ARDUINO				pankey_Level_7
*	pankey_ARDUINO_MEGA					pankey_Level_6
*	pankey_ARDUINO_UNO					pankey_Level_4
*	pankey_ARDUINO_NANO					pankey_Level_1
*	pankey_ARDUINO_LEONARDO				pankey_Level_5
*	
*	pankey_GENERIC_ESP8266				pankey_Level_10
*
*	pankey_GENERIC_ESP32_S3				pankey_Level_12
*	pankey_GENERIC_ESP32					pankey_Level_12
*	pankey_ESP32_T2						pankey_Level_12
*	pankey_ESP32_DEV						pankey_Level_12
*	pankey_TTGO_T7						pankey_Level_12
*	pankey_ESPRESSIF_ESP32_S3_EYE		pankey_Level_12
*	pankey_ESP32_LILYGO_T_CAMERA_MINI	pankey_Level_12
*	pankey_ESP32_LILYGO_T_CAMERA_S3		pankey_Level_12
*	pankey_ESP32_LILYGO_CAMERA_PLUS		pankey_Level_12
*	pankey_ESP32_AUDIO_KIT				pankey_Level_12
*	pankey_ESP32_LORA_V1					pankey_Level_15
*	pankey_LILYGO_WATCH_2020_V1			pankey_Level_15
*	pankey_LILYGO_WATCH_2020_V2			pankey_Level_15
*	pankey_LILYGO_WATCH_2020_V3			pankey_Level_15
*	pankey_ESP32_POE_ETHERNET			pankey_Level_15
*
*	pankey_GENERIC_ADAFRUIT_FEATHER		pankey_Level_8
*	pankey_ADAFRUIT_FEATHER_M0			pankey_Level_8
*
*	pankey_RaspberryPi_3					pankey_Level_15
*	pankey_RaspberryPi_4					pankey_Level_15
*	
*	If a board is defined, the generic macro will be defined
*	
*	If a level is defined, the macro pankey_Level_Defined is defined
*	
*	If a board is defined, the macro pankey_Hardware_Defined is defined
*	
*	
*	char* enviroment_name = pankey_Enviroment_Name;
*	char* hardware_name = pankey_Hardware_Name;
*	
*	
*	
*	
*	
*/
#ifndef pankey_Enviroment_hpp
	#define pankey_Enviroment_hpp

	#include "pankey_Enviroment_predefined.hpp"
	#include "pankey_Enviroment_define.hpp"

	#include "pankey_Enviroment_predefined.hpp"
	#include "pankey_Enviroment_deep_define.hpp"
	//at this point the enviroment is defined

	#include "pankey_Hardware_define.hpp"

	#include "pankey_Render_define.hpp"

	#include "pankey_Level_define.hpp"

	#include "pankey_Logger_define.hpp"

	#include "pankey_Memory_Manager_define.hpp"
 
#endif