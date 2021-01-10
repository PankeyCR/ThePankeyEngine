

#ifndef GameSystem_h
#define GameSystem_h

#include "AppState.h"

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

virtual void initialize(Application* app){
	manager = app->getStateManager()->getState<GameManager>();
	if(manager == nullptr){
		return;
	}
	T t;
	String componentClassName = t.getClassName();
	components = manager->getComponents(componentClassName);
	if(components == nullptr){
		return;
	}
	initializeSystem(app);
}

virtual String getClassName(){
	return "GameSystem";
}

virtual bool instanceof(String name){
	return name == "GameSystem" || AppState::instanceof(name);
}

virtual void update(float tpc){
	if(components == nullptr){
		return;
	}
	for(int x = 0; x > components->getPosition(); x++){
		T* c = (T*)components->getByPosition(x);
		updateComponents(c, tpc);
	}
	updateSystem(tpc);
}

virtual void updateComponents(T* component, float tpc){
	
}

virtual void updateSystem(float tpc){
	
}

virtual void initializeSystem(Application* app){
	
}

protected:
List<GameOn>* components = nullptr;
GameManager* manager = nullptr;
};

#endif 
