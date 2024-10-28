
#ifndef pankey_Watchdog_hpp
	#define pankey_Watchdog_hpp
	
	#if pankey_IDE == pankey_Generic_Esp32_Hardware
		#include "esp_task_wdt.h"
	#endif

	namespace pankey{

		class Watchdog{
			public:

				static void feed(){
					#if pankey_IDE == pankey_Generic_Esp32_Hardware
						esp_task_wdt_reset();
					#endif
				}

		};
	}

#endif

