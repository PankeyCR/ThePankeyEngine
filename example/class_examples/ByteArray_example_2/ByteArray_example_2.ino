
#include "ByteArray.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ByteArray array;
  Serial.println("start");
  array.add(0b00000101);//adds a single byte
  array.add(3, 0b10000010);//adds n bytes, n = 3 
  array.adding(5);//adds n bytes with value 0, n = 5 
  array.adding(5,true);//adds n bytes with value 1, n = 5 
  array.addBits(7);//adds n bits with value 0, n = 7, even with less than 8 bits it adds the whole byte
  array.addBits(7,true);//adds n bits with value 1, n = 7
  Serial.println(array.toString());
  Serial.println("end");
}