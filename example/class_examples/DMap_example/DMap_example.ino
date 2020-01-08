
#include "D5Map.h"
#include "D4Map.h"
#include "D3Map.h"
#include "D2Map.h"


void setup() {
  Serial.begin(9600);
  
  D2Map<float,2,2> map2d;
  //  vector(first parameter, econd parameter)
  //  first parameter = dimention
  //  second parameter = position inside dimention
  map2d.vector(0,0);
  map2d.vector(1,0);
  //  add value to current position
  map2d.add(2);
  map2d.vector(0,0);
  map2d.vector(1,1);
  map2d.add(22);
  
  map2d.vector(0,0);
  map2d.vector(1,1);
  //  get value to current position
  Serial.println(map2d.get());
  map2d.vector(0,0);
  map2d.vector(1,0);
  Serial.println(map2d.get());
  
  D3Map<float,2,2,2> map3d;
  map3d.vector(0,0);
  map3d.vector(1,0);
  map3d.vector(2,0);
  map3d.add(3);
  map3d.vector(0,0);
  map3d.vector(1,0);
  map3d.vector(2,1);
  map3d.add(333);
  
  map3d.vector(0,0);
  map3d.vector(1,0);
  map3d.vector(2,1);
  Serial.println(map3d.get());
  map3d.vector(0,0);
  map3d.vector(1,0);
  map3d.vector(2,0);
  Serial.println(map3d.get());
  
  D4Map<float,2,2,2,2> map4d;
  map4d.vector(0,0);
  map4d.vector(1,0);
  map4d.vector(2,0);
  map4d.vector(3,0);
  map4d.add(4);
  map4d.vector(0,0);
  map4d.vector(1,0);
  map4d.vector(2,0);
  map4d.vector(3,1);
  map4d.add(4444);
  
  map4d.vector(0,0);
  map4d.vector(1,0);
  map4d.vector(2,0);
  map4d.vector(3,1);
  Serial.println(map4d.get());
  map4d.vector(0,0);
  map4d.vector(1,0);
  map4d.vector(2,0);
  map4d.vector(3,0);
  Serial.println(map4d.get());
  
  D5Map<float,2,2,2,2,2> map5d;
  map5d.vector(0,0);
  map5d.vector(1,0);
  map5d.vector(2,0);
  map5d.vector(3,0);
  map5d.vector(4,0);
  map5d.add(5);
  map5d.vector(0,0);
  map5d.vector(1,0);
  map5d.vector(2,0);
  map5d.vector(3,0);
  map5d.vector(4,1);
  map5d.add(55555);
  
  map5d.vector(0,0);
  map5d.vector(1,0);
  map5d.vector(2,0);
  map5d.vector(3,0);
  map5d.vector(4,1);
  Serial.println(map5d.get());
  map5d.vector(0,0);
  map5d.vector(1,0);
  map5d.vector(2,0);
  map5d.vector(3,0);
  map5d.vector(4,0);
  Serial.println(map5d.get());
}

void loop() {
}
