
#include "Method.h"
#include "FlyMonkey.h"

//you only need a class with a invoke method, with no need to inhered anything , and you
//can use the Method::invoke<> method
FlyMonkey* fly;

void setup() {
  Serial.begin(9600);
  fly = new FlyMonkey();
}

void loop() {
  bool invoded = Method::invoke<bool>(fly, "println");
  if(invoded){
    Serial.println("invoded");
  }
}
