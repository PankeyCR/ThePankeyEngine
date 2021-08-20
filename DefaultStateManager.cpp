
#ifndef DefaultStateManager_cpp
#define DefaultStateManager_cpp

#include "DefaultStateManager.h"
	
	
	ame::DefaultStateManager::DefaultStateManager(){
		this->appStateList = new PrimitiveList<AppState>();
	}
	
	ame::DefaultStateManager::~DefaultStateManager(){
		delete this->appStateList;
	}
	
	void ame::DefaultStateManager::setApplication(ame::Application *app){
		this->managerApp = app;
	}
	
	ame::AppState *ame::DefaultStateManager::add(ame::AppState* state){
		this->appStateList->addPointer(state);
		if(this->managerApp != nullptr){
			state->initialize(this->managerApp);
		}
		state->onEnable();
		return state;
	}
	
	ame::AppState* ame::DefaultStateManager::get(ame::cppObjectClass* cls){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClass() == cls){
				return this->appStateList->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	ame::AppState* ame::DefaultStateManager::get(String appstateId, ame::cppObjectClass* cls){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClass() == cls &&
							this->appStateList->getByPosition(x)->getId() == appstateId){
				return this->appStateList->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	ame::AppState* ame::DefaultStateManager::remove(ame::cppObjectClass* cls){
		ame::AppState *appstate = nullptr;
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClass() == cls){
				appstate = this->appStateList->getByPosition(x);
			}
		}
		if(appstate == nullptr){
			return nullptr;
		}
		appstate->onDisable();
		this->appStateList->removeByPointer(appstate);
		return appstate;
	}
	
	ame::AppState* ame::DefaultStateManager::remove(String appstateId, ame::cppObjectClass* cls){
		ame::AppState *appstate = nullptr;
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClass() == cls &&
							this->appStateList->getByPosition(x)->getId() == appstateId){
				appstate = this->appStateList->getByPosition(x);
			}
		}
		if(appstate == nullptr){
			return nullptr;
		}
		appstate->onDisable();
		this->appStateList->removeByPointer(appstate);
		return appstate;
	}
	
	bool ame::DefaultStateManager::contain(ame::cppObjectClass* cls){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClass() == cls){
				return true;
			}
		}
		return false;
	}
	
	bool ame::DefaultStateManager::contain(String appstateId, ame::cppObjectClass* cls){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClass() == cls &&
							this->appStateList->getByPosition(x)->getId() == appstateId){
				return true;
			}
		}
		return false;
	}
	
	void ame::DefaultStateManager::removeAll(){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			this->appStateList->getByPosition(x)->onDisable();
		}			
		this->appStateList->reset();
	}
	
	void ame::DefaultStateManager::removeDeleteAll(){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			this->appStateList->getByPosition(x)->onDisable();
		}
		this->appStateList->resetDelete();
	}
	
	void ame::DefaultStateManager::update(){
		this->now = micros();
		this->t = (float)(this->now - this->prev)/1000000;
		this->prev = this->now;
		for(int x=0; x < this->appStateList->getPosition();x++){
			this->appStateList->getByPosition(x)->update(this->t);
		}			
	}
		
	float ame::DefaultStateManager::tpc(){
		return t;
	}
	
	ame::cppObjectClass* ame::DefaultStateManager::getClass(){
		return ame::Class<DefaultStateManager>::classType;
	}
	
	String ame::DefaultStateManager::toString(){
		return "DefaultStateManager";
	}
	
	bool ame::DefaultStateManager::instanceof(ame::cppObjectClass* cls){
		return cls == Class<DefaultStateManager>::classType || AppStateManager::instanceof(cls);
	}
    
#endif
