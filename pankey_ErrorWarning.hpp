
#ifndef pankey_ErrorWarning_hpp
#define pankey_ErrorWarning_hpp
#define pankey_ErrorWarning_AVAILABLE

#ifndef pankey_Enviroment_Defined

#endif

#ifdef pankey_Windows

#endif

#ifdef pankey_ArduinoIDE
	#include "Arduino.h"
#endif

#ifdef pankey_ErrorWarning
	#define pankey_ErrorHandler(e_ErrorType, e_Name, e_Method, e_Info) ErrorHandler_(e_ErrorType, e_Name, e_Method, e_Info)
	#define pankey_ErrorRelease() ErrorRelease_()
#else
	#define pankey_ErrorHandler(e_ErrorType, e_Name, e_Method, e_Info) 
	#define pankey_ErrorRelease() 
#endif

namespace ame{
	
//Error defines
#define NO_WIFI_CONEXION_ERROR 0
#define App_Crash_ERROR 0

#include "pankey_String.hpp"

void ErrorRelease_(){
}

void ErrorHandler_(int e_ErrorType, const pankey_String& name, const pankey_String& method, const pankey_String& e_Info){
}

template<class T>
struct ErrorClassReturn{
	static T* returnValue;
	
	static T set(T a_value){*returnValue = a_value;}
	static T get(){return *returnValue;}
	
	static T catchError(){
		pankey_ErrorHandler(App_Crash_ERROR, "", "", "");
	}
};

template<class T>
T* ErrorClassReturn<T>::returnValue = new T();

}

#endif