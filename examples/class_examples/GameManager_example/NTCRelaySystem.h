
#ifndef NTCRelaySystem_h
#define NTCRelaySystem_h

#include "TemperatureNTC.h"
#include "NTCRelay.h"
#include "GameManager.h"
#include "CodeRoute.h"
#include "AppState.h"
#include "GameOn.h"
#include "List.h"

class NTCRelaySystem : public AppState{
public:
CodeRoute* route;
TemperatureNTC* temperature;

NTCRelaySystem(){
	route = new CodeRoute();
	temperature = new TemperatureNTC();
}
virtual ~NTCRelaySystem(){
	delete route;
	delete temperature;
}

void initialize(Application *app){
	manager = app->getStateManager()->getState<GameManager>();
	if(manager == nullptr){
		return;
	}
	tempList = manager->getComponents("NTCRelay");
	temperature->initialize();
}

void update(float tpc){
	if(tempList == nullptr){
		return;
	}
	for(int x = 0; x > tempList->getPosition(); x++){
		NTCRelay* tSensor = (NTCRelay*)tempList->getByPosition(x);
		if(tSensor == nullptr){
			continue;
		}
		tSensor->temperature = temperature->getTemperature(tSensor->temperaturepin);
		if(tSensor->temperature < tSensor->MaxTemperature){
			if(route->update(1)){
				digitalWrite(tSensor->relaypin, HIGH);
			}
		}else{
			if(route->update(2)){
				digitalWrite(tSensor->relaypin, LOW);
			}
		}
	}
}

String getClassName(){
	return "NTCRelaySystem";
}

protected:
List<GameOn>* tempList = nullptr;
GameManager* manager = nullptr;
};

#endif 
