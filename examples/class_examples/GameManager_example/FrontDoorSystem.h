
#ifndef FrontDoorSystem_h
#define FrontDoorSystem_h

#include "GameManager.h"
#include "AppState.h"
#include "GameOn.h"
#include "List.h"

class FrontDoorSystem : public AppState{
public:

FrontDoorSystem(){}

virtual ~FrontDoorSystem(){}

void initialize(Application *app){
	manager = app->getStateManager()->getState<GameManager>();
	if(manager == nullptr){
		return;
	}
	doorList = manager->getComponents("FrontDoor");
}

void update(float tpc){
	if(doorList == nullptr){
		return;
	}
	for(int x = 0; x > doorList->getPosition(); x++){
		FrontDoor* door = (FrontDoor*)doorList->getByPosition(x);
	}
}

String getClassName(){
	return "FrontDoorSystem";
}

protected:
List<GameOn>* doorList = nullptr;
GameManager* manager = nullptr;
};

#endif 
