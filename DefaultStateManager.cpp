
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
		this->appStateList->add(state);
		if(this->managerApp != nullptr){
			state->initialize(this->managerApp);
		}
		state->onEnable();
		return state;
	}
	
	AppState* DefaultStateManager::get(String classname){
		iterate(this->appStateList){
			if(this->appStateList->getPointer()->getClassName() == classname){
				return this->appStateList->getPointer();
			}
		}
		return nullptr;
	}
	
	AppState* DefaultStateManager::get(String appstateId,String classname){
		iterate(this->appStateList){
			if(this->appStateList->getPointer()->getClassName() == classname &&
							this->appStateList->getPointer()->getId() == appstateId){
				return this->appStateList->getPointer();
			}
		}
		return nullptr;
	}
	
	AppState* DefaultStateManager::remove(String classname){
		AppState *appstate = nullptr;
		iterate(this->appStateList){
			if(this->appStateList->getPointer()->getClassName() == classname){
				appstate = this->appStateList->getPointer();
			}
		}
		if(appstate == nullptr){
			return nullptr;
		}
		appstate->onDisable();
		this->appStateList->remove(appstate);
		return appstate;
	}
	
	AppState* DefaultStateManager::remove(String appstateId,String classname){
		AppState *appstate = nullptr;
		iterate(this->appStateList){
			if(this->appStateList->getPointer()->getClassName() == classname &&
							this->appStateList->getPointer()->getId() == appstateId){
				appstate = this->appStateList->getPointer();
			}
		}
		if(appstate == nullptr){
			return nullptr;
		}
		appstate->onDisable();
		this->appStateList->remove(appstate);
		return appstate;
	}
	
	bool DefaultStateManager::contain(String classname){
		iterate(this->appStateList){
			if(this->appStateList->getPointer()->getClassName() == classname){
				return true;
			}
		}
		return false;
	}
	
	bool DefaultStateManager::contain(String appstateId,String classname){
		iterate(this->appStateList){
			if(this->appStateList->getPointer()->getClassName() == classname &&
							this->appStateList->getPointer()->getId() == appstateId){
				return true;
			}
		}
		return false;
	}
	
	void DefaultStateManager::removeAll(){
		iterate(this->appStateList){
			this->appStateList->getPointer()->onDisable();
		}			
		this->appStateList->reset();
	}
	
	void DefaultStateManager::removeDeleteAll(){
		iterate(this->appStateList){
			this->appStateList->getPointer()->onDisable();
		}			
		this->appStateList->resetDelete();
	}
	
	void DefaultStateManager::update(){
		this->now = micros();
		this->tpc = (float)(this->now - this->prev)/1000000;
		this->prev = this->now;
		for(int x=0; x < this->appStateList->getPos();x++){
			this->appStateList->getByPos(x)->update(this->tpc);
		}			
	}
	
	String DefaultStateManager::getClassName(){
		return "DefaultStateManager";
	}
	
	String DefaultStateManager::toString(){
		return "DefaultStateManager";
	}
    
#endif
