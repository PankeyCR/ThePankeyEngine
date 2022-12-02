
#include "Reflection.hpp"
#include "Note.hpp"
#include "System.hpp"

using namespace ame;

Note Function(){
  return "Function";
}

Note Function_2(Note a_name){
  return a_name;
}
 
void setup() {
  Serial.begin(9600);

  Reflection::addMethod("Function", Function);
  Reflection::addMethod("Function 2", Function_2);
}

void loop() {
  Note result = Reflection::invokeMethod<Note>("Function");
  Note result_2 = Reflection::invokeMethod<Note,Note>("Function 2", Note("f2 invoke"));
  
  System::console.println(result);
  System::console.println(result_2);
}









//
