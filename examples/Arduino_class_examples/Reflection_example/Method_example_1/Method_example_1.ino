
#include "Reflection.hpp"
#include "Note.hpp"
#include "System.hpp"

using namespace ame;

void Function(){
  System::console.println("Function");
}

void Function_2(Note a_name){
  System::console.println(a_name);
}
 
void setup() {
  Serial.begin(9600);

  Reflection::addMethod("Function", Function);
  Reflection::addMethod("Function 2", Function_2);
}

void loop() {
  Reflection::invokeMethod("Function");
  Reflection::invokeMethod("Function 2", Note("f2 invoke"));
}