
#ifndef RobotArmTest_h
#define RobotArmTest_h

#include "Annotation.h"
#include "Stream.h"
#include "List.h"
#include "Map.h"
#include "KVMap.h"
#include "ArrayList.h"
#include "SimpleServo.h"

class RobotArmTest : public Annotation<String,void (RobotArmTest::*)(float)>{
	public:
		RobotArmTest(Stream *port,int Xpin,int Ypin,int Zpin){
			serial = port;      
      
			listA = new ArrayList<String,4>();
			mapA = new KVMap<String, void (RobotArmTest::*)(float),3>();

			listA->add("arm");
			listA->add("X Axis");
			listA->add("Y Axis");
			listA->add("Z Axis");

			mapA->add("X",&RobotArmTest::MoveX);
			mapA->add("Y",&RobotArmTest::MoveY);
			mapA->add("Z",&RobotArmTest::MoveZ);

			servos = new SimpleServo();
			servos->setup(3);
			servos->attach(0,Xpin);        
			servos->attach(1,Ypin);
			servos->attach(2,Zpin);
		}
   
    void MoveX(float move){
      servos->MoveServo(0,move);
      serial->println(move);
    }
    
    void MoveY(float move){
      servos->MoveServo(1,move);   
      serial->println(move);   
    }
    
    void MoveZ(float move){
      servos->MoveServo(2,move);   
      serial->println(move);   
    }
   
   ~RobotArmTest(){
      delete listA;
      delete mapA;
      delete servos;
   }
    List<String>* getClassAnnotations(){
      return listA;
    }
    Map<String, void (RobotArmTest::*)(float)>* getMethodAnnotations(){
      return mapA;
    }
		
	private:
		Stream *serial=NULL;
		List<String> *listA;
		Map<String, void (RobotArmTest::*)(float)> *mapA;
		SimpleServo *servos;
};

#endif 
