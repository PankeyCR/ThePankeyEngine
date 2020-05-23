

#ifndef MonkeyTime_cpp
#define MonkeyTime_cpp

#include "MonkeyTime.h"

	MonkeyTime::MonkeyTime(){
        this->computeTime();
	}
	MonkeyTime::~MonkeyTime(){
			
	}
	
    void MonkeyTime::run() {
        this->running=true;
    }
	
    void MonkeyTime::computeManualTime(long time) {
        if(this->running){
			this->microTimer = time - this->startTime;
			this->tpcTimer = time -this->currentTimer;
            this->currentTimer = time;
        }
    }
	
    void MonkeyTime::computeTime() {
        if(this->running){
            long mm = micros();
			this->tpcTimer = mm -this->currentTimer;
            this->currentTimer = mm;
			this->microTimer = this->currentTimer-this->startTime;
        }
    }
	
    void MonkeyTime::computeTime(long time) {
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
		
	void MonkeyTime::setStartTime(long time){
        this->startTime = time;
	}
	
	long MonkeyTime::getStartTime() {
        return this->startTime;
	}
	
	void MonkeyTime::setCurrentTime(long time){
        this->currentTimer = time;
	}

	long MonkeyTime::getCurrentTimer(){
        return this->currentTimer;
	}

	void MonkeyTime::setTime(long time){
        this->microTimer = time;
	}

	long MonkeyTime::getTime(){
        return this->microTimer;
	}

	void MonkeyTime::setEndTime(long time){
        this->endTime = time;
	}

	long MonkeyTime::getEndTime() {
        return this->endTime;
	}

	void MonkeyTime::start(long time){
        this->running= true;
        this->startTime = time;
	}

	void MonkeyTime::start(){
        this->running= true;
        this->currentTimer= micros();
        this->startTime= this->currentTimer;
	}

	void MonkeyTime::end(long time){
        this->running= false;
        this->endTime = time;
	}

	void MonkeyTime::end(){
        this->running= false;
        this->endTime = this->currentTimer;
	}

	void MonkeyTime::restart(long time){
        this->running= true;
        this->startTime= time;
        this->endTime = 0;
	}

	void MonkeyTime::restart(){
        this->running= true;
        this->currentTimer= micros();
        this->startTime= this->currentTimer;
        this->endTime = 0;
	}

	bool MonkeyTime::isRunning(){
        return this->running;
	}

	int MonkeyTime::getTPC(){
        return this->tpcTimer;
	}

	int MonkeyTime::getTPCandRestart(){
        int tpc = this->getTPC();
        this->restartTPC();
        return tpc;
	}

	void MonkeyTime::restartTPC(){
        this->tpcTimer=0;   
	}

	void MonkeyTime::Tick(){
        this->tickTimer++;
	}

	void MonkeyTime::setTick(long tick){
        this->tickTimer = tick;
	}

	long MonkeyTime::getTick(){
        return this->tickTimer;
	}

	void MonkeyTime::resetTick(){
        this->tickTimer = 0;
	}

	bool MonkeyTime::isNow(float time){
		return Now::is(TimeCheck::InBetween, this->getTime(), time,0.01f);
	}

	bool MonkeyTime::isNow(float time,float offset){
		return Now::is(TimeCheck::InBetween, this->getTime(), time,offset);
	}

	bool MonkeyTime::isNow(TimeCheck check,float time){
		return Now::is(check, this->getTime(), time,0.01f);
	}

	bool MonkeyTime::isNow(TimeCheck check,float time,float offset){
		return Now::is(check, this->getTime(), time,offset);
	}

	void MonkeyTime::setTimeOffset(TimeCheck check){
        this->timecheck = check;
	}

	TimeCheck MonkeyTime::getTimeOffset(){
        return this->timecheck;
	}


#endif 
