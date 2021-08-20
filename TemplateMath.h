

#ifndef TemplateMath_h
#define TemplateMath_h

#include "Arduino.h"

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
