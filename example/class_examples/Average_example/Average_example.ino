
#include "Average.h"
#include "Vector3f.h"
#include "MemoryFree.h"

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println(freeMemory());
  Vector3f *size = new Vector3f();

  //The average class can have 0, 1 or 2 parameters
  //the first parameter is for the variable you are going to hold the average of the sums
  //the second parameter is a bool, true to delete the first paramete when the instance of Average is deleted, if you dont specify that parameter, the code will but true
  //Average<Vector3f> average(size);
  {
  Average<Vector3f> average(size, true);
  average.reset();
  
  average.addRValue(Vector3f(1,1,1));
  average.addRValue(Vector3f(1,1,1));
  average.addRValue(Vector3f(1,1,1));
  
  Serial.println(average.getAverage().toString());
  average.reset();
  
  average.addRValue(Vector3f(10,10,0));
  average.addRValue(Vector3f(80,80,0));
  average.addRValue(Vector3f(10,10,0));
  
  Serial.println(average.getAverage().toString());
  }
  Serial.println(freeMemory());
}
