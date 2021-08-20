
#include "CuadraticFunction.h"
#include "MemoryFree.h"

using namespace ame;

CuadraticFunction<float,float,float>* fxyz;
CuadraticFunction<float>* fx;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
  Serial.println(freeMemory());
  fx = new CuadraticFunction<float>();
  fx->set(0, 1);
  fx->set(1, 0);
  fx->set(2, 0);
  Serial.println(fx->f(2));
  
  fxyz = new CuadraticFunction<float,float,float>();
  Serial.println(fxyz->f(2,2,2));
  delete fx;
  delete fxyz;
  Serial.println("end");
  Serial.println(freeMemory());
}