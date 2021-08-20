
#include "TypeErasedInvoke.h"

class Example_1{
  public:
  Example_1(){}
  void invoke(String n, int b){Serial.println(b);}
};
class Example_2{
  public:
  Example_2(){}
  void invoke(String n, int b){Serial.println(b);}
};
using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  TypeErasedInvoke<int> t = Example_1();
  t.invoke("",5);
  t = Example_2();
  t.invoke("",10);
}
