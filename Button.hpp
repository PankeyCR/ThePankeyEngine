
#include "ame_Enviroment.hpp"

#if defined(DISABLE_Button)
	#define Button_hpp
#endif

#ifndef Button_hpp
#define Button_hpp
#define Button_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

namespace ame{
	
class Button {
    private:
	
    public:
		virtual bool isPressed()=0;
		virtual bool isReleased()=0;
		virtual bool isClick()=0;
};

}

#endif