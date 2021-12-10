
#include "ame_Level.hpp"

#if defined(ame_untilLevel_5)

#ifndef DefaultStateManager_hpp
#define DefaultStateManager_hpp

#include "List.hpp"
#include "PrimitiveList.hpp"
#include "AppStateManager.hpp"

#ifdef DefaultStateManagerLogApp
	#include "Logger.hpp"
	#define DefaultStateManagerLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define DefaultStateManagerLog(name,method,type,mns)
#endif

namespace ame{

class DefaultStateManager : public AppStateManager{
    public:
		DefaultStateManager(){}
		virtual ~DefaultStateManager(){}
		
		virtual void setApplication(Application* app){
			managerApp = app;
		}
		
		virtual AppState* add(AppState* state){
			DefaultStateManagerLog("DefaultStateManager", "add",  "println", "");
			initializeStates.addPointer(state);
			return state;
		}
		
		virtual AppState* get(cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "get",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls){
					return m_state;
				}
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls){
					return m_state;
				}
			}
			return nullptr;
		}
	
		virtual AppState* get(String appstateId, cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "get",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					return m_state;
				}
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					return m_state;
				}
			}
			return nullptr;
		}
		
		virtual AppState* remove(cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "remove",  "println", "");
			ame::AppState *appstate = nullptr;
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls){
					appstate = m_state;
					if(appstate == nullptr){
						return nullptr;
					}
					appstate->onDisable();
					appStateList.removeByPointer(appstate);
					return appstate;
				}
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls){
					appstate = m_state;
					if(appstate == nullptr){
						return nullptr;
					}
					appstate->onDisable();
					initializeStates.removeByPointer(appstate);
					return appstate;
				}
			}
			return appstate;
		}
	
		virtual AppState* remove(String appstateId, cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "remove",  "println", "");
			AppState *appstate = nullptr;
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					appstate = m_state;
					if(appstate == nullptr){
						return nullptr;
					}
					appstate->onDisable();
					appStateList.removeByPointer(appstate);
					return appstate;
				}
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					appstate = m_state;
					if(appstate == nullptr){
						return nullptr;
					}
					appstate->onDisable();
					initializeStates.removeByPointer(appstate);
					return appstate;
				}
			}
			return appstate;
		}
		
		virtual bool contain(cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "contain",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls){
					return true;
				}
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls){
					return true;
				}
			}
			return false;
		}
	
		virtual bool contain(String appstateId, cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "contain",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					return true;
				}
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					return true;
				}
			}
			return false;
		}
		
		virtual void removeAll(){
			DefaultStateManagerLog("DefaultStateManager", "removeAll",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				appStateList.getByPosition(x)->onDisable();
			}		
			for(int x = 0; x < initializeStates.getPosition(); x++){
				initializeStates.getByPosition(x)->onDisable();
			}		
			appStateList.reset();
			initializeStates.reset();
		}
	
		virtual void removeDeleteAll(){
			DefaultStateManagerLog("DefaultStateManager", "removeDeleteAll",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				appStateList.getByPosition(x)->onDisable();
			}
			for(int x = 0; x < initializeStates.getPosition(); x++){
				initializeStates.getByPosition(x)->onDisable();
			}
			appStateList.resetDelete();
			initializeStates.resetDelete();
		}
		
		virtual void update(){
			this->now = micros();
			this->t = (float)(this->now - this->prev)/1000000;
			this->prev = this->now;
			if(!initializeStates.isEmpty()){
				for(int x=0; x < initializeStates.getPosition();x++){
					AppState* m_state = initializeStates.getByPosition(x);
					if(managerApp != nullptr){
						m_state->initialize(managerApp);
						m_state->onEnable();
						appStateList.addPointer(m_state);
					}
				}
				DefaultStateManagerLog("DefaultStateManager", "update",  "println", "initializeStates");
				initializeStates.reset();
			}
			for(int x=0; x < appStateList.getPosition();x++){
				appStateList.getByPosition(x)->update(this->t);
			}			
		}
		
		virtual float tpc(){
			return t;
		}
		
		//cppObject part
		virtual cppObjectClass* getClass(){
			return ame::Class<DefaultStateManager>::classType;
		}
		
		virtual String toString(){
			return "DefaultStateManager";
		}
	
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultStateManager>::classType || AppStateManager::instanceof(cls);
		}
    
	protected:
		PrimitiveList<AppState> appStateList;
		PrimitiveList<AppState> initializeStates;
		Application *managerApp;
		long now = 0;
		long prev = 0;
		float t = 0;
};

}

#endif

#endif

