
/*
*
*	Macros for all types of enviroments:
*
*	higgs_Windows
*	higgs_Linux
*	higgs_Apple
*	higgs_RaspberryPiOS
*	higgs_ArduinoIDE
*	higgs_Expressif
*
*
*	Macros for all supported hardwares and its level:
*	
*	higgs_GENERIC_ARDUINO				higgs_Level_7
*	higgs_ARDUINO_MEGA					higgs_Level_6
*	higgs_ARDUINO_UNO					higgs_Level_4
*	higgs_ARDUINO_NANO					higgs_Level_1
*	higgs_ARDUINO_LEONARDO				higgs_Level_5
*	
*	higgs_GENERIC_ESP8266				higgs_Level_10
*
*	higgs_GENERIC_ESP32_S3				higgs_Level_12
*	higgs_GENERIC_ESP32					higgs_Level_12
*	higgs_ESP32_T2						higgs_Level_12
*	higgs_ESP32_DEV						higgs_Level_12
*	higgs_TTGO_T7						higgs_Level_12
*	higgs_ESPRESSIF_ESP32_S3_EYE		higgs_Level_12
*	higgs_ESP32_LILYGO_T_CAMERA_MINI	higgs_Level_12
*	higgs_ESP32_LILYGO_T_CAMERA_S3		higgs_Level_12
*	higgs_ESP32_LILYGO_CAMERA_PLUS		higgs_Level_12
*	higgs_ESP32_AUDIO_KIT				higgs_Level_12
*	higgs_ESP32_LORA_V1					higgs_Level_15
*	higgs_LILYGO_WATCH_2020_V1			higgs_Level_15
*	higgs_LILYGO_WATCH_2020_V2			higgs_Level_15
*	higgs_LILYGO_WATCH_2020_V3			higgs_Level_15
*	higgs_ESP32_POE_ETHERNET			higgs_Level_15
*
*	higgs_GENERIC_ADAFRUIT_FEATHER		higgs_Level_8
*	higgs_ADAFRUIT_FEATHER_M0			higgs_Level_8
*
*	higgs_RaspberryPi_3					higgs_Level_15
*	higgs_RaspberryPi_4					higgs_Level_15
*	
*	If a board is defined, the generic macro will be defined
*	
*	If a level is defined, the macro higgs_Level_Defined is defined
*	
*	If a board is defined, the macro higgs_Hardware_Defined is defined
*	
*	
*	char* enviroment_name = higgs_Enviroment_Name;
*	char* hardware_name = higgs_Hardware_Name;
*	
*	
*	
*	
*	
*/
#ifndef higgs_Enviroment_hpp
	#define higgs_Enviroment_hpp

	#include "higgs_Enviroment_predefined.hpp"
	#include "higgs_Enviroment_define.hpp"

	#include "higgs_Enviroment_predefined.hpp"
	#include "higgs_Enviroment_deep_define.hpp"
	//at this point the enviroment is defined

	#include "higgs_Hardware_define.hpp"

	#include "higgs_Render_define.hpp"

	#include "higgs_Level_define.hpp"

	#include "higgs_Logger_define.hpp"

	#include "higgs_Memory_Manager_define.hpp"
 
#endif