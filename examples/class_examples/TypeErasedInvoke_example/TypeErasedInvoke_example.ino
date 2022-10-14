
#include "TypeErasedInvoke.hpp"
#include "Note.hpp"

using namespace ame;

class Example_1{
  public:
  Example_1(){}
  void invoke(Note n, int b){Serial.println(b);}
};
class Example_2{
  public:
  Example_2(){}
  void invoke(Note n, int b){Serial.println(b);}
};

void setup() {
  Serial.begin(9600);
}

void loop() {
  TypeErasedInvoke<int> t = Example_1();
  t.invoke("",5);
  t = Example_2();
  t.invoke("",10);
}
