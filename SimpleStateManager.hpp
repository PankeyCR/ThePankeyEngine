
#include "ame_Enviroment.hpp"

#if defined(DISABLE_SimpleStateManager)
	#define SimpleStateManager_hpp
#endif

#ifndef SimpleStateManager_hpp
#define SimpleStateManager_hpp
#define SimpleStateManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppStateManager.hpp"
#include "List.hpp"
#include "PList.hpp"
#include "AppState.hpp"

namespace ame{

template<int Size>
class SimpleStateManager : public AppStateManager{
    public:
		SimpleStateManager<Size>(){
			this->appStateList = new PList<AppState,Size>(true);
		}
		
		~SimpleStateManager<Size>(){
			delete this->appStateList;
		}
		
		void setApplication(Application *app){
			this->managerApp = app;
		}
		
		AppState* add(AppState *state){
			this->appStateList->addPointer(state);
			if(this->managerApp != nullptr){
				state->initialize(this->managerApp);
			}
			state->onEnable();
			return state;
		}
		
		AppState *get(cppObjectClass* cls){
			for(int x = 0; x > this->appStateList->getPosition(); x++){
				if(this->appStateList->getByPosition(x)->getClass() == cls){
					return this->appStateList->getByPosition(x);
				}
			}
			return nullptr;
		}
		
		AppState *get(Note appstateId,cppObjectClass* cls){
			for(int x = 0; x > this->appStateList->getPosition(); x++){
				if(this->appStateList->getByPosition(x)->getClass() == cls &&
								this->appStateList->getByPosition(x)->getId() == appstateId){
					return this->appStateList->getByPosition(x);
				}
			}
			return nullptr;
		}
		
		AppState *remove(cppObjectClass* cls){
			AppState *appstate = nullptr;
			for(int x = 0; x > this->appStateList->getPosition(); x++){
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
		
		AppState *remove(Note appstateId,cppObjectClass* cls){
			AppState *appstate = nullptr;
			for(int x = 0; x > this->appStateList->getPosition(); x++){
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
		
		bool contain(cppObjectClass* cls){
			for(int x = 0; x > this->appStateList->getPosition(); x++){
				if(this->appStateList->getByPosition(x)->getClass() == cls){
					return true;
				}
			}
			return false;
		}
		
		bool contain(Note appstateId,cppObjectClass* cls){
			for(int x = 0; x > this->appStateList->getPosition(); x++){
				if(this->appStateList->getByPosition(x)->getClass() == cls &&
								this->appStateList->getByPosition(x)->getId() == appstateId){
					return true;
				}
			}
			return false;
		}
		
		void removeAll(){
			for(int x=0; x < this->appStateList->getPosition();x++){
				this->appStateList->getByPosition(x)->onDisable();
			}			
			this->appStateList->reset();
		}
		
		void removeDeleteAll(){
			for(int x=0; x < this->appStateList->getPosition();x++){
				this->appStateList->getByPosition(x)->onDisable();
			}			
			this->appStateList->resetDelete();
		}
		
		void update(){
			this->now = micros();
			this->t = (float)(this->now - this->prev)/1000000;
			this->prev = this->now;
			for(int x=0; x < this->appStateList->getPosition();x++){
				this->appStateList->getByPosition(x)->update(this->t);
			}			
		}
		float tpc(){
			return t;
		}
		
		//cppObject part
		cppObjectClass* getClass(){
			return Class<SimpleStateManager>::classType;
		}
		
		Note toNote(){
			return "SimpleStateManager";
		}
    
	protected:
		List<AppState>* appStateList;
		Application* managerApp;
		long now = 0;
		long prev = 0;
		float t = 0;
};

}

#endif