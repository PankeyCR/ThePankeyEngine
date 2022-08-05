
#if defined(DISABLE_ame_config)
	#define ame_config_hpp
#endif

#ifndef ame_config_hpp
#define ame_config_hpp
#define ame_config_AVAILABLE

//////////////////////////////////////////////////////////////

//enviroments

#ifndef ame_Enviroment_Defined
	// #define ame_Windows 
	// #define ame_Ubuntu 
	// #define ame_RaspberryPiOS 
	// #define ame_ArduinoIDE 
	// #define ame_Expressif 
#endif

//hardwares

#ifndef ame_Hardware_Defined
	// #define ame_GENERIC_ARDUINO 
	// #define ame_ARDUINO_MEGA 
	// #define ame_ARDUINO_UNO 
	// #define ame_ARDUINO_NANO 
	// #define ame_ARDUINO_LEONARDO 

	// #define ame_GENERIC_ESP32_S3 
	// #define ame_GENERIC_ESP8266 
	// #define ame_GENERIC_ESP32 
	// #define ame_ESP32_T2 
	// #define ame_ESP32_LILYGO_CAMERA_PLUS 
	// #define ame_ESP32_AUDIO_KIT 
	// #define ame_ESP32_LORA_V1  
	// #define ame_LILYGO_WATCH_2020_V1 
	// #define ame_LILYGO_WATCH_2020_V2 
	// #define ame_LILYGO_WATCH_2020_V3 
	// #define ame_ESP32_POE_ETHERNET 

	// #define ame_GENERIC_ADAFRUIT_FEATHER 
	// #define ame_ADAFRUIT_FEATHER_M0 

	// #define ame_RaspberryPi_3 
	// #define ame_RaspberryPi_4 
#endif


//logger

// #define ame_LogApp
// #define ame_LogPrint
// #define ame_Arduino_Log
// #define ame_SystemFullLog

// #define LinkedList_LogApp
// #define CSMS_LogApp
// #define Array_LogApp
// #define Note_LogApp
//#define Listener_LogApp
// #define SerialState_LogApp
//#define DefaultPortProtocol_LogApp
//#define StartEndPortProtocol_LogApp
//#define DefaultServerProtocol_LogApp
//#define IOPortProtocol_LogApp
//#define IOServerProtocol_LogApp
//#define SerialListenerState_LogApp
//#define AlwaysConnected_LogApp

// #define Note_LogDebugApp
//#define Listener_LogDebugApp
//#define SerialState_LogDebugApp
//#define DefaultPortProtocol_LogDebugApp
//#define StartEndPortProtocol_LogDebugApp
//#define DefaultServerProtocol_LogDebugApp
//#define IOPortProtocol_LogDebugApp
//#define IOServerProtocol_LogDebugApp
//#define SerialListenerState_LogDebugApp
//#define AlwaysConnected_LogDebugApp

#define DISABLE_Note
#define DISABLE_ByteArray
// #define DISABLE_AppSettings
// #define DISABLE_TimeControl
#define DISABLE_Memory
// #define DISABLE_MemoryManager
// #define DISABLE_MemoryPool
// #define DISABLE_RenderManager
// #define DISABLE_LinkedList





// #ifndef ame_LogDebug
	// #include "ame_debug.hpp"
	// #define ame_LogDebug(pointer,location,name,method,type) debug(pointer,location,name,method,type)
// #endif



//////////////////////////////////////////////////////////////

#endif