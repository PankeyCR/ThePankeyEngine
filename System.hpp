
#ifndef System_hpp
#define System_hpp

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows
	#include <stdio.h>
	#include "higgs_Print.hpp"
	#include "higgs_Printable.hpp"
	#include "ConsolePrint.hpp"
#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

#include "higgs_String.hpp"

namespace higgs{

class System{
    public:
		static Print& console;
		virtual ~System(){}

		static long milliSeconds(){
			#ifdef higgs_Windows
				return 0;
			#elif defined(higgs_ArduinoIDE)
				return millis();
			#else
				return 0;
			#endif
		}

		static long microSeconds(){
			#ifdef higgs_Windows
				return 0;
			#elif defined(higgs_ArduinoIDE)
				return micros();
			#else
				return 0;
			#endif
		}

		static void sleep(long a_time){
			#ifdef higgs_Windows
				
			#elif defined(higgs_ArduinoIDE)
				delay(a_time);
			#else
				
			#endif
		}

		static void recycle(){
			#ifdef higgs_Windows
				
			#elif defined(higgs_ArduinoIDE)
			
			#else
				
			#endif
		}

	protected:

		System(){}

};
#ifdef higgs_Windows

ConsolePrint PConsole;
Print& System::console = PConsole;

#endif

#ifdef higgs_ArduinoIDE
Print& System::console = Serial;
#endif


}

#endif
