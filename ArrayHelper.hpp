
#ifndef NoteHelper_hpp
	#define NoteHelper_hpp

	#include "Array.hpp"
	#include "System.hpp"

#ifdef higgs_Windows
	#include "higgs_Printable.hpp"
	#include "higgs_Print.hpp"
#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
	#include "Printable.h"
#endif

    #ifdef NoteHelper_LogApp
        #include "higgs_Logger_config.hpp"
        #define NoteHelperLog(location,method,type,mns) higgs_Log((void*)this,location,"NoteHelper",method,type,mns)
    #else
        #define NoteHelperLog(location,method,type,mns)
    #endif

	namespace higgs{

		template<class T>
		void print(const Array<T>& a_array){
			NoteHelperLog(higgs_Log_StartMethod, "Destructor", "println", "");
			for(int x = 0; x < a_array.getPosition(); x++){
				System::console.print(a_array.get(x));
			}
			NoteHelperLog(higgs_Log_EndMethod, "Destructor", "println", "");
		}

		template<class T>
		void println(const Array<T>& a_array){
			NoteHelperLog(higgs_Log_StartMethod, "Destructor", "println", "");
			for(int x = 0; x < a_array.getPosition(); x++){
				System::console.print(a_array.get(x));
				if(x == a_array.getPosition() - 1){
					break;
				}
				System::console.print(',');
			}
			System::console.println();
			NoteHelperLog(higgs_Log_EndMethod, "Destructor", "println", "");
		}
	}

#endif