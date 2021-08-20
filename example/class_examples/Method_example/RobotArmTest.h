
#ifndef RobotArmTest_h
#define RobotArmTest_h

#include "Stream.h"
#include "SimpleServo.h"
#include "cppObject.h"

using namespace ame;

class RobotArmTest : public cppObject{
public:
RobotArmTest(Stream *port,int Xpin,int Ypin,int Zpin){
	serial = port;

  ClassMethod<RobotArmTest>::add("X");
  ClassMethod<RobotArmTest>::add("Y");
  ClassMethod<RobotArmTest>::add("Z");
  ClassMethod<RobotArmTest>::add("stop");
  
  MethodMap<RobotArmTest,bool,float>* map = Invoker<RobotArmTest,bool,float>::getMap();
  map->add("X",&RobotArmTest::MoveX);
  map->add("Y",&RobotArmTest::MoveY);
  map->add("Z",&RobotArmTest::MoveZ);
  MethodMap<RobotArmTest,String>* mapS = Invoker<RobotArmTest,String>::getMap();
  mapS->add("stop",&RobotArmTest::Stop);

	servos = new SimpleServo();
	servos->setup(3);
	servos->attach(0,Xpin);        
	servos->attach(1,Ypin);
	servos->attach(2,Zpin);
}

bool MoveX(float move){
	servos->MoveServo(0,move);
  serial->println("MoveX");
	return true;
}

bool MoveY(float move){
	servos->MoveServo(1,move); 
  serial->println("MoveY");
	return false;  
}

bool MoveZ(float move){
  servos->MoveServo(2,move);
  serial->println("MoveZ");
  return true;
}

String Stop(){
  serial->println("Stop");
  return "stopping";
}

cppObjectClass* getClass(){
  return Class<RobotArmTest>::classType;
}

~RobotArmTest(){
	delete servos;
}

private:
Stream *serial = nullptr;
SimpleServo *servos = nullptr;
};

#endif 