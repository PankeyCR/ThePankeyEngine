
#include "Array.hpp"
#include "System.hpp"
#include "Cast.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  Array<int> array = {1,2,3,4,5};
  Array<int> array_2 = move(array);

  for(int i : array_2){
    System::console.println(i);
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}