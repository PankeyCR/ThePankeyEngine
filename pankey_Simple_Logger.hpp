
#ifndef pankey_Simple_Logger_hpp
#define pankey_Simple_Logger_hpp

#include "pankey_Logger_position.hpp"
#include "pankey_String.hpp"
#include "System.hpp"

namespace pankey{
	
template<class T>
void Simple_LogPrint_(void* a_log_pointer, int location, const pankey_String& name, const pankey_String& method, const pankey_String& type, T mns){

	// shrink expand

	// if(	method != "setPointer" /*&& 
	// 	method != "getIndex" && 
	// 	method != "insertLocalArrayPointer"/* && 
	// 	method != "getKeyIndexByLValue" /*&& method != "setMapEntry"*/){
	// 	return;
	// }
	#ifdef pankey_SystemFullLog
		System::console.print("Loggin class: ");
		System::console.print(name);
		System::console.print(" - Method: ");
		System::console.print(method);
		System::console.print(" - Location: ");
		System::console.print(location);
		System::console.print(" - Log: ");
		System::console.println(mns);
	#elif defined(pankey_Arduino_Log)
		Serial.print("Loggin class: ");
		Serial.print(name);
		Serial.print(" - Method: ");
		Serial.print(method);
		Serial.print(" - Location: ");
		Serial.print(location);
		Serial.print(" - Log: ");
		Serial.println(mns);
	#endif
}

}

#endif 

