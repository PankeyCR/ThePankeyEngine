
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ClassCount)
	#define ClassCount_hpp
#endif

#ifndef ClassCount_hpp
#define ClassCount_hpp
#define ClassCount_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{
	
static long class_count = 0;
	
long getGenericClassCount(){
	long i_value = class_count;
	class_count++;
	return i_value;
}
	
template<class cls>
struct ClassCount{
	static long value;
	static bool once;
	static long get(){
		if(once){
			value = class_count;
			class_count++;
			once = false;
		}
		return value;
	}
	static void set(long a_c){value = a_c;}
	static long getSize(){return class_count;}
};

template<class cls> long ClassCount<cls>::value = -1;
template<class cls> bool ClassCount<cls>::once = true;

}

#endif