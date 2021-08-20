
//#define LogApp
//#define RealRandomLogApp
//#define AbsoluteRandomLogApp

#include "DefaultLogging.h"
#include "AbsoluteRandom.h"

using namespace ame;

AbsoluteRandom* rnd;
  
void setup() {
  Serial.begin(9600);
  initializeLogger(new DefaultLogging(&Serial, true, false));
  LogClass("AbsoluteRandom");
  
  //the values of the seeds should be between 0 - 1000, but i prefer between 300 - 900
  rnd = new AbsoluteRandom(875.85f);
  rnd->setMax(10);
  rnd->setMin(0);
  rnd->setSeed(545.25f);
}

void loop() {
  Log("AbsoluteRandom", "getRandom", "println","loop");
  Serial.print("absolute ");Serial.println(rnd->getRandom());
  //Serial.print("real     ");Serial.println(rnd->getSeed());
}