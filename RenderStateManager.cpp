
#ifndef RenderStateManager_cpp
#define RenderStateManager_cpp

#include "RenderStateManager.h"
	
	
	RenderStateManager::RenderStateManager(){
		this->appStateRenderList = new PrimitiveList<RenderState>();
		this->renderManager = new DefaultRenderManager();
	}
	
	RenderStateManager::~RenderStateManager(){
		delete this->appStateRenderList;
		delete this->renderManager;
	}
	
	void RenderStateManager::setApplication(Application *app){
		this->managerApp = app;
		if(this->renderManager != nullptr){
			this->renderManager->initialize(this->managerApp);
		}
	}
	
	AppState *RenderStateManager::add(AppState* state){
		this->appStateList->addPointer(state);
		if(this->managerApp != nullptr){
			state->initialize(this->managerApp);
		}
		state->onEnable();
		if(state->instanceof(Class<RenderState>::classType)){
			this->appStateRenderList->addPointer((RenderState*)state);
		}
		return state;
	}
	
	AppState* RenderStateManager::remove(cppObjectClass* cls){
		AppState *appstate = nullptr;
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
		if(appstate->instanceof(Class<RenderState>::classType)){
			this->appStateRenderList->removeByPointer((RenderState*)appstate);
		}
		return appstate;
	}
	
	AppState* RenderStateManager::remove(String appstateId, cppObjectClass* cls){
		AppState *appstate = nullptr;
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
		if(appstate->instanceof(Class<RenderState>::classType)){
			this->appStateRenderList->removeByPointer((RenderState*)appstate);
		}
		return appstate;
	}
	
	void RenderStateManager::removeAll(){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			this->appStateList->getByPosition(x)->onDisable();
		}
		this->appStateList->reset();
		this->appStateRenderList->reset();
	}
	
	void RenderStateManager::removeDeleteAll(){
		for(int x = 0; x < this->appStateList->getPosition(); x++){
			this->appStateList->getByPosition(x)->onDisable();
		}
		this->appStateRenderList->reset();
		this->appStateList->resetDelete();
	}
	
	void RenderStateManager::update(){
		DefaultStateManager::update();
		for(int x=0; x < appStateRenderList->getPosition(); x++){
			RenderState* state = appStateRenderList->getByPosition(x);
			state->RenderUpdate(this->renderManager);
		}
	}
	
	cppObjectClass* RenderStateManager::getClass(){
		return Class<RenderStateManager>::classType;
	}
	
	String RenderStateManager::toString(){
		return "RenderStateManager";
	}
	bool RenderStateManager::instanceof(cppObjectClass* cls){
		return cls == Class<RenderStateManager>::classType || DefaultStateManager::instanceof(cls);
	}
    
#endif
