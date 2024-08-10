
#ifndef higgs_List_Logger_hpp
#define higgs_List_Logger_hpp

#include "higgs_Logger_position.hpp"
#include "higgs_String.hpp"
#include "PrimitiveRawList.hpp"
#include "System.hpp"

namespace higgs{

PrimitiveRawList<higgs_String> g_log_class_list;
PrimitiveRawList<higgs_String> g_log_class_method_list;

void addClassToLog(higgs_String a_note){
	g_log_class_list.add(a_note);
}

void addClassMethodToLog(higgs_String a_note){
	g_log_class_method_list.add(a_note);
}
void addClassMethodToLog(higgs_String a_class, higgs_String a_method){
	g_log_class_list.add(a_class);
	g_log_class_method_list.add(a_method);
}
	
template<class T>
void List_LogPrint_(void* a_log_pointer, int location, const higgs_String& name, const higgs_String& method, const higgs_String& type, T mns){

	if(!g_log_class_list.contain(name)){
		return;
	}
	if(!g_log_class_method_list.contain("all")){
		if(!g_log_class_method_list.contain(method)){
			return;
		}
	}

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

