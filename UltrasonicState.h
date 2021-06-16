

#ifndef UltrasonicState_h
#define UltrasonicState_h

#include "Arduino.h"
#include "AppState.h"
#include "Ultrasonic.h"

class Application;

class UltrasonicState : public AppState{
    public:
		UltrasonicState(){}
		virtual ~UltrasonicState(){}
		
		virtual void setId(String i){
			if(this->id == nullptr){
				this->id = new String(i);
			}else{
				if(*this->id != i){
					*this->id = i;
				}
			}
		}
		virtual bool instanceof(cppObjectClass* cls){
			return cls == Class<UltrasonicState>::classType || AppState::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){
			return Class<UltrasonicState>:classType;
		}
		virtual void onEnable(){enable = true;}
		virtual void onDisable(){enable = false;}
		
		virtual void initialize(Application* a){
			app = a;
			for(int x = 0; x < ultrasonics.getPosition(); x++){
				Ultrasonic* ultrasonic = ultrasonics.getByPosition(x);
				if(!ultrasonic->isEnable()){
					ultrasonic->initialize(a);
				}
			}
		}
		
		virtual Application* getApplication(){
			return app;
		}
				
		virtual void addUltrasonic(Ultrasonic* u){
			ultrasonics.addPointer(u);
			if(u->isEnable() || app == nullptr){
				return;
			}
			u->initialize(app);
		}
		
		virtual void update(float tpc){
			if(!enable){
				return;
			}
			for(int x = 0; x < ultrasonics.getPosition(); x++){
				Ultrasonic* ultrasonic = ultrasonics.getByPosition(x);
				if(ultrasonic->online()){
					if(!ultrasonicsOnline.containByPointer(ultrasonic)){
						ultrasonicsOnline.addPointer(ultrasonic);
					}
				}
			}
			for(int x = 0; x < ultrasonicsOnline.getPosition(); x++){
				Ultrasonic* ultrasonic = ultrasonicsOnline.getByPosition(x);
				if(!ultrasonic->online()){
					ultrasonicsOnline.removeByPointer(ultrasonic);
					x--;
					continue;
				}
				float rawDistance = ultrasonic->read();
				int rawZone = ultrasonic->zone();
				Serial.print("distance: ");
				Serial.println(rawDistance);
				Serial.print("zone: ");
				Serial.println(rawZone);
				// serialState->send(String(rawZone) + String(" ") + String(rawDistance));
			}
		}
		
	protected:
		Application* app = nullptr;
		bool enable = false;
		PrimitiveList<Ultrasonic> ultrasonics;
		PrimitiveList<Ultrasonic> ultrasonicsOnline;
};

#endif 
