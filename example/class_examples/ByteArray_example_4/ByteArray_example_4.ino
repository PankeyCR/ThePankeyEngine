
#include "ByteArray.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("start");
  ByteArray array = "011";//smaller than 8
  if(array == "011"){
    Serial.println(array);
    Serial.println(array.toString());
  }
  Serial.println();
  ByteArray array_2 = "11101011";//equal than 8
  if(array_2 == "11101011"){
    Serial.println(array_2);
    Serial.println(array_2.toString());
  }
  Serial.println();
  ByteArray array_3 = "10111101011";//bigger than 8
  if(array_3 == "10111101011"){
    Serial.println(array_3);
    Serial.println(array_3.toString());
  }
  Serial.println();
  ByteArray array_4 = "1110101101110101";//bigger than 8 but multiple of 8
  if(array_4 == "1110101101110101"){
    Serial.println(array_4);
    Serial.println(array_4.toString());
  }
  Serial.println();
}
