
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef aMath_hpp
#define aMath_hpp

#include "Arduino.h"

namespace ame{

class aMath{
    public:
	
		aMath(){
		}
		
		static float invSqrt(float x){
			float xhalf = 0.5f*x;
			int i = *(int*)&x;
			i = 0x5f3759df - (i>>1);
			x = *(float*)&i;
			x = x*(1.5f - xhalf*x*x);
			return x;
		}
		
		static float arccos(float x){
			return (float)acos((double)x);
		}
    
  
	private:	
};

}

#endif 

#endif 
