
#include "Annotation.hpp"
#include "cppObjectClass.hpp"
#include "cppObject.hpp"
#include "Method.hpp"
#include "Class.hpp"
#include "MemoryRam.hpp"

using namespace ame;

class ExampleAnnotation : public Annotation{
  public:
  ExampleAnnotation(){}
  cppObjectClass* getClass(){
    return Class<ExampleAnnotation>::classType;
  }
};

class ExampleMethod : public Method{
  public:
  ExampleMethod(){}
  cppObjectClass* getClass(){
    return Class<ExampleMethod>::classType;
  }
};

class ExampleMethodAnnotation : public Annotation{
  public:
  ExampleMethodAnnotation(){}
  cppObjectClass* getClass(){
    return Class<ExampleMethodAnnotation>::classType;
  }
};

class Example : public cppObject{
  public:
  Example(){}
  bool instanceof(cppObjectClass* cls){
    return cls == Class<Example>::classType || cppObject::instanceof(cls);
  }
  cppObjectClass* getClass(){
    return Class<Example>::classType;
  }
};
 
void setup() {
  Serial.begin(9600);

  ClassAnnotationList<Example>::add(new ExampleAnnotation());

  ClassName<Example>::className = "Example";

  ClassMethodList<Example>::add(new ExampleMethod());
  
  ClassAnnotationList<ExampleMethod>::add(new ExampleMethodAnnotation());
}

void loop() {
  Serial.println("////////////start");
  Serial.println(getRamSize());
  Example example;

  Annotation* annotation = example.getClass()->getAnnotation(Class<ExampleAnnotation>::classType);
  if(annotation != nullptr){
    ExampleAnnotation* e_annotation = (ExampleAnnotation*)annotation;
    //Do something with the annotation
    Serial.println("Do something with the annotation");
  }
    
  Method* method = example.getClass()->getMethod(Class<ExampleMethod>::classType);
  if(method != nullptr){
    ExampleMethod* e_method = (ExampleMethod*)method;
    //Do something with the method
    Serial.println("Do something with the method");
    
    Annotation* method_annotation = method->getClass()->getAnnotation(Class<ExampleMethodAnnotation>::classType);
    if(method_annotation != nullptr){
      ExampleMethodAnnotation* a_method = (ExampleMethodAnnotation*)method_annotation;
      //Do something with the method annotation
      Serial.println("Do something with the method annotation");
    }
  }
  Serial.println("////////////end");
  Serial.println(getRamSize());
}
