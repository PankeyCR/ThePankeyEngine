
#ifndef higgs_Simple_Logger_hpp
#define higgs_Simple_Logger_hpp

#include "higgs_Logger_position.hpp"
#include "higgs_String.hpp"
#include "System.hpp"

namespace higgs{
	
template<class T>
void Simple_LogPrint_(void* a_log_pointer, int location, const higgs_String& name, const higgs_String& method, const higgs_String& type, T mns){

	// shrink expand

	// if(	method != "setPointer" /*&& 
	// 	method != "getIndex" && 
	// 	method != "insertLocalArrayPointer"/* && 
	// 	method != "getKeyIndexByLValue" /*&& method != "setMapEntry"*/){
	// 	return;
	// }
	#ifdef higgs_SystemFullLog
		System::console.print("Loggin class: ");
		System::console.print(name);
		System::console.print(" - Method: ");
		System::console.print(method);
		System::console.print(" - Location: ");
		System::console.print(location);
		System::console.print(" - Log: ");
		System::console.println(mns);
	#elif defined(higgs_Arduino_Log)
		Serial.console.print("Loggin class: ");
		Serial.console.print(name);
		Serial.console.print(" - Method: ");
		Serial.console.print(method);
		Serial.console.print(" - Location: ");
		Serial.console.print(location);
		Serial.console.print(" - Log: ");
		Serial.console.println(mns);
	#endif
}

}

#endif 

