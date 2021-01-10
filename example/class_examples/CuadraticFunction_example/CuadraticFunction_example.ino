
#include "CuadraticFunction.h"
#include "MemoryFree.h"

CuadraticFunction<float,float,float>* fxyz;
CuadraticFunction<float>* fx;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
  Serial.println(freeMemory());
  fx = new CuadraticFunction<float>();
  fx->setVariable(0, 1);
  fx->setVariable(1, 0);
  fx->setVariable(2, 0);
  Serial.println(fx->f(2));
  
  fxyz = new CuadraticFunction<float,float,float>();
  Serial.println(fxyz->f(2,2,2));
  delete fx;
  delete fxyz;
  Serial.println("end");
  Serial.println(freeMemory());
}