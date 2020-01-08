

#ifndef Now_cpp
#define Now_cpp

#include "Now.h"

	bool Now::is(TimeCheck ofst,float time,float isNow,float offset){
		if(ofst == TimeCheck::Equal){
			return time == isNow;
		}
		if(ofst == TimeCheck::LessThan){
			return time > isNow;
		}
		if(ofst == TimeCheck::GreaterThan){
			return time < isNow;
		}
		if(ofst == TimeCheck::GreaterEqualThan){
			return time >= isNow;
		}
		if(ofst == TimeCheck::GreaterEqualThan){
			return time <= isNow;
		}
		if(ofst == TimeCheck::InBetween){
			return isNow<=time+offset && isNow>=time-offset; 
		} 
		return false;
	}


#endif 
