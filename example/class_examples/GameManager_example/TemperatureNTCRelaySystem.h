
#ifndef TemperatureNTCRelaySystem_h
#define TemperatureNTCRelaySystem_h

#include "TemperatureNTCRelay.h"
#include "GameManager.h"
#include "CodeRoute.h"
#include "AppState.h"
#include "GameOn.h"
#include "List.h"

class TemperatureNTCRelaySystem : public AppState{
	public:
		CodeRoute* route;
    TemperatureNTCRelaySystem(GameManager* mgr){
      manager = mgr;
      route = new CodeRoute();
    }
    virtual ~TemperatureNTCRelaySystem(){delete route;}
    
		void initialize(Application *app){
      tempList = manager->getComponents("NTC");
		}
		void update(){
			iterate(tempList){
				NTC* tSensor = (NTC*)tempList->getPointer();
        TemperatureNTCRelay* relayComponent = (TemperatureNTCRelay*)manager->getComponent(tSensor->getId(), "TemperatureNTCRelay");
				if(relayComponent == nullptr){
           continue;
				}
        if(tSensor->temperature < relayComponent->MaxTemperature){
          if(route->update(10)){
            digitalWrite(relayComponent->pin, HIGH);
          }
        }else{
          if(route->update(35)){
            digitalWrite(relayComponent->pin, LOW);
          }
        }
			}
		}
		
		String getClassName(){
		  return "TemperatureNTCRelaySystem";
		}
		
	protected:
    List<GameOn>* tempList;
		GameManager* manager;
};

#endif 
