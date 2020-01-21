
#include "MonkeyTime.h"
#include "TimeScale.h"
#include "DelaySensor.h"
#include "LightSensor.h"
#include "SimpleEvent.h"

SimpleEvent<String>* LightActivations;

MonkeyTime* timer;

LightSensor* light;

void setup() {
  Serial.begin(9600);
  
  timer = new MonkeyTime();
  
  LightActivations = new SimpleEvent<String>();
  LightActivations->add(&lightEvent);
  
  light = new LightSensor();
  light ->monkeytime(timer)
        ->delay(2.0f)
        ->attach(A0)
        ->limit(120);
        
  timer->start();
  timer->setScale(TimeScale::Second);
}

void loop() {
  timer->computeScaleTime(0.1f);
  light->update();
  if(timer->getScaleTPC() > 0){
    Serial.print("timer tpc ");Serial.println(timer->getScaleTPC());
  }
  if(light->isOpen()){
    LightActivations->event("open");
  }
  if(light->isClose()){
    LightActivations->event("close");
  }
}

void lightEvent(String event) {
  Serial.print("lightEvent ");Serial.println(event);
  Serial.print("light->getValue() ");Serial.println(light->getValue());
}
