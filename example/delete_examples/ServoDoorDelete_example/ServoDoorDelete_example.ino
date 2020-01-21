
#include "MonkeyTime.h"
#include "TimeScale.h"
#include "ServoDoor.h"
#include "SimpleEvent.h"
#include "DelaySensor.h"
#include "MemoryFree.h"

SimpleEvent<String>* DoorActivations;

MonkeyTime* timer;

ServoDoor* door;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  
  DoorActivations = new SimpleEvent<String>();
  DoorActivations->add(&doorEvent);

  timer = new MonkeyTime();
  
  door = new ServoDoor();
  door  ->monkeytime(timer)
        ->delay(1.5f)
        ->attach(7)
        ->closeAngle(0)
        ->openAngle(180)
        ->open()
         //->close()
        ;
  instancememory = freeMemory();
  timer->start();
  timer->setScale(TimeScale::Second);
  delete DoorActivations;
  delete timer;
  delete door;
  
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {
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
