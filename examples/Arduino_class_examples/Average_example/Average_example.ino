
#include "higgs.hpp"

#include "Average.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("//////////////////////start");

  Average<float> average = 0;
  
  average.add(5);
  average.add(5);
  average.add(5);

  float i_value = average.getValue();
  float i_average = average.getAverage();
  
  Serial.println(i_value);
  Serial.println(i_average);
  
  Serial.println("//////////////////////end");
}