
#ifndef pankey_List_Logger_hpp
#define pankey_List_Logger_hpp

#include "pankey_Logger_position.hpp"
#include "pankey_String.hpp"
#include "PrimitiveRawList.hpp"
#include "System.hpp"

namespace pankey{

PrimitiveRawList<pankey_String> g_log_class_list;
PrimitiveRawList<pankey_String> g_log_class_method_list;

void addClassToLog(pankey_String a_note){
	g_log_class_list.add(a_note);
}

void addClassMethodToLog(pankey_String a_note){
	g_log_class_method_list.add(a_note);
}
void addClassMethodToLog(pankey_String a_class, pankey_String a_method){
	g_log_class_list.add(a_class);
	g_log_class_method_list.add(a_method);
}
	
template<class T>
void List_LogPrint_(void* a_log_pointer, int location, const pankey_String& name, const pankey_String& method, const pankey_String& type, T mns){

	if(!g_log_class_list.contain(name)){
		return;
	}
	if(!g_log_class_method_list.contain("all")){
		if(!g_log_class_method_list.contain(method)){
			return;
		}
	}

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

