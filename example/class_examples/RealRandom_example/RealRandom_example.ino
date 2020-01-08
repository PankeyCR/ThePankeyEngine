
#include "RealRandom.h"

RealRandom r;
  
void setup() {
  Serial.begin(9600);
  r.setMax(10);
  r.setMin(0);
  r.setSeed(3521);
  Serial.println(r.getRandom());
}

void loop() {
  Serial.print("random ");Serial.println(r.getRandom());
  
}
