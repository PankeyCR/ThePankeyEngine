
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Random)
	#define Random_hpp
#endif

#ifndef Random_hpp
#define Random_hpp
#define Random_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

class Random{
	protected:
		float max=1;
		float min=0;
		float seed=1.0f;
	
    public:
		virtual ~Random(){}
		
		virtual void setMax(float Max){
			max = Max;
		}
		
		virtual void setMin(float Min){
			min = Min;
		}
		
		virtual float getMax() const{
			return max;
		}
		
		virtual float getMin() const{
			return min;
		}
		
		virtual void setSeed(float Seed){
			seed = Seed;
		}
		
		virtual float getSeed() const{
			return seed;
		}
		
		virtual float getRandom() const{
			return 0;
		}
};

}

#endif