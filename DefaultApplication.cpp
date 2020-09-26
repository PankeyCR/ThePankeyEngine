

#ifndef DefaultApplication_cpp
#define DefaultApplication_cpp

#include "DefaultApplication.h"

	DefaultApplication::DefaultApplication(){
		this->states = new DefaultStateManager();
		this->settings = new DefaultSettings();
		this->states->setApplication(this);
	}
	
	DefaultApplication::~DefaultApplication(){
		delete this->states;
		delete this->settings;
	}
	
	void DefaultApplication::setSettings(AppSettings *set){
		if(set != nullptr && this->settings != set){
			delete this->settings;
		}
		this->settings = set;
	}
	
	AppSettings *DefaultApplication::getSettings(){
		return this->settings;
	}
	
	void DefaultApplication::setStateManager(AppStateManager *manager){
		if(manager != nullptr && this->states != manager){
			delete this->states;
		}
		this->states = manager;
	}
	
	AppStateManager *DefaultApplication::getStateManager(){
		return this->states;
	}
	
	void DefaultApplication::setTimeControl(TimeControl *timecontrol){
		
	}
	
	TimeControl *DefaultApplication::getTimeControl(){
		return SimpleTimer::getInstance();
	}
		
	void DefaultApplication::update(){
		this->states->update();
	}
	
	//cppObject part
	String DefaultApplication::getClassName(){
		return "DefaultApplication";
	}
	
	String DefaultApplication::toString(){
		return "DefaultApplication";
	}
	
		
#endif 
