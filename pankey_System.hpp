
#ifndef pankey_System_hpp
	#define pankey_System_hpp

	#if pankey_Enviroment == pankey_Windows_Enviroment
		#include <stdio.h>
		#include "pankey_Print.hpp"
		#include "pankey_Printable.hpp"
		#include "ConsolePrint.hpp"
	#endif

	#if pankey_IDE == pankey_Arduino_IDE
		#include "Arduino.h"
		#include "Printable.h"
	#endif

	#include "pankey_String.hpp"

	namespace pankey{

		class System{
			public:
				static Print& console;
				virtual ~System(){}

				static long milliSeconds(){
					#if pankey_Enviroment == pankey_Windows_Enviroment
						return 0;
					#elif pankey_IDE == pankey_Arduino_IDE
						return millis();
					#else
						return 0;
					#endif
				}

				static long microSeconds(){
					#if pankey_Enviroment == pankey_Windows_Enviroment
						return 0;
					#elif pankey_IDE == pankey_Arduino_IDE
						return micros();
					#else
						return 0;
					#endif
				}

				static void sleep(long a_time){
					#if pankey_Enviroment == pankey_Windows_Enviroment
						
					#elif pankey_IDE == pankey_Arduino_IDE
						delay(a_time);
					#else
						
					#endif
				}

				static void recycle(){
					#if pankey_Enviroment == pankey_Windows_Enviroment
						
					#elif pankey_IDE == pankey_Arduino_IDE
					
					#else
						
					#endif
				}

			protected:

				System(){}

		};

		#if pankey_Enviroment == pankey_Windows_Enviroment
			ConsolePrint PConsole;
			Print& System::console = PConsole;
		#endif

		#if pankey_IDE == pankey_Arduino_IDE
			Print& System::console = Serial;
		#endif

	}

#endif
