
#ifndef X9C10x_hpp
#define X9C10x_hpp

#include "AbstractRead.hpp"
#include "TimeControl.hpp"
#include "TimeElapsed.hpp"

namespace ame{

class X9C10x : public AbstractRead , public TimeElapsed{
    public:
		X9C10x();
		virtual ~X9C10x();
		
		virtual bool increment(){
			
			return false;
		}
		virtual bool decrement(){
			
			return false;
		}
		virtual void initialize(Application *app){}
		virtual bool available(){}
		virtual bool Timer_Loop(){}
		virtual void Play(TimeControl* t){}
		virtual void Read(){
			digitalWrite(pulse, HIGH);	  
			delay(PULSE_TIMED);       
			digitalWrite(enable,LOW); 
			digitalWrite(pulse, LOW); 
			delay(PULSE_TIMED);  
			digitalWrite(enable,HIGH);
		}
		virtual float getReading(){}
	protected:
};

}
#endif 
