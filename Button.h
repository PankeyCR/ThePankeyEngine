
#ifndef Button_h
#define Button_h

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
