
#ifndef RobotArmTest_hpp
#define RobotArmTest_hpp

#include "Stream.h"
#include "cppObject.hpp"
#include "ClassMethod.hpp"

using namespace ame;

class RobotArmTest : public cppObject{
public:
RobotArmTest(Stream *port){
  serial = port;

  ClassMethod<RobotArmTest>::add("X");
  ClassMethod<RobotArmTest>::add("stop");
  
  MethodMap<RobotArmTest,bool,float>* map = Invoker<RobotArmTest,bool,float>::getMap();
  map->add("X",&RobotArmTest::MoveX);
  MethodMap<RobotArmTest,String>* mapS = Invoker<RobotArmTest,String>::getMap();
  mapS->add("stop",&RobotArmTest::Stop);
}

bool MoveX(float move){
  serial->println("MoveX");
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
}

private:
Stream *serial = nullptr;
};

#endif 