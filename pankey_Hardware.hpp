
/*
*	Macros for all supported hardwares:
*				
*	pankey_ARDUINO_MEGA					
*	pankey_ARDUINO_UNO					
*	pankey_ARDUINO_NANO					
*	pankey_ARDUINO_LEONARDO				
*	
*	pankey_ESP8266				
*			
*	pankey_ESP32_T2						
*	pankey_ESP32_DEV					
*	pankey_TTGO_T7						
*	pankey_ESPRESSIF_ESP32_S3_EYE		
*	pankey_ESP32_LILYGO_T_CAMERA_MINI	
*	pankey_ESP32_LILYGO_T_CAMERA_S3		
*	pankey_ESP32_LILYGO_CAMERA_PLUS		
*	pankey_ESP32_AUDIO_KIT				
*	pankey_ESP32_LORA_V1				
*	pankey_LILYGO_WATCH_2020_V1			
*	pankey_LILYGO_WATCH_2020_V2			
*	pankey_LILYGO_WATCH_2020_V3			
*	pankey_ESP32_POE_ETHERNET			
*	
*	pankey_ADAFRUIT_FEATHER_M0			
*
*	pankey_RaspberryPi_3				
*	pankey_RaspberryPi_4
*	
*	Macros for a family of chips:
*				
*	pankey_GENERIC_ARDUINO	
*	pankey_GENERIC_ESP8266	
*	pankey_GENERIC_ESP32_S3				
*	pankey_GENERIC_ESP32	
*	pankey_GENERIC_ADAFRUIT_FEATHER	
*	
*	Note hardware_name = pankey_Hardware_Name;
*	
*	
*/
#ifndef pankey_Hardware_hpp
	#define pankey_Hardware_hpp

	#define pankey_Arduino_Mega_Hardware					1
	#define pankey_Arduino_Uno_Hardware						2
	#define pankey_Arduino_Nano_Hardware					3
	#define pankey_Arduino_Leonardo_Hardware				4

	#define pankey_Esp32_T2_Hardware						5
	#define pankey_Esp32_Dev_Hardware						6
	#define pankey_Esp32_ttgo_T7_Hardware					7
	#define pankey_Espressif_Esp32_S3_EYE_Hardware			8
	#define pankey_Esp32_lilygo_T_CAMERA_MI_Hardware		9
	#define pankey_Esp32_lilygo_T_Camera_S3_Hardware		10
	#define pankey_Esp32_lilygo_Camera_Plus_Hardware		11
	#define pankey_Esp32_Audio_Kit_Hardware					12
	#define pankey_Esp32_Lora_V1_Hardware					13
	#define pankey_lilygo_Watch_2020_V1_Hardware			14
	#define pankey_lilygo_Watch_2020_V2_Hardware			15
	#define pankey_lilygo_Watch_2020_V3_Hardware			16
	#define pankey_Esp32_Poe_Ethernet_Hardware				17

	#define pankey_Adafruit_Feather_M0_Hardware				18
	
	#define pankey_RaspberryPi_3_Hardware					19
	#define pankey_RaspberryPi_4_Hardware					20

	#define pankey_Generic_Arduino_Hardware					101
	#define pankey_Generic_Esp8266_Hardware					102
	#define pankey_Generic_Esp32_S3_Hardware				103
	#define pankey_Generic_Esp32_Hardware					104
	#define pankey_Generic_Adafruit_Feather_Hardware		105
	
	#define pankey_No_Hardware								90
	#define pankey_No_Hardware_Name							"No_Hardware"
	
#endif