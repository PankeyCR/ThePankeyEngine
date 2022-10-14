
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

#ifdef ame_ErrorWarning
	#define ame_ErrorHandler(e_ErrorType, e_Name, e_Method, e_Info) ErrorHandler_(e_ErrorType, e_Name, e_Method, e_Info)
	#define ame_ErrorRelease() ErrorRelease_()
#else
	#define ame_ErrorHandler(e_ErrorType, e_Name, e_Method, e_Info) 
	#define ame_ErrorRelease() 
#endif

namespace ame{
	
//Error defines
#define NO_WIFI_CONEXION_ERROR 0
#define App_Crash_ERROR 0

#include "ame_String.hpp"

void ErrorRelease_(){
}

void ErrorHandler_(int e_ErrorType, const ame_String& name, const ame_String& method, const ame_String& e_Info){
}

template<class T>
struct ErrorClassReturn{
	static T* returnValue;
	
	static T set(T a_value){*returnValue = a_value;}
	static T get(){return *returnValue;}
	
	static T catchError(){
		ame_ErrorHandler(App_Crash_ERROR, "", "", "");
	}
};

template<class T>
T* ErrorClassReturn<T>::returnValue = new T();

}

#endif