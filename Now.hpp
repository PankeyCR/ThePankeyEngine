
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Now)
	#define Now_hpp
#endif

#ifndef Now_hpp
#define Now_hpp
#define Now_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "TimeCheck.hpp"

namespace ame{

class Now {
    public:
		static bool is(TimeCheck check,float time,float isNow,float offset){
			if(check == TimeCheck::Equal){
				return time == isNow;
			}
			if(check == TimeCheck::LessThan){
				return time < isNow;
			}
			if(check == TimeCheck::GreaterThan){
				return time > isNow;
			}
			if(check == TimeCheck::GreaterEqualThan){
				return time >= isNow;
			}
			if(check == TimeCheck::LessEqualThan){
				return time <= isNow;
			}
			if(check == TimeCheck::InBetween){
				return isNow<=time+offset && isNow>=time-offset; 
			} 
			return false;
		}
		
		static bool is(TimeCheck check,long time,long isNow,long offset){
			if(check == TimeCheck::Equal){
				return time == isNow;
			}
			if(check == TimeCheck::LessThan){
				return time < isNow;
			}
			if(check == TimeCheck::GreaterThan){
				return time > isNow;
			}
			if(check == TimeCheck::GreaterEqualThan){
				return time >= isNow;
			}
			if(check == TimeCheck::LessEqualThan){
				return time <= isNow;
			}
			if(check == TimeCheck::InBetween){
				return isNow<=time+offset && isNow>=time-offset; 
			} 
			return false;
		}
};

}

#endif