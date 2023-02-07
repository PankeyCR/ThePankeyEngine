
#include "TimeRecorder.hpp"
#include "TimeCheck.hpp"

using namespace ame;

TimeRecorder recorder;


void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");

  recorder.record(0.1f);
  
  //InBetween, Equal, LessThan, LessEqualThan,GreaterEqualThan,GreaterThan
  if(recorder.isNow(TimeCheck::InBetween, 10, 0.2f)){
    runEvent();
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}


void runEvent(){
  
}


