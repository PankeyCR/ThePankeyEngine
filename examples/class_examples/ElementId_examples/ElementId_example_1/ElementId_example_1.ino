
#include "ElementId.hpp"

using namespace ame;

void setup() {
  Serial.begin(9600);
}

void loop() {
  ame_Debuging(ame_Log_StartLoop, "loop");
  
  ElementId parent = "parent";
  ElementId child = parent.child("child");
  Serial.println(parent);
  Serial.println(child);
  if(parent == "parent"){
    Serial.println("parent == parent");
  }
  if(child == "parent.child"){
    Serial.println("parent.child == parent.child");
  }
  ElementId child_2 = child.child("child_2");
  Serial.println(child_2);
  if(child_2 == "parent.child.child_2"){
    Serial.println("parent.child.child_2 == parent.child.child_2");
  }
  Serial.print("child_2 ");Serial.println(child_2.getSize());
  for(int x = 0; x < child_2.getSize(); x++){
    Serial.print("child_2 part ");Serial.println(child_2.getPart(x));
  }

  ame_Debuging(ame_Log_EndLoop, "loop");
}