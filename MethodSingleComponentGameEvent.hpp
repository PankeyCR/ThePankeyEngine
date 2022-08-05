
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodSingleComponentGameEvent)
	#define MethodSingleComponentGameEvent_hpp
#endif

#ifndef MethodSingleComponentGameEvent_hpp
#define MethodSingleComponentGameEvent_hpp
#define MethodSingleComponentGameEvent_AVAILABLE

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

#ifdef MethodSingleComponentGameEvent_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MethodSingleComponentGameEventLog(location,method,type,mns) ame_Log(this,location,"MethodSingleComponentGameEvent",method,type,mns)
	#define MethodSingleComponentGameEventMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_MethodSingleComponentGameEventLog(location,method,type,mns) 
	#define StaticMethodSingleComponentGameEventLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MethodSingleComponentGameEvent",method,type,mns)
#else
	#ifdef MethodSingleComponentGameEvent_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MethodSingleComponentGameEventLog(location,method,type,mns) ame_LogDebug(this,location,"MethodSingleComponentGameEvent",method,type)
		#define MethodSingleComponentGameEventMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_MethodSingleComponentGameEventLog(location,method,type,mns) 
		#define StaticMethodSingleComponentGameEventLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MethodSingleComponentGameEvent",method,type)
	#else
		#define MethodSingleComponentGameEventLog(location,method,type,mns) 
		#define MethodSingleComponentGameEventMethodLog(location,method,type,mns) 
		#define const_MethodSingleComponentGameEventLog(location,method,type,mns) 
		#define StaticMethodSingleComponentGameEventLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{
	
template<class T>
class MethodSingleComponentGameEvent : public AppState{
public:
using Game_event = bool(*)(float);
using Game_method = void(*)(T*,float);

MethodSingleComponentGameEvent(){}

MethodSingleComponentGameEvent(Game_method a_method, Game_event a_event){
	m_event = new Game_event();
	m_method = new Game_method();
	*m_event = a_event;
	*m_method = a_method;
}

virtual ~MethodSingleComponentGameEvent(){
	delete m_event;
	delete m_method;
}

virtual void initializeComponents(Application* app){
	MethodSingleComponentGameEventLog(ame_Log_Statement, "initializeComponents",  "println", "");
	manager = (GameManager*)app->getStateManager()->get(Class<GameManager>::classType);
	if(manager == nullptr){
		MethodSingleComponentGameEventLog(ame_Log_Statement, "initializeComponents",  "println", "manager == nullptr");
		return;
	}
	MethodSingleComponentGameEventLog(ame_Log_Statement, "initializeComponents",  "println", Class<T>::classType->getName());
	components = manager->getComponents(Class<T>::classType);
}

virtual void initialize(Application* app){
	MethodSingleComponentGameEventLog(ame_Log_Statement, "initialize",  "println", "");
	initializeComponents(app);
	if(components == nullptr){
		MethodSingleComponentGameEventLog(ame_Log_Statement, "initialize",  "println", "components == nullptr");
	}
}

virtual cppObjectClass* getClass(){
	return Class<MethodSingleComponentGameEvent>::classType;
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<MethodSingleComponentGameEvent>::classType || AppState::instanceof(cls);
}

virtual void update(float tpc){
	if(components == nullptr || m_event == nullptr || m_method == nullptr){
		MethodSingleComponentGameEventLog(ame_Log_Statement, "update",  "println", "components == nullptr || m_event == nullptr");
		return;
	}
	if((*m_event)(tpc) && !components->isEmpty()){
		MethodSingleComponentGameEventLog(ame_Log_Statement, "update",  "println", "execute first component");
		T* c = (T*)components->getByPosition(0);
		(*m_method)(c, tpc);
	}
}

protected:
PrimitiveList<GameOn>* components = nullptr;
GameManager* manager = nullptr;
Game_event* m_event = nullptr;
Game_method* m_method = nullptr;
};

}

#endif