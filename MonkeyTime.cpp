

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
			if(time < mm -this->currentTimer){
				return;
			}
			this->tpcTimer = mm -this->currentTimer;
            this->currentTimer = mm;
			this->microTimer = this->currentTimer-this->startTime;
        }
    }
	
    void MonkeyTime::computeScaleTime(float time) {
        if(this->running){
            long mm = micros();
			if(time < (float)((float)(mm -this->startTime)/(float)this->scale)){
				return;
			}
			this->tpcTimer = mm -this->currentTimer;
            this->currentTimer = mm;
			this->microTimer = this->currentTimer-this->startTime;
        }
    }
		
	void MonkeyTime::setStartTime(long time){
        this->startTime = time;
	}
	
	float MonkeyTime::getStartScaleTime() {
        return (float)((float) this->startTime/(float)this->scale);
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

	float MonkeyTime::getEndScaleTime(){
        return (float)((float)this->endTime/(float)this->scale);
	}

	void MonkeyTime::setScale(long scale){
        this->scale = scale;
	}

	void MonkeyTime::setScale(TimeScale scale){
		if(scale == TimeScale::MicroSecond){
			this->scale = 1l;
			return;
		}
		if(scale == TimeScale::MilliSecond){
			this->scale = 1000l;
			return;
		}
		if(scale == TimeScale::CentiSecond){
			this->scale = 10000l;
			return;
		}
		if(scale == TimeScale::DeciSecond){
			this->scale = 100000l;
			return;
		}
		if(scale == TimeScale::Second){
			this->scale = 1000000l;
			return;
		}
		if(scale == TimeScale::DecaSecond){
			this->scale = 10000000l;
			return;
		}
		if(scale == TimeScale::HectoSecond){
			this->scale = 100000000l;
			return;
		}
		if(scale == TimeScale::KiloSecond){
			this->scale = 1000000000l;
			return;
		}
	}

	long MonkeyTime::getScale(){
        return this->scale;
	}

	float MonkeyTime::getScaleTime(){
        return (float)((float)this->microTimer/(float)this->scale);
	}

	float MonkeyTime::getScaleTimeandRestart(){
        float time = this->getScaleTime();
        this->restart();
        return time;
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

	float MonkeyTime::getScaleTPC(){
        return (float)((float)this->tpcTimer/(float)this->scale);
	}

	float MonkeyTime::getScaleTPCandRestart(){
        float tpc = this->getScaleTPC();
        this->restartTPC();
        return tpc;
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

	float MonkeyTime::getScaleTick(){
        return (float)((float)this->tickTimer/(float)this->scale);
	}

	void MonkeyTime::resetTick(){
        this->tickTimer = 0;
	}

	bool MonkeyTime::isNow(float time){
		return Now::is(TimeCheck::InBetween, this->getScaleTime(), time,0.01f);
	}

	bool MonkeyTime::isNow(float time,float offset){
		return Now::is(TimeCheck::InBetween, this->getScaleTime(), time,offset);
	}

	bool MonkeyTime::isNow(TimeCheck check,float time){
		return Now::is(check, this->getScaleTime(), time,0.01f);
	}

	bool MonkeyTime::isNow(TimeCheck check,float time,float offset){
		return Now::is(check, this->getScaleTime(), time,offset);
	}

	void MonkeyTime::setTimeOffset(TimeCheck check){
        this->timecheck = check;
	}

	TimeCheck MonkeyTime::getTimeOffset(){
        return this->timecheck;
	}


#endif 
