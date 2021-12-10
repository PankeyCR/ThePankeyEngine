
#include "ame_Level.hpp"

#if defined(ame_untilLevel_1)

#ifndef DelaySensor_hpp
#define DelaySensor_hpp

#include "MonkeyTime.hpp"
#include "TimeRecorder.hpp"
#include "trilean.hpp"

namespace ame{

class DelaySensor{
	protected:
		bool closem = false;
		bool openm = false;
		trilean state;
		float timing = 0;
		MonkeyTime* timer = nullptr;
		TimeRecorder openRecorder;
		TimeRecorder closeRecorder;
		TimeCheck timecheckm = TimeCheck::GreaterThan;
		float offsetm = 1.0f;
		int slpin=0;
		
    public:
		virtual ~DelaySensor(){}
		virtual DelaySensor* monkeytime(MonkeyTime* tim){
			this->timer = tim;
			return this;
		}
		
		virtual DelaySensor* delay(float tm){
			this->timing = tm;
			return this;
		}
	
		virtual DelaySensor* offset(float tm){
			this->offsetm = tm;
			return this;
		}
	
		virtual DelaySensor* timecheck(TimeCheck tm){
			this->timecheckm = tm;
			return this;
		}
	
		virtual DelaySensor* close(){
			this->state = false;
			return this;
		}
	
		virtual DelaySensor* open(){
			this->state = true;
			return this;
		}
	
		virtual DelaySensor* attach(int pin){
			this->slpin = pin;
			return this;
		}
	
		virtual void update(){
			if(this->timer == nullptr){
				return;
			}
			if(this->state==true){
				openRecorder+=this->timer->getTPC();
				closeRecorder.resetRecord();
			}
			if(this->state==false){
				closeRecorder+=this->timer->getTPC();
				openRecorder.resetRecord();
			}
			if(this->state==unknown){
				openRecorder.resetRecord();
				closeRecorder.resetRecord();
			}
			if(openRecorder.isNow(this->timecheckm,this->timing,this->offsetm)){
				this->openm = true;
			}
			if(closeRecorder.isNow(this->timecheckm,this->timing,this->offsetm)){
				this->closem = true;
			}
		}
	
		virtual bool isClose(){
			return this->closem;
		}
	
		virtual bool isOpen(){
			return this->openm;
		}
	
		virtual float closeTime(){
			return this->openRecorder.getRecord();
		}
	
		virtual float openTime(){
			return this->closeRecorder.getRecord();
		}
};

}

#endif 

#endif 
