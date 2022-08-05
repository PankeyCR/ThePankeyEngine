
#include "ame_Enviroment.hpp"

#if defined(DISABLE_RenderStateManager)
	#define RenderStateManager_hpp
#endif

#ifndef RenderStateManager_hpp
#define RenderStateManager_hpp
#define RenderStateManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "PrimitiveList.hpp"
#include "DefaultStateManager.hpp"
#include "List.hpp"
#include "RenderState.hpp"
#include "RenderManager.hpp"
//#include "DefaultRenderManager.hpp"

namespace ame{

class RenderStateManager : public DefaultStateManager{
    public:
		RenderStateManager(){
			// this->renderManager = new DefaultRenderManager();
		}
		virtual ~RenderStateManager(){
			if(renderManager == nullptr){
				delete this->renderManager;
			}
		}
			
		// virtual void setApplication(Application* app){
			// this->managerApp = app;
			// if(this->renderManager != nullptr){
				// this->renderManager->initialize(this->managerApp);
			// }
		// }
		
		// virtual AppState* add(AppState* state){
			// this->appStateList->addPointer(state);
			// if(this->managerApp != nullptr){
				// state->initialize(this->managerApp);
			// }
			// state->onEnable();
			// if(state->instanceof(Class<RenderState>::classType)){
				// this->appStateRenderList->addPointer((RenderState*)state);
			// }
			// return state;
		// }
	
		// virtual AppState* remove(cppObjectClass* cls){
			// AppState *appstate = nullptr;
			// for(int x = 0; x < this->appStateList->getPosition(); x++){
				// if(this->appStateList->getByPosition(x)->getClass() == cls){
					// appstate = this->appStateList->getByPosition(x);
				// }
			// }
			// if(appstate == nullptr){
				// return nullptr;
			// }
			// appstate->onDisable();
			// this->appStateList->removeByPointer(appstate);
			// if(appstate->instanceof(Class<RenderState>::classType)){
				// this->appStateRenderList->removeByPointer((RenderState*)appstate);
			// }
			// return appstate;
		// }
	
		// virtual AppState* remove(Note appstateId, cppObjectClass* cls){
			// AppState *appstate = nullptr;
			// for(int x = 0; x < this->appStateList->getPosition(); x++){
				// if(this->appStateList->getByPosition(x)->getClass() == cls &&
								// this->appStateList->getByPosition(x)->getId() == appstateId){
					// appstate = this->appStateList->getByPosition(x);
				// }
			// }
			// if(appstate == nullptr){
				// return nullptr;
			// }
			// appstate->onDisable();
			// this->appStateList->removeByPointer(appstate);
			// if(appstate->instanceof(Class<RenderState>::classType)){
				// this->appStateRenderList->removeByPointer((RenderState*)appstate);
			// }
			// return appstate;
		// }
	
		// virtual void removeAll(){
			// for(int x = 0; x < this->appStateList->getPosition(); x++){
				// this->appStateList->getByPosition(x)->onDisable();
			// }
			// this->appStateList->reset();
			// this->appStateRenderList->reset();
		// }
	
		// virtual void removeDeleteAll(){
			// for(int x = 0; x < this->appStateList->getPosition(); x++){
				// this->appStateList->getByPosition(x)->onDisable();
			// }
			// this->appStateRenderList->reset();
			// this->appStateList->resetDelete();
		// }
	
		// virtual void update(){
			// DefaultStateManager::update();
			// for(int x=0; x < appStateRenderList->getPosition(); x++){
				// RenderState* state = appStateRenderList->getByPosition(x);
				// state->RenderUpdate(this->renderManager);
			// }
		// }
	
		
		///////// cppObject part
		// virtual cppObjectClass* getClass(){
			// return Class<RenderStateManager>::classType;
		// }
	
		// virtual Note toNote(){
			// return "RenderStateManager";
		// }
		// virtual bool instanceof(cppObjectClass* cls){
			// return cls == Class<RenderStateManager>::classType || DefaultStateManager::instanceof(cls);
		// }
    
	protected:
		List<RenderState>* appStateRenderList = nullptr;
		RenderManager* renderManager = nullptr;
};

}

#endif