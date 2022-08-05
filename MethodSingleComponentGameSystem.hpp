
#include "ame_Enviroment.hpp"

#if defined(DISABLE_MethodSingleComponentGameSystem)
	#define MethodSingleComponentGameSystem_hpp
#endif

#ifndef MethodSingleComponentGameSystem_hpp
#define MethodSingleComponentGameSystem_hpp
#define MethodSingleComponentGameSystem_AVAILABLE

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

#ifdef MethodSingleComponentGameSystem_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define MethodSingleComponentGameSystemLog(location,method,type,mns) ame_Log(this,location,"MethodSingleComponentGameSystem",method,type,mns)
	#define MethodSingleComponentGameSystemMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_MethodSingleComponentGameSystemLog(location,method,type,mns) 
	#define StaticMethodSingleComponentGameSystemLog(pointer,location,method,type,mns) ame_Log(pointer,location,"MethodSingleComponentGameSystem",method,type,mns)
#else
	#ifdef MethodSingleComponentGameSystem_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define MethodSingleComponentGameSystemLog(location,method,type,mns) ame_LogDebug(this,location,"MethodSingleComponentGameSystem",method,type)
		#define MethodSingleComponentGameSystemMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_MethodSingleComponentGameSystemLog(location,method,type,mns) 
		#define StaticMethodSingleComponentGameSystemLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"MethodSingleComponentGameSystem",method,type)
	#else
		#define MethodSingleComponentGameSystemLog(location,method,type,mns) 
		#define MethodSingleComponentGameSystemMethodLog(location,method,type,mns) 
		#define const_MethodSingleComponentGameSystemLog(location,method,type,mns) 
		#define StaticMethodSingleComponentGameSystemLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{
	
template<class T>
class MethodSingleComponentGameSystem : public AppState{
public:
using Game_method = void(*)(T*,float);

MethodSingleComponentGameSystem(){}

MethodSingleComponentGameSystem(Game_method a_method){
	m_method = new Game_method();
	*m_method = a_method;
}

virtual ~MethodSingleComponentGameSystem(){
	delete m_method;
}

virtual void initializeComponents(Application* app){
	MethodSingleComponentGameSystemLog(ame_Log_Statement, "initializeComponents",  "println", "");
	manager = (GameManager*)app->getStateManager()->get(Class<GameManager>::classType);
	if(manager == nullptr){
		MethodSingleComponentGameSystemLog(ame_Log_Statement, "initializeComponents",  "println", "manager == nullptr");
		return;
	}
	MethodSingleComponentGameSystemLog(ame_Log_Statement, "initializeComponents",  "println", Class<T>::classType->getName());
	components = manager->getComponents(Class<T>::classType);
}

virtual void initialize(Application* app){
	MethodSingleComponentGameSystemLog(ame_Log_Statement, "initialize",  "println", "");
	initializeComponents(app);
	if(components == nullptr){
		MethodSingleComponentGameSystemLog(ame_Log_Statement, "initialize",  "println", "components == nullptr");
	}
}

virtual cppObjectClass* getClass(){
	return Class<MethodSingleComponentGameSystem>::classType;
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<MethodSingleComponentGameSystem>::classType || AppState::instanceof(cls);
}

virtual void update(float tpc){
	if(components == nullptr || m_method == nullptr){
		MethodSingleComponentGameSystemLog(ame_Log_Statement, "update",  "println", "components == nullptr || m_event == nullptr");
		return;
	}
	if(!components->isEmpty()){
		MethodSingleComponentGameSystemLog(ame_Log_Statement, "update",  "println", "execute first component");
		T* c = (T*)components->getByPosition(0);
		(*m_method)(c, tpc);
	}
}

protected:
PrimitiveList<GameOn>* components = nullptr;
GameManager* manager = nullptr;
Game_method* m_method = nullptr;
};

}

#endif