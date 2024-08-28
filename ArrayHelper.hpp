
#ifndef ArrayHelper_hpp
	#define ArrayHelper_hpp

	#include "Array.hpp"
	#include "System.hpp"

	#ifdef pankey_Windows
		#include "pankey_Printable.hpp"
		#include "pankey_Print.hpp"
	#endif

	#ifdef pankey_ArduinoIDE
		#include "Arduino.h"
		#include "Printable.h"
	#endif

    #ifdef ArrayHelper_LogApp
        #include "pankey_Logger_config.hpp"
        #define ArrayHelperLog(location,method,type,mns) pankey_Log((void*)this,location,"ArrayHelper",method,type,mns)
    #else
        #define ArrayHelperLog(location,method,type,mns)
    #endif

	namespace pankey{

		template<class T>
		void print(const Array<T>& a_array){
			ArrayHelperLog(pankey_Log_StartMethod, "Destructor", "println", "");
			for(int x = 0; x < a_array.getPosition(); x++){
				System::console.print(a_array.get(x));
			}
			ArrayHelperLog(pankey_Log_EndMethod, "Destructor", "println", "");
		}

		template<class T>
		void println(const Array<T>& a_array){
			ArrayHelperLog(pankey_Log_StartMethod, "Destructor", "println", "");
			for(int x = 0; x < a_array.getPosition(); x++){
				System::console.print(a_array.get(x));
				if(x == a_array.getPosition() - 1){
					break;
				}
				System::console.print(',');
			}
			System::console.println();
			ArrayHelperLog(pankey_Log_EndMethod, "Destructor", "println", "");
		}
	}

#endif