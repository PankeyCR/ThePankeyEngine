
#include "MetricScale.h"

void setup() {
  Serial.begin(9600);
  MetricScale scale;
  scale.setScaleTransform(MetricPrefix::micro, MetricPrefix::none);
  
  float v = scale.getValue(3.5f);
  Serial.println(v);
  
  scale.setScaleTransform(MetricPrefix::none, MetricPrefix::micro);
  
  float v2 = scale.getValue(v);
  Serial.println(v2);
}

void loop() {
  // put your main code here, to run repeatedly:

}
