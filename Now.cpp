

#ifndef Now_cpp
#define Now_cpp

#include "Now.h"

	bool ame::Now::is(ame::TimeCheck ofst,float time,float isNow,float offset){
		if(ofst == ame::TimeCheck::Equal){
			return time == isNow;
		}
		if(ofst == ame::TimeCheck::LessThan){
			return time < isNow;
		}
		if(ofst == ame::TimeCheck::GreaterThan){
			return time > isNow;
		}
		if(ofst == ame::TimeCheck::GreaterEqualThan){
			return time >= isNow;
		}
		if(ofst == ame::TimeCheck::LessEqualThan){
			return time <= isNow;
		}
		if(ofst == ame::TimeCheck::InBetween){
			return isNow<=time+offset && isNow>=time-offset; 
		} 
		return false;
	}


#endif 
