

#ifndef AnimationAppState_h
#define AnimationAppState_h

/*
#include "AppState.h"
#include "Application.h"
#include "KVMap.h"
#include "SerialController.h"
#include "SD.h"
#include "MonkeyTime.h"


class AnimationAppState : public AppState ,TimeElapsed{
	private:	
	 static AnimationAppState *instance;
	 AnimationAppState();
	 KVMap<int,String,50> *animMap;
	 Application *App;
     SerialController *serialController;
     SDClass mySD;
     File myFile;
     MonkeyTime *time;
	 int count =0;
	 boolean runAnim =false;
	 int lengthSentence = 0;
	 
    public:
		static AnimationAppState *getInstance();
		
		virtual void initialize(Application *app){
			App = app;
			serialController = app->getSerialController();
			mySD = app->getScreen()->getSD(); 
			runAnim =false;
			count=0;
			app->getTimer()->add(this); 
		}
		virtual void onDisable(){
			App->getTimer()->remove(this);
		}
		
		boolean makeSDAnimation(String animPath){
			String recive="";
			int respuesta_len = animPath.length() + 1; 
			char respuesta_array[respuesta_len];
			animPath.toCharArray(respuesta_array, respuesta_len);
			myFile = mySD.open(respuesta_array, FILE_WRITE);
			myFile.seek(0);
			if(myFile){
				while (myFile.available()) {
				recive = recive+(char)myFile.read();
				}
			}
			if(recive != ""){
				lengthSentence = serialController->SplitLenght(recive,0,'\n');
				animMap->reset();
				for(int xan=0; xan < lengthSentence+1; xan++){
					String sentence = serialController->Split(recive,xan,'\n');
					animMap->add(xan,sentence);
				}
				return true;
			}
			return false;
		}
		
		
		void start(){
			time->start();
			runAnim =true;
		}
		void stop(){
			runAnim =false;
		}
		
		
		virtual void Play(TimeControl *t){
			if(!runAnim){
				return;
			}
			if(count>lengthSentence){
				count=0;
				return;
			}
			String oracion =animMap->get(count);
			int servoPos_1 = serialController->Split(oracion,0,' ').toInt();
			int servoPos_2 = serialController->Split(oracion,1,' ').toInt();
			int servoPos_3 = serialController->Split(oracion,2,' ').toInt();
			int servoPos_4 = serialController->Split(oracion,3,' ').toInt();
			App->getMultiServo()->MoveServo(0,servoPos_1);
			App->getMultiServo()->MoveServo(1,servoPos_2);
			App->getMultiServo()->MoveServo(2,servoPos_3);
			App->getMultiServo()->MoveServo(3,servoPos_4);
			
			count++;
		}
		
		
		virtual void update(){
			
		}
};
*/
#endif 
