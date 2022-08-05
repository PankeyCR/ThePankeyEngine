
#ifndef ame_ErrorWarning_hpp
#define ame_ErrorWarning_hpp
#define ame_ErrorWarning_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#ifndef ame_ErrorWarning
	#define ame_ErrorWarning(e_ErrorType, e_Info) ErrorHandler_(e_ErrorType, e_Info)
#else
	#define ame_ErrorWarning(e_ErrorType, e_Info) 
#endif

namespace ame{
	
//Error defines
#define NO_WIFI_CONEXION_ERROR 0

#include "ame_String.hpp"

void ErrorHandler_(int e_ErrorType, const ame_String& e_Info){
	
}

template<class T>
struct ErrorClassReturn{
	static T* returnValue;
	
	static T set(T a_value){*returnValue = a_value;}
	static T get(){return *returnValue;}
	
	static T catchError(){
		ame_ErrorWarning(RETURN_ERROR, "");
	}
};

template<class T>
T* ErrorClassReturn<T>::returnValue = new T();

}

#endif