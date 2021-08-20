

#ifndef UltrasonicState_h
#define UltrasonicState_h

#include "Arduino.h"
#include "Application.h"
#include "Command.h"
#include "Message.h"
#include "AppState.h"
#include "Ultrasonic.h"
#include "Average.h"
#include "TimeElapsed.h"
#include "SerialMessageState.h"
#include "SerialMessageControlledState.h"

namespace ame{

class UltrasonicState : public SerialMessageControlledState , public TimeElapsed{
    public:
		using PlayMethod = void (UltrasonicState::*)();
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
			return cls == Class<UltrasonicState>::classType || SerialMessageControlledState::instanceof(cls);
		}
		virtual cppObjectClass* getClass(){
			return Class<UltrasonicState>::classType;
		}
		
		virtual void initialize(Application* a){
			SerialMessageControlledState::initialize(a);
			for(int x = 0; x < zone_0.getPosition(); x++){
				Ultrasonic* ultrasonic = zone_0.getByPosition(x);
				if(!ultrasonic->isEnable()){
					ultrasonic->initialize(a);
					ultrasonic->enable();
				}
			}
			for(int x = 0; x < zone_1.getPosition(); x++){
				Ultrasonic* ultrasonic = zone_1.getByPosition(x);
				if(!ultrasonic->isEnable()){
					ultrasonic->initialize(a);
					ultrasonic->enable();
				}
			}
			for(int x = 0; x < zone_2.getPosition(); x++){
				Ultrasonic* ultrasonic = zone_2.getByPosition(x);
				if(!ultrasonic->isEnable()){
					ultrasonic->initialize(a);
					ultrasonic->enable();
				}
			}
			app->getTimeControl()->initialize(20);
			app->getTimeControl()->startInterrupt();
			app->getTimeControl()->attachInterrupt();
			app->getTimeControl()->add(this);
		}
		
		virtual Application* getApplication(){
			return app;
		}
				
		virtual void addUltrasonic(int x, Ultrasonic* u){
			if(x == 0){
				zone_0.addPointer(u);
			}
			if(x == 1){
				zone_1.addPointer(u);
			}
			if(x == 2){
				zone_2.addPointer(u);
			}
			if(x > 2){
				return;
			}
			if(u->isEnable() || app == nullptr){
				return;
			}
			u->initialize(app);
			u->enable();
		}
		
		void Play(TimeControl *t){
			if(!enable){
				return;
			}
			(this->*method)();
			time++;
		}
		
		virtual void update(float tpc){
			if(!ready){
				return;
			}
			ready = false;
			SerialMessageState* serialState = (SerialMessageState*)app->getStateManager()->get(Class<SerialMessageState>::classType);
			if(serialState == nullptr){
				return;
			}
			if(readySingleZone){
				readySingleZone = false;
				serialState->send(String("singleZone ") + String(singleZone));
			}
			if(readyZone_0){
				readyZone_0 = false;
				serialState->send(String("left_size ") + String(left_size));
			}
			if(readyZone_1){
				readyZone_1 = false;
				serialState->send(String("height ") + String(height));
			}
			if(readyZone_2){
				readyZone_2 = false;
				serialState->send(String("right_size ") + String(right_size));
			}
			if(readyFull){
				readyFull = false;
				serialState->send(String("left_size ") + String(left_size));
				serialState->send(String("right_size ") + String(right_size));
				serialState->send(String("height ") + String(height));
			}
		}
		
		virtual void FullRead(){
			if(time == 0){
				for(int x = 0; x < zone_0.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_0.getByPosition(x);
					ultrasonic->startTrigger();
				}
				for(int x = 0; x < zone_1.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_1.getByPosition(x);
					ultrasonic->startTrigger();
				}
				for(int x = 0; x < zone_2.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_2.getByPosition(x);
					ultrasonic->startTrigger();
				}
			}
			if(time == UltraLimit){
				for(int x = 0; x < zone_0.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_0.getByPosition(x);
					ultrasonic->stopTrigger();
				}
				for(int x = 0; x < zone_1.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_1.getByPosition(x);
					ultrasonic->stopTrigger();
				}
				for(int x = 0; x < zone_2.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_2.getByPosition(x);
					ultrasonic->stopTrigger();
				}
			}
			if(time >= readLimit){
				Average<float> average_0;
				Average<float> average_1;
				Average<float> average_2;
				for(int x = 0; x < zone_0.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_0.getByPosition(x);
					float r = ultrasonic->read();
					if(r == -1.0f){
						continue;
					}
					average_0.addLValue(r);
				}
				for(int x = 0; x < zone_1.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_1.getByPosition(x);
					float r = ultrasonic->read();
					if(r == -1.0f){
						continue;
					}
					average_1.addLValue(r);
				}
				for(int x = 0; x < zone_2.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_2.getByPosition(x);
					float r = ultrasonic->read();
					if(r == -1.0f){
						continue;
					}
					average_2.addLValue(r);
				}
				time = 0;
				left_size = average_0.getAverage();
				height = average_1.getAverage();
				right_size = average_2.getAverage();
				readyFull = true;
				enable = false;
				ready = true;
			}
		}
		
		virtual void Zone_0(){
			if(time == 0){
				for(int x = 0; x < zone_0.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_0.getByPosition(x);
					ultrasonic->startTrigger();
				}
			}
			if(time == UltraLimit){
				for(int x = 0; x < zone_0.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_0.getByPosition(x);
					ultrasonic->stopTrigger();
				}
			}
			if(time >= readLimit){
				Average<float> average;
				for(int x = 0; x < zone_0.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_0.getByPosition(x);
					float r = ultrasonic->read();
					if(r == -1.0f){
						continue;
					}
					average.addLValue(r);
				}
				time = 0;
				left_size = average.getAverage();
				readyZone_0 = true;
				enable = false;
				ready = true;
			}
		}
		
		template<int x>
		void Zone_0_t(){
			Ultrasonic* ultrasonic = zone_0.getByPosition(x);
			if(ultrasonic == nullptr){
				return;
			}
			if(time == 0){
				ultrasonic->startTrigger();
			}
			if(time == UltraLimit){
				ultrasonic->stopTrigger();
			}
			if(time >= readLimit){
				singleZone = ultrasonic->read();
				time = 0;
				readySingleZone = true;
				enable = false;
				ready = true;
			}
		}
		
		virtual void Zone_1(){
			if(time == 0){
				for(int x = 0; x < zone_1.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_1.getByPosition(x);
					ultrasonic->startTrigger();
				}
			}
			if(time == UltraLimit){
				for(int x = 0; x < zone_1.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_1.getByPosition(x);
					ultrasonic->stopTrigger();
				}
			}
			if(time >= readLimit){
				Average<float> average;
				for(int x = 0; x < zone_1.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_1.getByPosition(x);
					float r = ultrasonic->read();
					if(r == -1.0f){
						continue;
					}
					average.addLValue(r);
				}
				time = 0;
				height = average.getAverage();
				readyZone_0 = true;
				enable = false;
				ready = true;
			}
		}
		
		template<int x>
		void Zone_1_t(){
			Ultrasonic* ultrasonic = zone_1.getByPosition(x);
			if(ultrasonic == nullptr){
				return;
			}
			if(time == 0){
				ultrasonic->startTrigger();
			}
			if(time == UltraLimit){
				ultrasonic->stopTrigger();
			}
			if(time >= readLimit){
				singleZone = ultrasonic->read();
				time = 0;
				readySingleZone = true;
				enable = false;
				ready = true;
			}
		}
		
		virtual void Zone_2(){
			if(time == 0){
				for(int x = 0; x < zone_2.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_2.getByPosition(x);
					ultrasonic->startTrigger();
				}
			}
			if(time == UltraLimit){
				for(int x = 0; x < zone_2.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_2.getByPosition(x);
					ultrasonic->stopTrigger();
				}
			}
			if(time >= readLimit){
				Average<float> average;
				for(int x = 0; x < zone_2.getPosition(); x++){
					Ultrasonic* ultrasonic = zone_2.getByPosition(x);
					float r = ultrasonic->read();
					if(r == -1.0f){
						continue;
					}
					average.addLValue(r);
				}
				time = 0;
				right_size = average.getAverage();
				readyZone_0 = true;
				enable = false;
				ready = true;
			}
		}
		
		template<int x>
		void Zone_2_t(){
			Ultrasonic* ultrasonic = zone_2.getByPosition(x);
			if(ultrasonic == nullptr){
				return;
			}
			if(time == 0){
				ultrasonic->startTrigger();
			}
			if(time == UltraLimit){
				ultrasonic->stopTrigger();
			}
			if(time >= readLimit){
				singleZone = ultrasonic->read();
				time = 0;
				readySingleZone = true;
				enable = false;
				ready = true;
			}
		}
		
		virtual void Stop(){
			enable = false;
			left_size = 0.0f;
			right_size = 0.0f;
			height = 0.0f;
			ready = false;
		}
		
		virtual void execute(Message* message){
			String mns = message->text();
			if(mns == "stop"){
				enable = true;
				method = &UltrasonicState::Stop;
			}
			if(mns == "full"){
				enable = true;
				method = &UltrasonicState::FullRead;
			}
			if(mns == "zone 0"){
				enable = true;
				method = &UltrasonicState::Zone_0;
			}
			if(mns == "zone 0 0"){
				enable = true;
				method = &UltrasonicState::Zone_0_t<0>;
			}
			if(mns == "zone 0 1"){
				enable = true;
				method = &UltrasonicState::Zone_0_t<1>;
			}
			if(mns == "zone 0 2"){
				enable = true;
				method = &UltrasonicState::Zone_0_t<2>;
			}
			if(mns == "zone 1"){
				enable = true;
				method = &UltrasonicState::Zone_1;
			}
			if(mns == "zone 1 0"){
				enable = true;
				method = &UltrasonicState::Zone_1_t<0>;
			}
			if(mns == "zone 1 1"){
				enable = true;
				method = &UltrasonicState::Zone_1_t<1>;
			}
			if(mns == "zone 1 2"){
				enable = true;
				method = &UltrasonicState::Zone_1_t<2>;
			}
			if(mns == "zone 2"){
				enable = true;
				method = &UltrasonicState::Zone_2;
			}
			if(mns == "zone 2 0"){
				enable = true;
				method = &UltrasonicState::Zone_2_t<0>;
			}
			if(mns == "zone 2 1"){
				enable = true;
				method = &UltrasonicState::Zone_2_t<1>;
			}
			if(mns == "zone 2 2"){
				enable = true;
				method = &UltrasonicState::Zone_2_t<2>;
			}
		}
		
	protected:
		volatile bool enable = false;
		PrimitiveList<Ultrasonic> zone_0;
		PrimitiveList<Ultrasonic> zone_1;
		PrimitiveList<Ultrasonic> zone_2;
		volatile float left_size = 0;
		volatile float right_size = 0;
		volatile float height = 0;
		volatile float singleZone = 0;
		volatile bool ready = false;
		volatile bool readySingleZone = false;
		volatile bool readyZone_0 = false;
		volatile bool readyZone_1 = false;
		volatile bool readyZone_2 = false;
		volatile bool readyFull = false;
		
		PlayMethod method = &UltrasonicState::Stop;
		
		long time = 0;
		long UltraLimit = 2;
		long readLimit = 160;
};

void initializeUltrasonicStateAnnotations(){
	
}

}

#endif 
