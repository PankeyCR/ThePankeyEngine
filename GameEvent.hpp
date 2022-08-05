
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameEvent)
	#define GameEvent_hpp
#endif

#ifndef GameEvent_hpp
#define GameEvent_hpp
#define GameEvent_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "Event.hpp"
#include "GameOn.hpp"
#include "AppState.hpp"
#include "GameManager.hpp"
#include "PrimitiveList.hpp"

#ifdef GameEvent_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define GameEventLog(location,method,type,mns) ame_Log(this,location,"GameEvent",method,type,mns)
	#define GameEventMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_GameEventLog(location,method,type,mns) 
	#define StaticGameEventLog(pointer,location,method,type,mns) ame_Log(pointer,location,"GameEvent",method,type,mns)
#else
	#ifdef GameEvent_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define GameEventLog(location,method,type,mns) ame_LogDebug(this,location,"GameEvent",method,type)
		#define GameEventMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_GameEventLog(location,method,type,mns) 
		#define StaticGameEventLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"GameEvent",method,type)
	#else
		#define GameEventLog(location,method,type,mns) 
		#define GameEventMethodLog(location,method,type,mns) 
		#define const_GameEventLog(location,method,type,mns) 
		#define StaticGameEventLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{
	
template<class T>
class GameEvent : public AppState{
public:

GameEvent(){}

GameEvent(Event* a_event){
	m_event = a_event;
}

GameEvent(Note i, Event* a_event){
	setId(i);
	m_event = a_event;
}

virtual ~GameEvent(){}

virtual void initializeComponents(Application* app){
	GameEventLog(ame_Log_Statement, "initializeComponents",  "println", "");
	manager = (GameManager*)app->getStateManager()->get(Class<GameManager>::classType);
	if(manager == nullptr){
		GameEventLog(ame_Log_Statement, "initializeComponents",  "println", "manager == nullptr");
		return;
	}
	GameEventLog(ame_Log_Statement, "initializeComponents",  "println", Class<T>::classType->getName());
	components = manager->getComponents(Class<T>::classType);
}

virtual void initialize(Application* app){
	GameEventLog(ame_Log_Statement, "initialize",  "println", "");
	initializeComponents(app);
	if(components == nullptr){
		GameEventLog(ame_Log_Statement, "initialize",  "println", "components == nullptr");
		return;
	}
	initializeEvent(app);
}

virtual cppObjectClass* getClass(){
	return Class<GameEvent>::classType;
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<GameEvent>::classType || AppState::instanceof(cls);
}

virtual void update(float tpc){
	if(components == nullptr || m_event == nullptr){
		GameEventLog(ame_Log_Statement, "update",  "println", "components == nullptr || m_event == nullptr");
		return;
	}
	if(this->m_event->event()){
		for(int x = 0; x < components->getPosition(); x++){
			GameEventLog(ame_Log_Statement, "update",  "println", "iterating components");
			T* c = (T*)components->getByPosition(x);
			event(c, tpc);
		}
	}
	updateEvent(tpc);
}

virtual void event(T* component, float tpc){
	GameEventLog(ame_Log_Statement, "updateComponents",  "println", "");
}

virtual void updateEvent(float tpc){}

virtual void initializeEvent(Application* app){
	GameEventLog(ame_Log_Statement, "initializeSystem",  "println", "");
}

protected:
PrimitiveList<GameOn>* components = nullptr;
GameManager* manager = nullptr;
Event* m_event = nullptr;
};

}

#endif