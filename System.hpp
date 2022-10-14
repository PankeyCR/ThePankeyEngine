
#ifndef System_hpp
#define System_hpp
#define System_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include <stdio.h>
	#include "ame_Print.hpp"
	#include "ame_Printable.hpp"
	#include "ConsolePrint.hpp"
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "ame_String.hpp"

namespace ame{

class System{
    public:
		static Print& console;
		virtual ~System(){}

		static long milliSeconds(){
		#ifdef ame_Windows
			return 0;
		#elif defined(ame_ArduinoIDE)
			return millis();
		#else
			return 0;
		#endif
		}

		static long microSeconds(){
		#ifdef ame_Windows
			return 0;
		#elif defined(ame_ArduinoIDE)
			return micros();
		#else
			return 0;
		#endif
		}

		static void sleep(long a_time){
		#ifdef ame_Windows
			
		#elif defined(ame_ArduinoIDE)
			delay(a_time);
		#else
			
		#endif
		}

	protected:

		System(){}

};
#ifdef ame_Windows

ConsolePrint PConsole;
Print& System::console = PConsole;

#endif

#ifdef ame_ArduinoIDE
Print& System::console = Serial;
#endif


}

#endif
