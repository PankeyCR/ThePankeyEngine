
#include "Vector2f.hpp"

using namespace ame;

Vector2f line(0,1);

void setup() {
  Serial.begin(9600); 
  Vector2f lineX4 = line*5;     //line.mult(5);
  Vector2f lineD2 = line/2;     //line.divide(2);
  Vector2f lineAdd10 = line+10;  //line.add(10);
  
  Serial.print("line :  ");Serial.println(line.toNote());
  Serial.print("lineX4 ");Serial.println(lineX4.toNote());
  Serial.print("lineD2 ");Serial.println(lineD2.toNote());
  Serial.print("lineAdd10 ");Serial.println(lineAdd10.toNote());
  
  Serial.println();
  
  lineX4 = line.mult(5);
  lineD2 = line.divide(2);
  lineAdd10 = line.add(10);
  
  Serial.print("line :  ");Serial.println(line.toNote());
  Serial.print("lineX4 ");Serial.println(lineX4.toNote());
  Serial.print("lineD2 ");Serial.println(lineD2.toNote());
  Serial.print("lineAdd10 ");Serial.println(lineAdd10.toNote());
  
  Serial.println();
  
  lineX4 = line.multLocal(5);    
  Serial.print("line :  ");Serial.println(line.toNote());
  lineD2 = line.divideLocal(2);    
  Serial.print("line :  ");Serial.println(line.toNote());
  lineAdd10 = line.addLocal(10);
  Serial.print("line :  ");Serial.println(line.toNote());
  Serial.print("lineX4 ");Serial.println(lineX4.toNote());
  Serial.print("lineD2 ");Serial.println(lineD2.toNote());
  Serial.print("lineAdd10 ");Serial.println(lineAdd10.toNote());
}
void loop() {
}
