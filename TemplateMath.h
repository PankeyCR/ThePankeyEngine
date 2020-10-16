

#ifndef TemplateMath_h
#define TemplateMath_h

#include "Arduino.h"

class TemplateMath{
	protected:
		
    public:
		TemplateMath();
		~TemplateMath();
		
		long exp(int x);
		
		template<int x>
		long exp(){
			return 10 * exp<x-1>();
		}
};

#endif 
