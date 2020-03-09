
#define Log 
#define LogSerial 

#include "RealRandom.h"
#include "Logger.h"

RealRandom r;
  
void setup() {
  Serial.begin(9600);
  LogSerial(&Serial);
  r.setMax(10);
  r.setMin(0);
  r.setSeed(9521);
  Serial.println(r.getRandom());
}

void loop() {
  Serial.print("random ");Serial.println(r.getRandom());
  
}