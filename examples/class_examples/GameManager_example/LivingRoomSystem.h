
#ifndef LivingRoomSystem_h
#define LivingRoomSystem_h

#include "GameManager.h"
#include "AppState.h"
#include "GameOn.h"
#include "List.h"

class LivingRoomSystem : public AppState{
public:

LivingRoomSystem(){}

virtual ~LivingRoomSystem(){}

void initialize(Application *app){
	manager = app->getStateManager()->getState<GameManager>();
	if(manager == nullptr){
		return;
	}
	livingroomList = manager->getComponents("LivingRoom");
}

void update(float tpc){
	if(livingroomList == nullptr){
		return;
	}
	for(int x = 0; x > livingroomList->getPosition(); x++){
		LivingRoom* door = (LivingRoom*)livingroomList->getByPosition(x);
	}
}

String getClassName(){
	return "LivingRoomSystem";
}

protected:
List<GameOn>* livingroomList = nullptr;
GameManager* manager = nullptr;
};

#endif 
