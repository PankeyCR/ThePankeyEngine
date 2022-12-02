
#include "Reflection.hpp"
#include "System.hpp"

using namespace ame;

void runEvent(){System::console.println("runEvent");}
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  Reflection reflection;
  reflection.addClass("Example");
  reflection.addClassMethod("Example", "runEvent", runEvent);

  cppObject* obj = reflection.newInstance("Example");

  reflection.invoke(obj, "runEvent");
}





//