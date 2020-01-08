
#ifndef RobotArmTest_h
#define RobotArmTest_h

#include "Anotation.h"
#include "Stream.h"
#include "List.h"
#include "Map.h"
#include "KVMap.h"
#include "ArrayList.h"
#include "SimpleServo.h"

class RobotArmTest : public Anotation<void (RobotArmTest::*)(float),String>{
	public:
		RobotArmTest(Stream *port,int Xpin,int Ypin,int Zpin){
			serial = port;      
      
      listA = new ArrayList<String,4>();
      mapA = new KVMap<void (RobotArmTest::*)(float),String,3>();
      
      listA->add("arm");
      listA->add("X Axis");
      listA->add("Y Axis");
      listA->add("Z Axis");
      
      mapA->add(&RobotArmTest::MoveX,"X");
      mapA->add(&RobotArmTest::MoveY,"Y");
      mapA->add(&RobotArmTest::MoveZ,"Z");
      
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
    List<String>* getClassAnotations(){
      return listA;
    }
    Map<void (RobotArmTest::*)(float),String>* getMethodAnotations(){
      return mapA;
    }
		
	private:
		Stream *serial=NULL;
    List<String> *listA;
    Map<void (RobotArmTest::*)(float),String> *mapA;
    SimpleServo *servos;
};

#endif 
