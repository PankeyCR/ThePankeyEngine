
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

using namespace ame;

void setup() {
  Serial.begin(9600);
  Class<BaseClass> clase_1 = Class<BaseClass>::getClass<Example>();
  Class<BaseClass> clase_2 = Class<BaseClass>::getClass<BaseObject>();
  
  clase_1.setName<Example>("Example");
  clase_2.setName<BaseObject>("BaseObject");
}

void loop() {
  Class<BaseClass> clase = Class<BaseClass>::getClass<Example>();
  
  long type = clase.getType();
  char* name = clase.getName();
  
  if(!clase.isNull()) Serial.println("Not null class");
  if(name != nullptr) Serial.println(name);
  Serial.println(type);
}




//