
#ifndef pankey_RawLogger_hpp
#define pankey_RawLogger_hpp
  
#include "pankey_String.hpp"
#include "System.hpp"

namespace ame{
  
	template<class T>
	void RawLogPrint_(int location, const pankey_String& name, const pankey_String& method, const pankey_String& type, const pankey_String& mns){
		System::print("Loggin class: ");
		System::print(name);
		System::print(" - Method: ");
		System::print(method);
		System::print(" - Location: ");
		System::print(location);
		System::print(" - Log: ");
		System::println(mns);
	}
  
}

#ifndef pankey_RawLog
	#define pankey_RawLog(pointer,location,name,method,type,mns) RawLogPrint_(location,name,method,type,mns)
#endif

#endif 

