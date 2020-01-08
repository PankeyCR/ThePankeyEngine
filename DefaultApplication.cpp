

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
	
	void DefaultApplication::setSettings(AppSettings *setting){
		this->settings = setting;
	}
	
	AppSettings *DefaultApplication::getSettings(){
		return this->settings;
	}
	
	void DefaultApplication::setStateManager(AppStateManager *appstate){
		this->states = appstate;
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
