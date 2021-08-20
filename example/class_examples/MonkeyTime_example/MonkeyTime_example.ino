
#include "Now.h"
#include "MonkeyTime.h"
#include "TimeRecorder.h"

using namespace ame;

MonkeyTime timer;
TimeRecorder recorder;

void setup() {
  Serial.begin(9600);
  timer.start();
}

void loop() {
  timer.computeTime();
  recorder+=timer.getTPC();
  if(timer.isNow(TimeCheck::InBetween,100.0f,1.0f) ){
    Serial.println("yeah baby");
  }
  if(recorder.isNow(TimeCheck::InBetween,300.0f,1.0f)){
    Serial.println("no baby");
  }
  //Serial.println(timer.getTime());
  //Serial.println(recorder.getRecord());
  //Serial.println(timer.getTPC());
}
