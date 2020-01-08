
#include "Funtion.h"
#include "CuadraticFuntion.h"
#include "MemoryFree.h"

Funtion<float>* fx;

int deletememory;
int startmemory;
int instancememory;

void setup() {
  Serial.begin(9600);
  startmemory = freeMemory();
  fx = new CuadraticFuntion<float>();
  instancememory = freeMemory();
  
  fx->set("a",1);
  fx->set("b",0);
  fx->set("c",0);
  
  Serial.println(fx->f(2));
  
  delete fx;
  deletememory = freeMemory();
  
  Serial.print("startmemory ");Serial.println(startmemory);
  Serial.print("instancememory ");Serial.println(instancememory);
  Serial.print("instance ");Serial.println(startmemory-instancememory);
  Serial.print("delete ");Serial.println(startmemory-deletememory);
}

void loop() {

}
