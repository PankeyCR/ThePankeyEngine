
#include "MonkeyTime.h"
#include "TimeScale.h"
#include "DelaySensor.h"
#include "LightSensor.h"
#include "SimpleEvent.h"
#include "MemoryFree.h"

SimpleEvent<String>* LightActivations;

MonkeyTime* timer;

LightSensor* light;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  
  timer = new MonkeyTime();
  
  LightActivations = new SimpleEvent<String>();
  LightActivations->add(&lightEvent);
  
  light = new LightSensor();
  light ->monkeytime(timer)
        ->delay(2.0f)
        ->attach(A0)
        ->limit(120);
  instancememory = freeMemory();
        
  timer->start();
  timer->setScale(TimeScale::Second);

  delete timer;
  delete LightActivations;
  delete light;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {
}

void lightEvent(String event) {
  Serial.print("lightEvent ");Serial.println(event);
  Serial.print("light->getValue() ");Serial.println(light->getValue());
}
