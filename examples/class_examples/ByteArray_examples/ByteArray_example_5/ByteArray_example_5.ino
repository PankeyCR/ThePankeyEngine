
#include "ByteArray.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ByteArray array;
  array += 0b00000000;
  array.setBit(0,0,true);
  array.setBit(0,1,false);
  array.setBit(0,2,true);
  array.setBit(0,3,false);
  array.setBit(0,4,true);
  array.setBit(0,5,false);
  array.setBit(0,6,true);
  array.setBit(0,7,false);

  for(int x = 0; x < 8; x++){
    Serial.println(array.getBit(0,x));
  }
  
  ame_Debuging(ame_Log_EndLoop, "loop");
}