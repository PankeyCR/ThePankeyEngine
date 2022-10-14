
#include "ame_Enviroment.hpp"

#if defined(DISABLE_AppStateManager) || defined(DISABLE_DefaultStateManager)
	#define DefaultStateManager_hpp
#endif

#ifndef DefaultStateManager_hpp
#define DefaultStateManager_hpp
#define DefaultStateManager_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows
    #include <chrono>
#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "List.hpp"
#include "Class.hpp"
#include "PrimitiveList.hpp"
#include "AppStateManager.hpp"
#include "System.hpp"

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

		virtual AppState* get(Note appstateId, cppObjectClass* cls){
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

		virtual AppState* getInitializedState(cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "getInitializeState",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls){
					return m_state;
				}
			}
			return nullptr;
		}

		virtual AppState* getInitializedState(Note appstateId, cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "getInitializedState",  "println", "");
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state->getClass() == cls && m_state->getId() == appstateId){
					return m_state;
				}
			}
			return nullptr;
		}


		virtual AppState* getUnInitializedState(cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "getUnInitializedState",  "println", "");
			for(int x = 0; x < initializeStates.getPosition(); x++){
				AppState* m_state = initializeStates.getByPosition(x);
				if(m_state->getClass() == cls){
					return m_state;
				}
			}
			return nullptr;
		}

		virtual AppState* getUnInitializedState(Note appstateId, cppObjectClass* cls){
			DefaultStateManagerLog("DefaultStateManager", "getUnInitializedState",  "println", "");
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

		virtual AppState* remove(Note appstateId, cppObjectClass* cls){
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

		virtual bool contain(Note appstateId, cppObjectClass* cls){
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
			this->now = System::microSeconds();
			
			this->t = (float)(this->now - this->prev)/1000000;
			this->prev = this->now;
			if(!initializeStates.isEmpty()){
				for(int x = 0; x < initializeStates.getPosition();x++){
					AppState* m_state = initializeStates.getByPosition(x);
					if(this->getApplication() != nullptr){
						m_state->initialize(this->getApplication());
						m_state->onEnable();
						appStateList.addPointer(m_state);
					}
				}
				DefaultStateManagerLog("DefaultStateManager", "update",  "println", "initializeStates");
				initializeStates.reset();
			}
			for(int x = 0; x < appStateList.getPosition(); x++){
				AppState* m_state = appStateList.getByPosition(x);
				if(m_state == nullptr){
					continue;
				}
				m_state->update(this->t);
			}
		}

		virtual float tpc(){
			return t;
		}

		//cppObject part
		virtual cppObjectClass* getClass(){
			return Class<DefaultStateManager>::classType;
		}

		virtual Note toNote(){
			return "DefaultStateManager";
		}

		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<DefaultStateManager>::classType || AppStateManager::instanceof(cls);
		}

	protected:
		PrimitiveList<AppState> appStateList;
		PrimitiveList<AppState> initializeStates;
		long now = 0;
		long prev = 0;
		float t = 0;
};

}

#endif