
#include "ElementId.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  Serial.println("//////////////////////////////////start");
  ElementId parent_1 = "parent";
  ElementId child_1 = parent_1.child("child");
  Serial.print("parent_1 ");Serial.println(parent_1);
  Serial.print("child_1 ");Serial.println(child_1);
  if(parent_1.containChild(child_1)){
    Serial.println("parent_1.containChild(child_1)");
  }
  if(child_1.containParent(parent_1)){
    Serial.println("child_1.containParent(parent_1)");
  }
  Serial.println();
  ElementId parent_2 = "monkey";
  ElementId child_2 = parent_1.child("child");
  Serial.print("parent_2 ");Serial.println(parent_2);
  Serial.print("child_2 ");Serial.println(child_2);
  if(parent_2.containChild(child_2)){
    Serial.println("parent_2.containChild(child_2)");
  }
  if(child_2.containParent(parent_2)){
    Serial.println("child_2.containParent(parent_2)");
  }
  Serial.println();
  Serial.println();
  Serial.println("//////////////////////////////////end");
}
