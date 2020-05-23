
#include "MonkeyTime.h"
#include "MetricScale.h"
#include "MetricPrefix.h"
#include "DelaySensor.h"
#include "LightSensor.h"
#include "SimpleEvent.h"

SimpleEvent<String>* LightActivations;

MonkeyTime* timer;

MetricScale* scale;

LightSensor* light;

void setup() {
  Serial.begin(9600);
  
  timer = new MonkeyTime();
  
  scale = new MetricScale();
  
  LightActivations = new SimpleEvent<String>();
  LightActivations->add(&lightEvent);
  
  light = new LightSensor();
  light ->monkeytime(timer)
        ->delay(2.0f)
        ->attach(A0)
        ->limit(120);
        
  timer->start();
  scale->setScaleTransform(MetricPrefix::micro, MetricPrefix::none);
}

void loop() {
  timer->computeTime(scale->getValue(0.1f));
  light->update();
  if(timer->getTPC() > 0){
    Serial.print("timer tpc ");Serial.println(timer->getTPC());
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
