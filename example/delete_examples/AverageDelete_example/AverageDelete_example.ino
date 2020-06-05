
#include "Average.h"
#include "Vector3f.h"
#include "Vector2f.h"
#include "Quaternion.h"
#include "MemoryFree.h"

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  {
  Vector3f *size = new Vector3f();
  Average<Vector3f> average(size);
  average.reset();
  average.add(Vector3f(1,1,1));
  average.add(Vector3f(1,1,1));
  average.add(Vector3f(1,1,1));
  Serial.println(average.getValue().toString());
  Serial.println(average.getAverage().toString());
  instancememory = freeMemory();
  }
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
  {
  Vector2f *size = new Vector2f();
  Average<Vector2f> average(size);
  average.reset();
  average.add(Vector2f(1,1));
  average.add(Vector2f(1,1));
  average.add(Vector2f(1,1));
  Serial.println(average.getValue().toString());
  Serial.println(average.getAverage().toString());
  instancememory = freeMemory();
  }
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
  {
  Quaternion *size = new Quaternion();
  Average<Quaternion> average(size);
  average.reset();
  average.add(Quaternion(1,1,1,1));
  average.add(Quaternion(1,1,1,1));
  average.add(Quaternion(1,1,1,1));
  Serial.println(average.getValue().toString());
  Serial.println(average.getAverage().toString());
  instancememory = freeMemory();
  }
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
  {
  Average<float> average;
  average.reset();
  average.add(5.0f);
  average.add(5.0f);
  average.add(5.0f);
  Serial.println(average.getValue());
  Serial.println(average.getAverage());
  instancememory = freeMemory();
  }
  deletememory = freeMemory();
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
  
}

void loop() {

}
