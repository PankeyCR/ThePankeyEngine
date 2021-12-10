

#ifndef TemplateMath_hpp
#define TemplateMath_hpp

#ifndef ame_Enviroment_Defined
	#include "Arduino.h"
#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif


namespace ame{

class TemplateMath{
	protected:
		
    public:
		TemplateMath(){}
		~TemplateMath(){}
		
		long exp(int x){}
		
		template<int x>
		long exp(){
			return 10 * exp<x-1>();
		}
};

template<>
long TemplateMath::exp<0>(){
	return 1l;
}

}

#endif 
