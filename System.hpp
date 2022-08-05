
#ifndef System_hpp
#define System_hpp
#define System_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
	#include <stdio.h>
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "ame_String.hpp"

namespace ame{

class System{
    public:
		virtual ~System(){}
		
		static long milliSeconds(){
		#ifdef ame_Windows
			return 0;
		#endif

		#ifdef ame_ArduinoIDE
			return millis();
		#endif
		}
		
		static long microSeconds(){
		#ifdef ame_Windows
			return 0;
		#endif

		#ifdef ame_ArduinoIDE
			return micros();
		#endif
		}
		
		static void print(const char* chr){
		#ifdef ame_Windows
            printf ("%s", chr);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(chr);
		#endif
		}
		
		static void println(const char* chr){
		#ifdef ame_Windows
            printf ("%s \n", chr);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(chr);
		#endif
		}
		
		static void print(const char& chr){
		#ifdef ame_Windows
            printf ("%s", chr);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(chr);
		#endif
		}
		
		static void println(const char& chr){
		#ifdef ame_Windows
            printf ("%s \n", chr);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(chr);
		#endif
		}
		
		static void println(const float& val){
		#ifdef ame_Windows
            printf ("%f \n", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(val);
		#endif
		}
		
		static void print(const float& val){
		#ifdef ame_Windows
            printf ("%f", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(val);
		#endif
		}
		
		static void println(const long& val){
		#ifdef ame_Windows
            printf ("%ld \n", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(val);
		#endif
		}
		
		static void print(const long& val){
		#ifdef ame_Windows
            printf ("%ld", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(val);
		#endif
		}
		
		static void println(const int& val){
		#ifdef ame_Windows
            printf ("%id \n", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(val);
		#endif
		}
		
		static void print(const int& val){
		#ifdef ame_Windows
            printf ("%id", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(val);
		#endif
		}
		
		static void println(const bool& val){
		#ifdef ame_Windows
            printf ("%bd \n", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(val);
		#endif
		}
		
		static void print(const bool& val){
		#ifdef ame_Windows
            printf ("%bd", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(val);
		#endif
		}
		
		static void println(const ame_String& val){
		#ifdef ame_Windows
            printf ("%sd \n", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.println(val);
		#endif
		}
		
		static void print(const ame_String& val){
		#ifdef ame_Windows
            printf ("%sd", val);
		#endif

		#ifdef ame_ArduinoIDE
			Serial.print(val);
		#endif
		}
		
		
	protected:
	
		System(){}
		
};

}

#endif