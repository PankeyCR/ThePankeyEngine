
#define Log 
#define LogSerial 

#include "AbsoluteRandom.h"
#include "Logger.h"

AbsoluteRandom *r;
  
void setup() {
  Serial.begin(9600);
  LogSerial(&Serial);
  //the values of the seeds should be between 0 - 1000, but i prefer between 300 - 900
  r = new AbsoluteRandom(875.85f);
  r->setMax(10);
  r->setMin(0);
  r->setSeed(545.25f);
}

void loop() {
  Serial.print("absolute ");Serial.println(r->getRandom());
  //Serial.print("real     ");Serial.println(r->getSeed());
}