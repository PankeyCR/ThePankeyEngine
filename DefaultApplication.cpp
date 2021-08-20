

#ifndef DefaultApplication_cpp
#define DefaultApplication_cpp

#include "DefaultApplication.h"

	ame::DefaultApplication::DefaultApplication(){
		this->states = new ame::DefaultStateManager();
		this->settings = new ame::DefaultSettings();
		this->states->setApplication(this);
	}
	
	ame::DefaultApplication::~DefaultApplication(){
		delete this->states;
		delete this->settings;
	}
	
	void ame::DefaultApplication::setSettings(ame::AppSettings *set){
		if(set != nullptr && this->settings != set){
			delete this->settings;
		}
		this->settings = set;
	}
	
	ame::AppSettings *ame::DefaultApplication::getSettings(){
		return this->settings;
	}
	
	void ame::DefaultApplication::setStateManager(ame::AppStateManager *manager){
		if(manager != nullptr && this->states != manager){
			delete this->states;
		}
		this->states = manager;
	}
	
	ame::AppStateManager *ame::DefaultApplication::getStateManager(){
		return this->states;
	}
	
	void ame::DefaultApplication::setTimeControl(ame::TimeControl *timecontrol){
		
	}
	
	ame::TimeControl *ame::DefaultApplication::getTimeControl(){
		return ame::SimpleTimer::getInstance();
	}
	
	ame::Listener* ame::DefaultApplication::setListener(ame::Listener *l){
		listener = l;
		listener->attach(this);
		return l;
	}
	
	ame::Listener *ame::DefaultApplication::getListener(){
		return listener;
	}
	
	ame::MemoryPool* ame::DefaultApplication::setMemoryPool(ame::MemoryPool *l){
		memory = l;
		return l;
	}
	
	ame::MemoryPool *ame::DefaultApplication::getMemoryPool(){
		return memory;
	}
		
	void ame::DefaultApplication::update(){
		this->states->update();
		if(listener != nullptr){
			listener->InterruptEvent(this->states->tpc());
		}
		if(memory != nullptr){
			memory->update(this->states->tpc());
		}
	}
	
	//cppObject part
	ame::cppObjectClass* ame::DefaultApplication::getClass(){
		return ame::Class<DefaultApplication>::classType;
	}
	
	String ame::DefaultApplication::toString(){
		return "DefaultApplication";
	}
	
	bool ame::DefaultApplication::instanceof(ame::cppObjectClass* cls){
		return cls == ame::Class<DefaultApplication>::classType || ame::Application::instanceof(cls);
	}
	
		
#endif 
