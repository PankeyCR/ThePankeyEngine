
#ifndef SimpleStateManager_h
#define SimpleStateManager_h

#include "AppStateManager.h"
#include "List.h"
#include "PList.h"
#include "AppState.h"

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
			this->appStateList->add(state);
			if(this->managerApp != nullptr){
				state->initialize(this->managerApp);
			}
			state->onEnable();
			return state;
		}
		
		AppState *get(String classname){
			iterate(this->appStateList){
				if(this->appStateList->getPointer()->getClassName() == classname){
					return this->appStateList->getPointer();
				}
			}
			return nullptr;
		}
		
		AppState *get(String appstateId,String classname){
			iterate(this->appStateList){
				if(this->appStateList->getPointer()->getClassName() == classname &&
								this->appStateList->getPointer()->getId() == appstateId){
					return this->appStateList->getPointer();
				}
			}
			return nullptr;
		}
		
		AppState *remove(String classname){
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
		
		AppState *remove(String appstateId,String classname){
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
		
		bool contain(String classname){
			iterate(this->appStateList){
				if(this->appStateList->getPointer()->getClassName() == classname){
					return true;
				}
			}
			return false;
		}
		
		bool contain(String appstateId,String classname){
			iterate(this->appStateList){
				if(this->appStateList->getPointer()->getClassName() == classname &&
								this->appStateList->getPointer()->getId() == appstateId){
					return true;
				}
			}
			return false;
		}
		
		void removeAll(){
			for(int x=0; x < this->appStateList->getPos();x++){
				this->appStateList->getByPos(x)->onDisable();
			}			
			this->appStateList->reset();
		}
		
		void removeDeleteAll(){
			for(int x=0; x < this->appStateList->getPos();x++){
				this->appStateList->getByPos(x)->onDisable();
			}			
			this->appStateList->resetDelete();
		}
		
		void update(){
			this->now = micros();
			this->t = (float)(this->now - this->prev)/1000000;
			this->prev = this->now;
			for(int x=0; x < this->appStateList->getPos();x++){
				this->appStateList->getByPos(x)->update(this->t);
			}			
		}
		float tpc(){
			return t;
		}
		
		//cppObject part
		String getClassName(){
			return "SimpleStateManager";
		}
		
		String toString(){
			return "SimpleStateManager";
		}
    
	protected:
		List<AppState>* appStateList;
		Application* managerApp;
		long now = 0;
		long prev = 0;
		float t = 0;
};

#endif
