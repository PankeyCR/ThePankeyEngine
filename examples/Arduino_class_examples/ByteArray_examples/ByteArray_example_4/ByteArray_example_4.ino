
#include "higgs.hpp"

#include "ByteArray.hpp"

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  higgs_Debuging(higgs_Log_StartLoop, "loop");
  
  ByteArray array;
  array += 5;
  array += 0b00000101;//this is also a 5
  for(byte f_byte : array){
    Serial.println(f_byte);
  }
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}



//