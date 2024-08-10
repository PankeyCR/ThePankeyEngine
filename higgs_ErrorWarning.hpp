
#ifndef higgs_ErrorWarning_hpp
#define higgs_ErrorWarning_hpp
#define higgs_ErrorWarning_AVAILABLE

#ifndef higgs_Enviroment_Defined

#endif

#ifdef higgs_Windows

#endif

#ifdef higgs_ArduinoIDE
	#include "Arduino.h"
#endif

#ifdef higgs_ErrorWarning
	#define higgs_ErrorHandler(e_ErrorType, e_Name, e_Method, e_Info) ErrorHandler_(e_ErrorType, e_Name, e_Method, e_Info)
	#define higgs_ErrorRelease() ErrorRelease_()
#else
	#define higgs_ErrorHandler(e_ErrorType, e_Name, e_Method, e_Info) 
	#define higgs_ErrorRelease() 
#endif

namespace ame{
	
//Error defines
#define NO_WIFI_CONEXION_ERROR 0
#define App_Crash_ERROR 0

#include "higgs_String.hpp"

void ErrorRelease_(){
}

void ErrorHandler_(int e_ErrorType, const higgs_String& name, const higgs_String& method, const higgs_String& e_Info){
}

template<class T>
struct ErrorClassReturn{
	static T* returnValue;
	
	static T set(T a_value){*returnValue = a_value;}
	static T get(){return *returnValue;}
	
	static T catchError(){
		higgs_ErrorHandler(App_Crash_ERROR, "", "", "");
	}
};

template<class T>
T* ErrorClassReturn<T>::returnValue = new T();

}

#endif