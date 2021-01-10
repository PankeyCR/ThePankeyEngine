
#ifndef RobotArmTest_h
#define RobotArmTest_h

#include "Stream.h"
#include "Annotation.h"
#include "SimpleServo.h"

class RobotArmTest{
public:
RobotArmTest(Stream *port,int Xpin,int Ypin,int Zpin){
	serial = port;
	annotation = false;
	annotationString = "";

	annotation.addLValues("X",&RobotArmTest::MoveX);
	annotation.addLValues("Y",&RobotArmTest::MoveY);
	annotation.addLValues("Z",&RobotArmTest::MoveZ);
	annotationString.addLValues("stop",&RobotArmTest::Stop);

	servos = new SimpleServo();
	servos->setup(3);
	servos->attach(0,Xpin);        
	servos->attach(1,Ypin);
	servos->attach(2,Zpin);
}

bool invoke(String method, float move){
 return annotation.invoke(this,method,move);
}

String invoke(String method){
 return annotationString.invoke(this,method);
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

~RobotArmTest(){
	delete servos;
}

private:
Stream *serial = nullptr;
SimpleServo *servos = nullptr;
Annotation<String,bool,RobotArmTest,float> annotation;
Annotation<String,String,RobotArmTest> annotationString;
};

#endif 