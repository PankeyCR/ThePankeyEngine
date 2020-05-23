
#include "Function.h"
#include "CuadraticFunction.h"

Function<float,float,float,float>* fxyz;
Function<float,float>* fx;

void setup() {
  Serial.begin(9600);
  fx = new CuadraticFunction<float>();
  fx->set("a",1);
  fx->set("b",0);
  fx->set("c",0);
  Serial.println(fx->f(2));
  
  fxyz = new CuadraticFunction<float,float,float>();
  Serial.println(fxyz->f(2,2,2));
}

void loop() {

}
