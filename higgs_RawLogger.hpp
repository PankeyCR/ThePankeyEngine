
#ifndef higgs_RawLogger_hpp
#define higgs_RawLogger_hpp
  
#include "higgs_String.hpp"
#include "System.hpp"

namespace ame{
  
	template<class T>
	void RawLogPrint_(int location, const higgs_String& name, const higgs_String& method, const higgs_String& type, const higgs_String& mns){
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

#ifndef higgs_RawLog
	#define higgs_RawLog(pointer,location,name,method,type,mns) RawLogPrint_(location,name,method,type,mns)
#endif

#endif 

