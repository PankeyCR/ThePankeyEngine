
#include "higgs.hpp"

#include "Class.hpp"

class BaseClass{
  public:
  BaseClass(){}
};

class BaseObject{
  public:
  BaseObject(){}
};

class Example : public BaseObject{
  public:
  Example(){}
};

using namespace higgs;

void setup() {
  Serial.begin(9600);
  
  ClassName<Example>::set("Example");
  ClassName<BaseObject>::set("BaseObject");
  
  Class<BaseClass> clase_1 = Class<BaseClass>::getClass<Example>();
  Class<BaseClass> clase_2 = Class<BaseClass>::getClass<BaseObject>();
}

void loop() {
  Class<BaseClass> clase = Class<BaseClass>::getClass<Example>();
  
  long type = clase.getType();
  CharArray name = clase.getName();
  
  if(!clase.isNull()) Serial.println("Not null class");
  Serial.println(name.pointer());
  Serial.println(type);
}




//