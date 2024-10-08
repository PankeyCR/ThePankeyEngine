
#include "higgs.hpp"

#include "ByteArray.hpp"
//Set individual bits, checking if bits are true and if array contains byte, ByteArray:

using namespace higgs;

void setup() {
  Serial.begin(9600);
}

void loop() {
  higgs_Debuging(higgs_Log_StartLoop, "loop");
  
  ByteArray array;
  array += 0b00000000;//adds a single byte

  //cell: position of the array
  //bit: bit of the byte
  //value: 1 or 0, true or false
  //setBit(cell,bit,value)
  array.setBit(0,0,true);
  array.setBit(0,1,false);
  array.setBit(0,2,true);
  array.setBit(0,3,false);
  array.setBit(0,4,true);
  array.setBit(0,5,false);
  array.setBit(0,6,true);
  array.setBit(0,7,false);
  Serial.println(array);
  Serial.println();

  //cell: position of the array
  //bit: bit of the byte
  //getBit(cell,bit)
  if(array.getBit(0,6)){
    Serial.println("this bit is on: cell:0, bit:6");
  }
  if(array.contain(0b01010101)){
    Serial.println("contain this byte: 0b01010101");
    Serial.print("in position: ");Serial.println(array.getFirstIndex(0b01010101));
  }
  
  higgs_Debuging(higgs_Log_EndLoop, "loop");
}