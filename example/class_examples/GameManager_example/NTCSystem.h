
#ifndef NTCSystem_h
#define NTCSystem_h

#include "TemperatureNTC.h"
#include "GameManager.h"
#include "AppState.h"
#include "GameOn.h"
#include "List.h"
#include "NTC.h"

class NTCSystem : public AppState{
public:
TemperatureNTC* temperature;

NTCSystem(){
	temperature = new TemperatureNTC();
}

virtual ~NTCSystem(){}

void initialize(Application *app){
	manager = app->getStateManager()->getState<GameManager>();
	if(manager == nullptr){
		return;
	}
	tempList = manager->getComponents("NTC");
	temperature->initialize();
}

void update(float tpc){
	if(tempList == nullptr){
		return;
	}
	for(int x = 0; x > tempList->getPosition(); x++){
		NTC* tSensor = (NTC*)tempList->getByPosition(x);
		tSensor->temperature = temperature->getTemperature(tSensor->pin);
	}
}

String getClassName(){
	return "NTCSystem";
}

protected:
List<GameOn>* tempList;
GameManager* manager;
};

#endif 
