

#ifndef SimpleServo_h
#define SimpleServo_h

#include <Servo.h>
#include <MultiServo.h>

namespace ame{

class SimpleServo : public MultiServo{
	private:
	
    public:
		int servoSize=0;
		Servo **servos;		
		SimpleServo();		
		~SimpleServo();
		void setup(int size);
		Servo *getServo(int sel);
		void attach(int sel,int i);
		void detach(int sel,int i);
		int MoveServo(int sel,int angle);
};

}

#endif 
