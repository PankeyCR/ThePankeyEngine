
#include "Average.h"
#include "Vector3f.h"

void setup() {
  Serial.begin(9600);
  Vector3f *size = new Vector3f();
  Average<Vector3f> average(size);
  average.reset();
  
  average.add(Vector3f(1,1,1));
  average.add(Vector3f(1,1,1));
  average.add(Vector3f(1,1,1));
  Serial.println(average.getAverage().toString());
  average.reset();
  
  average.add(Vector3f(10,10,0));
  average.add(Vector3f(80,80,0));
  average.add(Vector3f(10,10,0));
  Serial.println(average.getAverage().toString());
}

void loop() {

}
