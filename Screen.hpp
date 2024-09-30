
#ifndef Screen_hpp
	#define Screen_hpp

	#ifdef pankey_Windows
		#include <stdio.h>
		#include "pankey_Print.hpp"
		#include "pankey_Printable.hpp"
		#include "ConsolePrint.hpp"
	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
	#endif

	#include "pankey_String.hpp"

	namespace pankey{

		class Screen{
			public:
				static Print& console;
				virtual ~Screen(){}

				static long milliSeconds(){
					#ifdef pankey_Windows
						return 0;
					#elif defined(pankey_ArduinoIDE)
						return millis();
					#else
						return 0;
					#endif
				}

				static long microSeconds(){
					#ifdef pankey_Windows
						return 0;
					#elif defined(pankey_ArduinoIDE)
						return micros();
					#else
						return 0;
					#endif
				}

				static void sleep(long a_time){
					#ifdef pankey_Windows
						
					#elif defined(pankey_ArduinoIDE)
						delay(a_time);
					#else
						
					#endif
				}

				static void recycle(){
					#ifdef pankey_Windows
						
					#elif defined(pankey_ArduinoIDE)
					
					#else
						
					#endif
				}

			protected:

				Screen(){}

		};

		#ifdef pankey_Windows
			ConsolePrint PConsole;
			Print& Screen::console = PConsole;
		#endif

		#ifdef pankey_ArduinoIDE
			Print& Screen::console = Serial;
		#endif

	}

#endif
