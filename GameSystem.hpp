
#include "ame_Level.hpp"

#if defined(ame_untilLevel_7)

#ifndef GameSystem_hpp
#define GameSystem_hpp

#include "AppState.hpp"
#include "PrimitiveList.hpp"

#ifdef GameSystemLogApp
	#include "Logger.hpp"
	#define GameSystemLog(name,method,type,mns) Log(name,method,type,mns)
#else
	#define GameSystemLog(name,method,type,mns)
#endif

namespace ame{
	
template<class T>
class GameSystem : public AppState{
public:

GameSystem(){}

GameSystem(String i){
	setId(i);
}

virtual ~GameSystem(){}

virtual void initializeComponents(Application* app){
	GameSystemLog("GameSystem", "initializeComponents",  "println", "");
	manager = (GameManager*)app->getStateManager()->get(Class<GameManager>::classType);
	if(manager == nullptr){
		GameSystemLog("GameSystem", "initializeComponents",  "println", "manager == nullptr");
		return;
	}
	GameSystemLog("GameSystem", "initializeComponents",  "println", Class<T>::classType->getName());
	components = manager->getComponents(Class<T>::classType);
}

virtual void initialize(Application* app){
	GameSystemLog("GameSystem", "initialize",  "println", "");
	initializeComponents(app);
	if(components == nullptr){
		GameSystemLog("GameSystem", "initialize",  "println", "components == nullptr");
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
		GameSystemLog("GameSystem", "update",  "println", "components == nullptr");
		return;
	}
	for(int x = 0; x < components->getPosition(); x++){
		GameSystemLog("GameSystem", "update",  "println", "iterating components");
		T* c = (T*)components->getByPosition(x);
		updateComponents(c, tpc);
	}
	updateSystem(tpc);
}

virtual void updateComponents(T* component, float tpc){
	GameSystemLog("GameSystem", "updateComponents",  "println", "");
}

virtual void updateSystem(float tpc){
}

virtual void initializeSystem(Application* app){
	GameSystemLog("GameSystem", "initializeSystem",  "println", "");
}

protected:
PrimitiveList<GameOn>* components = nullptr;
GameManager* manager = nullptr;
};

}

#endif 

#endif 
