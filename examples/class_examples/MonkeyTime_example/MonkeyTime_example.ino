
#include "Now.hpp"
#include "MonkeyTime.hpp"
#include "TimeRecorder.hpp"

using namespace ame;

MonkeyTime timer;
TimeRecorder recorder;

void setup() {
  Serial.begin(9600);
  timer.start();
}

void loop() {
  timer.computeTime();
  recorder += (float)timer.getTPC()/1000000l;
  if(timer.isNow(TimeCheck::InBetween,1000000l,1000l) ){
    Serial.println("yeah baby");
  }
  if(recorder.isNow(TimeCheck::InBetween,3.0f,1.0f)){
    Serial.println("no baby");
  }
  if(recorder.isNow(TimeCheck::GreaterThan,5.0f,1.0f)){
    Serial.println("overflow reset");
    timer.restart();
    recorder.resetRecord();
  }
  //Serial.println(timer.getTime());
  //Serial.println(recorder.getRecord());
  //Serial.println(timer.getTPC());
}
