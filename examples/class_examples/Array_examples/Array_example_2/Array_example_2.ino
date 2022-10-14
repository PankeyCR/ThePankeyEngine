
#include "Array.hpp"
#include "System.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Array<int> array;

  array.addLocal(1);
  array.addLocal(2);
  array.addLocal(3);
  array.addLocal(4);
  array.addLocal(5);

  array.set(2, 91);

  for(int i : array){
    System::console.println(i);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}