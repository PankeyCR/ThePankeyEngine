
#include "Vector2f.hpp"

using namespace ame;

Vector2f line;

void setup() {
  Serial.begin(9600);  
}

void loop() {
  Vector2f original = line.set(0,1);
  Vector2f rot90 = line.rotateLocal(90);
  Vector2f rot180 = line.rotateLocal(90);
  line.rotateLocal(180);
  
  Serial.print("Vector original position :  ");Serial.println(original.toNote());
  Serial.print("add 90 rotation ");Serial.println(rot90.toNote());
  Serial.print("add 90 rotation ");Serial.println(rot180.toNote());
  Serial.print("add 180 rotation ");Serial.println(line.toNote());
}
