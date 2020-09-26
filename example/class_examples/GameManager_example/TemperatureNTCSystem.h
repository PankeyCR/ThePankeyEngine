
#ifndef TemperatureNTCSystem_h
#define TemperatureNTCSystem_h

#include "TemperatureNTC.h"
#include "GameManager.h"
#include "AppState.h"
#include "GameOn.h"
#include "List.h"
#include "NTC.h"

class TemperatureNTCSystem : public AppState{
public:
TemperatureNTC* temperature;

TemperatureNTCSystem(GameManager* mgr){
	manager = mgr;
	temperature = new TemperatureNTC();
}

virtual ~TemperatureNTCSystem(){}

void initialize(Application *app){
	tempList = manager->getComponents("NTC");
	temperature->initialize();
}

void update(float tpc){
	iterate(tempList){
		NTC* tSensor = (NTC*)tempList->getPointer();
		tSensor->temperature = temperature->getTemperature(tSensor->pin);
	}
}

String getClassName(){
	return "TemperatureNTCSystem";
}

protected:
List<GameOn>* tempList;
GameManager* manager;
};

#endif 
