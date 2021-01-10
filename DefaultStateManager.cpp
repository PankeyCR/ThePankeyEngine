
#ifndef DefaultStateManager_cpp
#define DefaultStateManager_cpp

#include "DefaultStateManager.h"
	
	
	DefaultStateManager::DefaultStateManager(){
		this->appStateList = new PrimitiveList<AppState>();
	}
	
	DefaultStateManager::~DefaultStateManager(){
		delete this->appStateList;
	}
	
	void DefaultStateManager::setApplication(Application *app){
		this->managerApp = app;
	}
	
	AppState *DefaultStateManager::add(AppState* state){
		this->appStateList->addPointer(state);
		if(this->managerApp != nullptr){
			state->initialize(this->managerApp);
		}
		state->onEnable();
		return state;
	}
	
	AppState* DefaultStateManager::get(String classname){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClassName() == classname){
				return this->appStateList->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	AppState* DefaultStateManager::get(String appstateId,String classname){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClassName() == classname &&
							this->appStateList->getByPosition(x)->getId() == appstateId){
				return this->appStateList->getByPosition(x);
			}
		}
		return nullptr;
	}
	
	AppState* DefaultStateManager::remove(String classname){
		AppState *appstate = nullptr;
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClassName() == classname){
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
	
	AppState* DefaultStateManager::remove(String appstateId,String classname){
		AppState *appstate = nullptr;
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClassName() == classname &&
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
	
	bool DefaultStateManager::contain(String classname){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClassName() == classname){
				return true;
			}
		}
		return false;
	}
	
	bool DefaultStateManager::contain(String appstateId,String classname){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			if(this->appStateList->getByPosition(x)->getClassName() == classname &&
							this->appStateList->getByPosition(x)->getId() == appstateId){
				return true;
			}
		}
		return false;
	}
	
	void DefaultStateManager::removeAll(){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			this->appStateList->getByPosition(x)->onDisable();
		}			
		this->appStateList->reset();
	}
	
	void DefaultStateManager::removeDeleteAll(){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			this->appStateList->getByPosition(x)->onDisable();
		}			
		this->appStateList->resetDelete();
	}
	
	void DefaultStateManager::update(){
		this->now = micros();
		this->t = (float)(this->now - this->prev)/1000000;
		this->prev = this->now;
		for(int x=0; x < this->appStateList->getPosition();x++){
			this->appStateList->getByPosition(x)->update(this->t);
		}			
	}
		
	float DefaultStateManager::tpc(){
		return t;
	}
	
	String DefaultStateManager::getClassName(){
		return "DefaultStateManager";
	}
	
	String DefaultStateManager::toString(){
		return "DefaultStateManager";
	}
    
#endif
