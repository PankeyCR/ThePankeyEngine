
#include "Class.hpp"
#include "System.hpp"

using namespace ame;
 
void setup() {
  Serial.begin(9600);
}

void loop() {
  Class<> class_1 = Class<int>::getClass();
  Class<> class_2 = Class<float>::getClass();
  Class<> class_3 = Class<Number>::getClass();
  
  Class<> class_4 = Class<char>::getClass();
  Class<> class_5 = Class<char*>::getClass();
  Class<> class_6 = Class<Note>::getClass();
  
  if(class_1 == class_2 && class_1 == class_3){
    System::console.println("int class, float class, long class and double class are the same because it references the Number class");
  }
 
  if(class_4 == class_5 && class_4 == class_6){
    System::console.println("char class and char* class are the same because it references the Note class");
  }
}