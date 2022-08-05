
#include "ame_Enviroment.hpp"

#if defined(DISABLE_GameSystem)
	#define GameSystem_hpp
#endif

#ifndef GameSystem_hpp
#define GameSystem_hpp
#define GameSystem_AVAILABLE

#ifndef ame_Enviroment_Defined

#endif

#ifdef ame_Windows

#endif

#ifdef ame_ArduinoIDE
	#include "Arduino.h"
#endif

#include "AppState.hpp"
#include "PrimitiveList.hpp"

#ifdef GameSystem_LogApp
	#include "ame_Logger_config.hpp"
	#include "ame_Logger.hpp"
	
	#define GameSystemLog(location,method,type,mns) ame_Log(this,location,"GameSystem",method,type,mns)
	#define GameSystemMethodLog(location,method,type,mns) ame_Log(nullptr,location,"RawMethod",method,type,mns)
	#define const_GameSystemLog(location,method,type,mns) 
	#define StaticGameSystemLog(pointer,location,method,type,mns) ame_Log(pointer,location,"GameSystem",method,type,mns)
#else
	#ifdef GameSystem_LogDebugApp
		#include "ame_Logger_config.hpp"
		#include "ame_Logger.hpp"
		
		#define GameSystemLog(location,method,type,mns) ame_LogDebug(this,location,"GameSystem",method,type)
		#define GameSystemMethodLog(location,method,type,mns) ame_LogDebug(nullptr,location,"RawMethod",method,type)
		#define const_GameSystemLog(location,method,type,mns) 
		#define StaticGameSystemLog(pointer,location,method,type,mns) ame_LogDebug(pointer,location,"GameSystem",method,type)
	#else
		#define GameSystemLog(location,method,type,mns) 
		#define GameSystemMethodLog(location,method,type,mns) 
		#define const_GameSystemLog(location,method,type,mns) 
		#define StaticGameSystemLog(pointer,location,method,type,mns) 
	#endif
#endif

namespace ame{
	
template<class T>
class GameSystem : public AppState{
public:

GameSystem(){}

GameSystem(Note i){
	this->setId(i);
}

virtual ~GameSystem(){}

virtual void initializeComponents(Application* app){
	GameSystemLog(ame_Log_Statement, "initializeComponents",  "println", "");
	manager = (GameManager*)app->getStateManager()->get(Class<GameManager>::classType);
	if(manager == nullptr){
		GameSystemLog(ame_Log_Statement, "initializeComponents",  "println", "manager == nullptr");
		return;
	}
	GameSystemLog(ame_Log_Statement, "initializeComponents",  "println", Class<T>::classType->getName());
	components = manager->getComponents(Class<T>::classType);
}

virtual void initialize(Application* app){
	GameSystemLog(ame_Log_Statement, "initialize",  "println", "");
	initializeComponents(app);
	if(components == nullptr){
		GameSystemLog(ame_Log_Statement, "initialize",  "println", "components == nullptr");
		return;
	}
	initializeSystem(app);
}

virtual cppObjectClass* getClass(){
	return Class<GameSystem>::classType;
}

virtual bool instanceof(cppObjectClass* cls){
	return cls == Class<GameSystem>::classType || AppState::instanceof(cls);
}

virtual void update(float tpc){
	if(components == nullptr){
		GameSystemLog(ame_Log_Statement, "update",  "println", "components == nullptr");
		return;
	}
	for(int x = 0; x < components->getPosition(); x++){
		GameSystemLog(ame_Log_Statement, "update",  "println", "iterating components");
		T* c = (T*)components->getByPosition(x);
		updateComponents(c, tpc);
	}
	updateSystem(tpc);
}

virtual void updateComponents(T* component, float tpc){
	GameSystemLog(ame_Log_Statement, "updateComponents",  "println", "");
}

virtual void updateSystem(float tpc){
}

virtual void initializeSystem(Application* app){
	GameSystemLog(ame_Log_Statement, "initializeSystem",  "println", "");
}

protected:
PrimitiveList<GameOn>* components = nullptr;
GameManager* manager = nullptr;
};

}

#endif