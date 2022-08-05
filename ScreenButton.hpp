
#include "ame_Enviroment.hpp"

#if defined(DISABLE_ScreenButton) || defined(ame_upToLevel_1)
	#define ScreenButton_hpp
#endif

#ifndef ScreenButton_hpp
#define ScreenButton_hpp
#define ScreenButton_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Button.hpp"
#include "Vector2f.hpp"

namespace ame{

class ScreenButton : public Button{
    private:
	
    public:
		virtual Vector2f getCursor()=0;
		virtual int getPressure()=0;
};

}

#endif