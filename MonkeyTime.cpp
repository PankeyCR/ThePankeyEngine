

#ifndef MonkeyTime_cpp
#define MonkeyTime_cpp

#include "MonkeyTime.h"

	ame::MonkeyTime::MonkeyTime(){
        this->computeTime();
	}
	ame::MonkeyTime::~MonkeyTime(){
			
	}
	
    void ame::MonkeyTime::run() {
        this->running=true;
    }
	
    void ame::MonkeyTime::computeManualTime(long time) {
        if(this->running){
			this->microTimer = time - this->startTime;
			this->tpcTimer = time -this->currentTimer;
            this->currentTimer = time;
        }
    }
	
    void ame::MonkeyTime::computeTime() {
        if(this->running){
            long mm = micros();
			this->tpcTimer = mm -this->currentTimer;
            this->currentTimer = mm;
			this->microTimer = this->currentTimer-this->startTime;
        }
    }
	
    void ame::MonkeyTime::computeTime(long time) {
        if(this->running){
            long mm = micros();
			this->microTimer = this->currentTimer - this->startTime;
			this->tpcTimer = 0;
			if(time > mm -this->currentTimer){
				return;
			}
			this->tpcTimer = mm -this->currentTimer;
            this->currentTimer = mm;
        }
    }
		
	void ame::MonkeyTime::setStartTime(long time){
        this->startTime = time;
	}
	
	long ame::MonkeyTime::getStartTime() {
        return this->startTime;
	}
	
	void ame::MonkeyTime::setCurrentTime(long time){
        this->currentTimer = time;
	}

	long ame::MonkeyTime::getCurrentTimer(){
        return this->currentTimer;
	}

	void ame::MonkeyTime::setTime(long time){
        this->microTimer = time;
	}

	long ame::MonkeyTime::getTime(){
        return this->microTimer;
	}

	void ame::MonkeyTime::setEndTime(long time){
        this->endTime = time;
	}

	long ame::MonkeyTime::getEndTime() {
        return this->endTime;
	}

	void ame::MonkeyTime::start(long time){
        this->running= true;
        this->startTime = time;
	}

	void ame::MonkeyTime::start(){
        this->running= true;
        this->currentTimer= micros();
        this->startTime= this->currentTimer;
	}

	void ame::MonkeyTime::end(long time){
        this->running= false;
        this->endTime = time;
	}

	void ame::MonkeyTime::end(){
        this->running= false;
        this->endTime = this->currentTimer;
	}

	void ame::MonkeyTime::restart(long time){
        this->running= true;
        this->startTime= time;
        this->endTime = 0;
	}

	void ame::MonkeyTime::restart(){
        this->running= true;
        this->currentTimer= micros();
        this->startTime= this->currentTimer;
        this->endTime = 0;
	}

	bool ame::MonkeyTime::isRunning(){
        return this->running;
	}

	int ame::MonkeyTime::getTPC(){
        return this->tpcTimer;
	}

	int ame::MonkeyTime::getTPCandRestart(){
        int tpc = this->getTPC();
        this->restartTPC();
        return tpc;
	}

	void ame::MonkeyTime::restartTPC(){
        this->tpcTimer=0;   
	}

	void ame::MonkeyTime::Tick(){
        this->tickTimer++;
	}

	void ame::MonkeyTime::setTick(long tick){
        this->tickTimer = tick;
	}

	long ame::MonkeyTime::getTick(){
        return this->tickTimer;
	}

	void ame::MonkeyTime::resetTick(){
        this->tickTimer = 0;
	}

	bool ame::MonkeyTime::isNow(float time){
		return Now::is(TimeCheck::InBetween, this->getTime(), time,0.01f);
	}

	bool ame::MonkeyTime::isNow(float time,float offset){
		return Now::is(TimeCheck::InBetween, this->getTime(), time,offset);
	}

	bool ame::MonkeyTime::isNow(TimeCheck check,float time){
		return Now::is(check, this->getTime(), time,0.01f);
	}

	bool ame::MonkeyTime::isNow(TimeCheck check,float time,float offset){
		return Now::is(check, this->getTime(), time,offset);
	}

	void ame::MonkeyTime::setTimeOffset(TimeCheck check){
        this->timecheck = check;
	}

	ame::TimeCheck ame::MonkeyTime::getTimeOffset(){
        return this->timecheck;
	}


#endif 
