
#ifndef FixStateManager_cpp
#define FixStateManager_cpp

#include "FixStateManager.h"
	
	FixStateManager::FixStateManager(Application *app){
		this->managerApp = app;
		this->appStateMap = new KPMap<String,AppState,20>();
	}
	
	FixStateManager::FixStateManager(){
		this->appStateMap = new KPMap<String,AppState,20>();
	}
	
	void FixStateManager::setApplication(Application *app){
		this->managerApp = app;
	}
	
	String FixStateManager::toString(){
		return "FixStateManager";
	}
	void FixStateManager::onDelete(){
		this->appStateMap->onDelete();
		delete this;
	}
	
	void FixStateManager::update(){
		for(int x=0; x < this->appStateMap->getPos();x++){
			this->appStateMap->getByPos(x)->update();
		}			
	}
	
	AppState *FixStateManager::add(String name,AppState *state){
		this->appStateMap->add(name,state);
		state->initialize(this->managerApp);
		state->onEnable();
		return state;
	}
	
	AppState *FixStateManager::get(String name){
		return this->appStateMap->get(name);
	}
	
	AppState *FixStateManager::remove(String name){
		if(this->appStateMap->get(name) == NULL){
			return NULL;
		}
		AppState *appstate = this->appStateMap->get(name);
		appstate->onDisable();
		this->appStateMap->remove(name);
		return appstate;
	}
	
	bool FixStateManager::contain(String name){
		return this->appStateMap->contain(name);
	}
	
	void FixStateManager::removeAll(){
		for(int x=0; x < this->appStateMap->getPos();x++){
			this->appStateMap->getByPos(x)->onDisable();
		}			
		this->appStateMap->reset();
	}
	
	void FixStateManager::removeDeleteAll(){
		for(int x=0; x < this->appStateMap->getPos();x++){
			this->appStateMap->getByPos(x)->onDisable();
		}			
		this->appStateMap->resetDelete();
	}
    
#endif
