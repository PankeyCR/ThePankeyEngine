
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef Button_hpp
#define Button_hpp

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

#endif 
