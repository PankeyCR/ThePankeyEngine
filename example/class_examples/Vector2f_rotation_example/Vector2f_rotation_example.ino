
#include "Vector2f.h"

Vector2f line;

void setup() {
  Serial.begin(9600);  
  Vector2f original = line.set(0,1);
  Vector2f rot90 = line.rotateLocal(90);
  Vector2f rot180 = line.rotateLocal(90);
  line.rotateLocal(180);
  
  Serial.print("Vector original position :  ");Serial.println(original.toString());
  Serial.print("add 90 rotation ");Serial.println(rot90.toString());
  Serial.print("add 90 rotation ");Serial.println(rot180.toString());
  Serial.print("add 180 rotation ");Serial.println(line.toString());

}

void loop() {


}
