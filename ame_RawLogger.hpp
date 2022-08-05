
#ifndef ame_RawLogger_hpp
#define ame_RawLogger_hpp
  
#include "ame_String.hpp"
#include "System.hpp"

namespace ame{
  
	template<class T>
	void RawLogPrint_(int location, const ame_String& name, const ame_String& method, const ame_String& type, const ame_String& mns){
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

#ifndef ame_RawLog
	#define ame_RawLog(pointer,location,name,method,type,mns) RawLogPrint_(location,name,method,type,mns)
#endif

#endif 

