
#include "PointerSize.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("loop start");
  
  Serial.println(sizeof(char));
  Serial.println(sizeof(int));
  Serial.println(sizeof(double));
  Serial.println(sizeof(float));
  
  Serial.println("------------");
  
  Serial.println(sizeOfPointer<char>());
  Serial.println(sizeOfPointer<int>());
  Serial.println(sizeOfPointer<double>());
  Serial.println(sizeOfPointer<float>());
  
  Serial.println("loop end");
}