

#ifndef GameSystem_h
#define GameSystem_h

#include "AppState.h"

#ifdef GameSystemLogApp
	#include "Logger.h"
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
	if(this->id == nullptr){
		this->id = new String(i);
	}else{
		*this->id = i;
	}
}

virtual ~GameSystem(){
	if(this->id != nullptr){
		delete this->id;
	}
}

virtual String setId(String i){
	if(this->id == nullptr){
		this->id = new String(i);
	}else{
		delete this->id;
		this->id = new String(i);
	}
}

virtual void initializeComponents(Application* app){
	GameSystemLog("GameSystem", "initializeComponents",  "println", "");
	manager = app->getStateManager()->getState<GameManager>();
	if(manager == nullptr){
		GameSystemLog("GameSystem", "initializeComponents",  "println", "manager == nullptr");
		return;
	}
	T t;
	cppObjectClass* componentClass = t.getClass();
	GameSystemLog("GameSystem", "initializeComponents",  "println", componentClass);
	components = manager->getComponents(componentClass);
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
List<GameOn>* components = nullptr;
GameManager* manager = nullptr;
};

}

#endif 
