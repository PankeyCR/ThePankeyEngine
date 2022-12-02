
#include "MonkeyTime.h"
#include "MetricScale.h"
#include "MetricPrefix.h"
#include "ServoDoor.h"
#include "SimpleEvent.h"
#include "DelaySensor.h"

using namespace ame;

SimpleEvent<String>* DoorActivations;

MonkeyTime* timer;

MetricScale* scale;

ServoDoor* door;

void setup() {
  Serial.begin(9600);
  
  DoorActivations = new SimpleEvent<String>();
  DoorActivations->add(&doorEvent);

  timer = new MonkeyTime();

  scale = new MetricScale();
  
  door = new ServoDoor();
  door  ->monkeytime(timer)
        ->delay(1.5f)
        ->attach(7)
        ->closeAngle(0)
        ->openAngle(180)
        ->open()
         //->close()
        ;
  timer->start();
  scale->setScaleTransform(MetricPrefix::micro, MetricPrefix::none);
}

void loop() {
  timer->computeTime(0.1f);
  door->update();
  if(door->isOpen()){
    DoorActivations->event("open");
  }
  if(door->isClose()){
    DoorActivations->event("close");
  }
}

void doorEvent(String event) {
  Serial.print("doorEvent ");Serial.println(event);
  if(event == "close"){
    door->open();
    return;
  }
  if(event == "open"){
    door->close();
    return;
  }
}
