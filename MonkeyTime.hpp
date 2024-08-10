
#ifndef MonkeyTime_hpp
#define MonkeyTime_hpp

#include "Now.hpp"
#include "TimeCheck.hpp"

namespace higgs{

class MonkeyTime {
    public:		
		MonkeyTime(){
			this->computeTime();
		}
		virtual ~MonkeyTime(){}
		
		virtual void run(){
			this->running=true;
		}
		
		virtual void computeManualTime(long time){
			if(this->running){
				this->microTimer = time - this->startTime;
				this->tpcTimer = ((float)(time - this->currentTimer)) / ((float)(scale));
				this->currentTimer = time;
			}
		}
		
		virtual void computeManualTime(long time, long cycle){
			if(this->running){
				if(cycle > time -this->currentTimer){
					return;
				}
				this->microTimer = time - this->startTime;
				this->tpcTimer = ((float)(time - this->currentTimer)) / ((float)(scale));
				this->currentTimer = time;
			}
		}
		
		virtual void computeTime(){
			computeManualTime(micros());
		}

		virtual void computeTime(long cycle){
			computeManualTime(micros(), cycle);
		}
			
		virtual void setStartTime(long time){
			this->startTime = time;
		}

		virtual long getStartTime(){
			return this->startTime;
		}

		virtual void setCurrentTime(long time){
			this->currentTimer = time;
		}

		virtual long getCurrentTimer(){
			return this->currentTimer;
		}

		virtual void setTime(long time){
			this->microTimer = time;
		}

		virtual long getTime(){
			return this->microTimer;
		}

		virtual void setEndTime(long time){
			this->endTime = time;
		}

		virtual long getEndTime(){
			return this->endTime;
		}

		virtual void start(long time){
			this->running= true;
			this->startTime = time;
		}

		virtual void start(){
			this->running= true;
			this->currentTimer= micros();
			this->startTime= this->currentTimer;
		}

		virtual void end(long time){
			this->running= false;
			this->endTime = time;
		}

		virtual void end(){
			this->running= false;
			this->endTime = this->currentTimer;
		}

		virtual void restart(long time){
			this->running= true;
			this->startTime= time;
			this->endTime = 0;
		}

		virtual void restart(){
			this->running= true;
			this->currentTimer= micros();
			this->startTime= this->currentTimer;
			this->endTime = 0;
		}

		virtual bool isRunning(){
			return this->running;
		}

		virtual float getTPC(){
			return this->tpcTimer;
		}

		virtual int getTPCandRestart(){
			float tpc = this->getTPC();
			this->restartTPC();
			return tpc;
		}

		virtual void restartTPC(){
			this->tpcTimer=0;   
		}

		virtual void Tick(){
			this->tickTimer++;
		}
		
		virtual void setTick(long tick){
			this->tickTimer = tick;
		}

		virtual long getTick(){
			return this->tickTimer;
		}

		virtual void resetTick(){
			this->tickTimer = 0;
		}

		virtual bool isNow(long time){
			return Now::is(TimeCheck::InBetween, this->getTime(), time,1000l);
		}

		virtual bool isNow(long time,long offset){
			return Now::is(TimeCheck::InBetween, this->getTime(), time,offset);
		}

		virtual bool isNow(TimeCheck check,long time){
			return Now::is(check, this->getTime(), time,1000l);
		}

		virtual bool isNow(TimeCheck check,long time,long offset){
			return Now::is(check, this->getTime(), time,offset);
		}

		virtual void setTimeOffset(TimeCheck check){
			this->timecheck = check;
		}

		virtual TimeCheck getTimeOffset(){
			return this->timecheck;
		}
		
    
	protected:	
		long currentTimer = 0;
		long microTimer = 0;
		float tpcTimer = 0.0f;
		long tickTimer = 0;
    
		long startTime = 0;
		long scale = 1000000;
		long endTime = 0;
		bool running = false;  
		TimeCheck timecheck;
		bool enable;
		long _micros = 1000000;
};

}

#endif