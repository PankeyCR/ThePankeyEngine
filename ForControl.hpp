
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ForControl)
	#define ForControl_hpp
#endif

#ifndef ForControl_hpp
#define ForControl_hpp
#define ForControl_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{

enum class ForControl {
	nothing,
	end,
	repite,
	restart,
	next,
	back,
	jumpNext,
	jumpBack
};

int ForIntIncrement(int x, ForControl c){
	if(c == ForControl::repite){
		return x;
	}
	if(c == ForControl::restart){
		return 0;
	}
	if(c == ForControl::next){
		return x+1;
	}
	if(c == ForControl::back){
		return x-1;
	}
	if(c == ForControl::jumpNext){
		return x+2;
	}
	if(c == ForControl::jumpBack){
		return x-2;
	}
	return x+1;
}

}

#define ForReturn(){\
	if(c == ForControl::repite){\
		return x;\
	}\
	if(c == ForControl::restart){\
		return 0;\
	}\
	if(c == ForControl::next){\
		return x+1;\
	}\
	if(c == ForControl::back){\
		return x-1;\
	}\
	if(c == ForControl::jumpNext){\
		return x+2;\
	}\
	if(c == ForControl::jumpBack){\
		return x-2;\
	}\
}


#endif