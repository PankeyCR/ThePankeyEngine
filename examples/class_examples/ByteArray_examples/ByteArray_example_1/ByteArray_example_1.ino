
#include "ByteArray.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ByteArray array;
  array += 5;
  array += 0b00000101;//this is also a 5
  Serial.println(array);
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}



//