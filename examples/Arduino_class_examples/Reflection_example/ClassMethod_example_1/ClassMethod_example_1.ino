
#include "Reflection.hpp"
#include "Note.hpp"
#include "System.hpp"

using namespace ame;

class Example{
public:
Example(){}

void Function(){
  System::console.println("Class Function");
}

void Function_2(Note a_name){
  System::console.println(Note("Class ") + a_name);
}

};
 
void setup() {
  Serial.begin(9600);

  Reflection::addClass("Example", Class<Example>::getClass());

  Reflection::addClassMethod("Example", "Function", Example::Function);
  Reflection::addClassMethod("Example", "Function 2", Example::Function_2);
}

void loop() {
  cppObject* obj = Reflection::newInstance("Example");
  
  Reflection::invokeClassMethod(obj, "Function");
  Reflection::invokeClassMethod(obj, "Function 2", Note("f2 invoke"));

  delete obj;
}





//