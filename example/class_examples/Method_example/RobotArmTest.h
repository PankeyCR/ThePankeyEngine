
#ifndef RobotArmTest_h
#define RobotArmTest_h

#include "Stream.h"
#include "SimpleServo.h"
#include "cppObject.h"
#include "DefaultMethod.h"

class RobotArmTest : public cppObject{
public:
RobotArmTest(Stream *port,int Xpin,int Ypin,int Zpin){
	serial = port;

  MethodType<RobotArmTest,bool,float>::add(new DefaultMethod<RobotArmTest,bool,float>("X",&RobotArmTest::MoveX));
  MethodType<RobotArmTest,bool,float>::add(new DefaultMethod<RobotArmTest,bool,float>("Y",&RobotArmTest::MoveY));
  MethodType<RobotArmTest,bool,float>::add(new DefaultMethod<RobotArmTest,bool,float>("Z",&RobotArmTest::MoveZ));
  MethodType<RobotArmTest,String>::add(new DefaultMethod<RobotArmTest,String>("stop",&RobotArmTest::Stop));

	servos = new SimpleServo();
	servos->setup(3);
	servos->attach(0,Xpin);        
	servos->attach(1,Ypin);
	servos->attach(2,Zpin);
}

bool MoveX(float move){
	servos->MoveServo(0,move);
	serial->println(move);
	return true;
}

bool MoveY(float move){
	servos->MoveServo(1,move);   
	serial->println(move); 
	return false;  
}

bool MoveZ(float move){
  servos->MoveServo(2,move);   
  serial->println(move);
  return true;
}

String Stop(){
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