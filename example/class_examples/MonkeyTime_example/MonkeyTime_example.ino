
#include "Now.h"
#include "MonkeyTime.h"
#include "TimeRecorder.h"

MonkeyTime timer;
TimeRecorder recorder;

void setup() {
  Serial.begin(9600);
  timer.start();
  timer.setScale(TimeScale::CentiSecond);
}

void loop() {
  timer.computeTime();
  recorder+=timer.getScaleTPC();
  if(timer.isNow(TimeCheck::InBetween,100.0f,1.0f) ){
    Serial.println("yeah baby");
  }
  if(recorder.isNow(TimeCheck::InBetween,300.0f,1.0f)){
    Serial.println("no baby");
  }
  //Serial.println(timer.getScaleTime());
  //Serial.println(recorder.getRecord());
  //Serial.println(timer.getScaleTPC());
}
