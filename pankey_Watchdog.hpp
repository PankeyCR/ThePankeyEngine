
#ifndef pankey_Watchdog_hpp
	#define pankey_Watchdog_hpp

	#ifdef pankey_Windows
	
	#endif
	
	#ifdef pankey_GENERIC_ESP32
		#include "esp_task_wdt.h"
	#endif

	namespace pankey{

		class Watchdog{
			public:

				static void feed(){
					#ifdef pankey_GENERIC_ESP32
						esp_task_wdt_reset();
					#endif
				}

		};
	}

#endif

