
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Processing)
	#define Processing_hpp
#endif

#ifndef Processing_hpp
#define Processing_hpp
#define Processing_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

template<class V>
class Processing{
	public:
		Processing();
		virtual ~Processing(){}
		
		virtual V processing(V plantValue, V controlValue);
		
	protected:
};

}

#endif