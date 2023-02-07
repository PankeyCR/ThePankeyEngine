
#include "MonkeyTime.hpp"
#include "TimeCheck.hpp"

using namespace ame;

MonkeyTime timer;


void setup() {
  Serial.begin(9600);
  
  timer.start();
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  timer.computeTime();
  
  //InBetween, Equal, LessThan, LessEqualThan,GreaterEqualThan,GreaterThan
  if(timer.isNow(TimeCheck::InBetween, 10, 0.2f)){
    runEvent();
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}


void runEvent(){
  
}

