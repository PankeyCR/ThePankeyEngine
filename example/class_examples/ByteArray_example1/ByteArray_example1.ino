
#include "ByteArray.h"
//Adding and Printing ByteArray:
//one easy way to add bytes to the array is by the += operator, you can use const bytes or ints
//when you print, it will show the value of each byte on a secuence, that way it can be transfer as
//as fast as posible, but when its displayed it doesnt shows the first ceros of the byte

void setup() {
  Serial.begin(9600);
  ByteArray array;
  array += 5;
  array += 0b00000101;//this is also a 5
  Serial.println("array");
  Serial.println(array);//this is better for sending data
  Serial.println();
  Serial.println("toString");
  Serial.println(array.toString());//this is better for visualizing data
  Serial.println();
  array.toggleAll();//changes all the 1 to 0 and 0 to 1 on the array
  Serial.println("array");
  Serial.println(array);
  Serial.println();
  Serial.println("toString");
  Serial.println(array.toString());
}

void loop() {
}
