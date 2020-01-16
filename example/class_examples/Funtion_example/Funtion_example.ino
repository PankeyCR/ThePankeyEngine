
#include "Funtion.h"
#include "CuadraticFuntion.h"

Funtion<float,float,float,float>* fxyz;
Funtion<float,float>* fx;

void setup() {
  Serial.begin(9600);
  fx = new CuadraticFuntion<float>();
  fx->set("a",1);
  fx->set("b",0);
  fx->set("c",0);
  Serial.println(fx->f(2));
  
  fxyz = new CuadraticFuntion<float,float,float>();
  Serial.println(fxyz->f(2,2,2));
}

void loop() {

}
