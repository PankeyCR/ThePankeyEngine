

#ifndef MultiServo_hpp
#define MultiServo_hpp

#include <Servo.h>

namespace ame{

class MultiServo {
	private:
	
    public:
		virtual Servo *getServo(int sel)=0;
		virtual void attach(int sel,int i)=0;
		virtual void detach(int sel,int i)=0;
		virtual int MoveServo(int sel,int angle)=0;
};

}

#endif 
