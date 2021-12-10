
#include "AbsoluteRandom.hpp"

using namespace ame;

AbsoluteRandom rnd;
  
void setup() {
  Serial.begin(9600);
  
  //the values of the seeds should be between 0 - 1000, but i prefer between 300 - 900
  rnd = 875.85f;
  rnd.setMax(10);
  rnd.setMin(0);
  rnd.setSeed(545.25f);
}

void loop() {
  Serial.print("absolute random: ");Serial.println(rnd.getRandom());
}