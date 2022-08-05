
#include "ame_Enviroment.hpp"

#if defined(DISABLE_aMath)
	#define aMath_hpp
#endif

#ifndef aMath_hpp
#define aMath_hpp
#define aMath_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

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